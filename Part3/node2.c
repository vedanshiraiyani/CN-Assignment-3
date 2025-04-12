#include <stdio.h>
#include <string.h>

extern struct rtpkt {
  int sourceid;
  int destid;
  int mincost[4];
};

extern int TRACE;
extern int YES;
extern int NO;
extern float clocktime;

#define MAX_COST 999
#define CURRENT_NODE 2

struct distance_table {
  int path_metrics[4][4];
} dt2;

int link_weights2[4] = {3, 1, 0, 2};
struct rtpkt routing_msgs2[4];
int optimal_routes2[4];

int getMin2(int x, int y) {
    return y < x ? y : x;
}

int findMinimum2(int arr[4]) {
    int m = arr[0];
    for (int k = 1; k < 4; k++) {
        if (arr[k] < m) m = arr[k];
    }
    return m;
}

void printdt2(struct distance_table *dt) {
    printf("\n*** Node %d Routing Table ***\n", CURRENT_NODE);
    printf("Destination | Via Node\n");
    printf("------------+----------------\n");
    printf("     0      | %3d  %3d  %3d\n", 
           dt->path_metrics[0][0], dt->path_metrics[0][1], dt->path_metrics[0][3]);
    printf("     1      | %3d  %3d  %3d\n", 
           dt->path_metrics[1][0], dt->path_metrics[1][1], dt->path_metrics[1][3]);
    printf("     3      | %3d  %3d  %3d\n", 
           dt->path_metrics[3][0], dt->path_metrics[3][1], dt->path_metrics[3][3]);
    printf("*****************************\n");
}

void printmincost2() {
    printf("Node %d optimal path costs: [%d, %d, %d, %d]\n",
           CURRENT_NODE, optimal_routes2[0], optimal_routes2[1],
           optimal_routes2[2], optimal_routes2[3]);
}

void updateMinimumCosts2() {
    for (int dest = 0; dest < 4; dest++) {
        optimal_routes2[dest] = dt2.path_metrics[dest][0];
        for (int via = 1; via < 4; via++) {
            optimal_routes2[dest] = getMin2(optimal_routes2[dest], dt2.path_metrics[dest][via]);
        }
    }
}

void broadcastUpdates2() {
    for (int neighbor = 0; neighbor < 4; neighbor++) {
        routing_msgs2[neighbor].sourceid = CURRENT_NODE;
        routing_msgs2[neighbor].destid = neighbor;
        for (int i = 0; i < 4; i++) {
            routing_msgs2[neighbor].mincost[i] = optimal_routes2[i];
        }
    }

    for (int neighbor = 0; neighbor < 4; neighbor++) {
        if (neighbor != CURRENT_NODE && link_weights2[neighbor] < MAX_COST) {
            tolayer2(routing_msgs2[neighbor]);
            printf("At %.3f: Node %d -> Node %d costs: [%d %d %d %d]\n",
                   clocktime, CURRENT_NODE, neighbor,
                   optimal_routes2[0], optimal_routes2[1],
                   optimal_routes2[2], optimal_routes2[3]);
        }
    }
}

void processAndBroadcast2() {
    int old_costs[4];
    for (int i = 0; i < 4; i++) old_costs[i] = optimal_routes2[i];
    
    updateMinimumCosts2();
    
    int changed = 0;
    for (int j = 0; j < 4; j++) {
        if (old_costs[j] != optimal_routes2[j]) {
            changed = 1;
            break;
        }
    }
    
    if (changed) {
        printf("\nNode %d: Detected path cost changes\n", CURRENT_NODE);
        broadcastUpdates2();
    } else {
        printf("\nNode %d: No path cost updates needed\n", CURRENT_NODE);
    }
}

void rtinit2() {
    printf("\n=== Starting Node %d at time %.3f ===\n", CURRENT_NODE, clocktime);
    
    for (int dest = 0; dest < 4; dest++) {
        for (int via = 0; via < 4; via++) {
            dt2.path_metrics[dest][via] = 
                (dest == via) ? link_weights2[dest] : MAX_COST;
        }
    }
    
    printdt2(&dt2);
    updateMinimumCosts2();
    broadcastUpdates2();
}

void rtupdate2(struct rtpkt *rcvdpkt) {
    int sender = rcvdpkt->sourceid;
    int new_costs[4];
    for (int i = 0; i < 4; i++) new_costs[i] = rcvdpkt->mincost[i];
    
    printf("\n=== Node %d received update at %.3f ===\n", 
           CURRENT_NODE, clocktime);
    printf("From node %d with costs: [%d %d %d %d]\n", 
           sender, new_costs[0], new_costs[1], new_costs[2], new_costs[3]);
    
    int updated = 0;
    for (int dest = 0; dest < 4; dest++) {
        int path_cost = dt2.path_metrics[sender][sender] + new_costs[dest];
        path_cost = path_cost > MAX_COST ? MAX_COST : path_cost;
        
        if (dt2.path_metrics[dest][sender] != path_cost) {
            dt2.path_metrics[dest][sender] = path_cost;
            updated = 1;
        }
    }
    
    printdt2(&dt2);
    if (updated) {
        printf("Routing table modified from node %d update\n", sender);
    }
    processAndBroadcast2();
}

void linkhandler2(int link, int new_cost) {
    printf("\n=== Link Update at %.3f ===\n", clocktime);
    printf("Node %d - Node %d cost changed to %d\n", 
           CURRENT_NODE, link, new_cost);
    
    int old_cost = link_weights2[link];
    link_weights2[link] = new_cost;
    int delta = new_cost - old_cost;
    
    for (int dest = 0; dest < 4; dest++) {
        if (dt2.path_metrics[dest][link] < MAX_COST) {
            dt2.path_metrics[dest][link] += delta;
        }
    }
    
    printdt2(&dt2);
    processAndBroadcast2();
}