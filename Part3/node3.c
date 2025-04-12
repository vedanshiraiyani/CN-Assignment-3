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

#define MAX_DIST 999
#define THIS_NODE 3

struct distance_table {
  int route_matrix[4][4];
} dt3;

int neighbor_weights3[4] = {7, 999, 2, 0};
struct rtpkt outgoing_msgs3[4];
int shortest_paths3[4];

int getMin3(int val1, int val2) {
    return val2 < val1 ? val2 : val1;
}

int findMinimum3(int nums[4]) {
    int lowest = nums[0];
    for (int idx = 1; idx < 4; idx++) {
        if (nums[idx] < lowest) lowest = nums[idx];
    }
    return lowest;
}

void printdt3(struct distance_table *dt) {
    printf("\n**** Node %d Routing Table ****\n", THIS_NODE);
    printf("Destination | Via Nodes\n");
    printf("------------+-----------\n");
    printf("     0      | %3d  %3d\n", dt->route_matrix[0][0], dt->route_matrix[0][2]);
    printf("     1      | %3d  %3d\n", dt->route_matrix[1][0], dt->route_matrix[1][2]);
    printf("     2      | %3d  %3d\n", dt->route_matrix[2][0], dt->route_matrix[2][2]);
    printf("*****************************\n");
}

void printmincost3() {
    printf("Node %d shortest path costs: [%d, %d, %d, %d]\n",
           THIS_NODE, shortest_paths3[0], shortest_paths3[1],
           shortest_paths3[2], shortest_paths3[3]);
}

void updateMinimumCosts3() {
    for (int target = 0; target < 4; target++) {
        shortest_paths3[target] = MAX_DIST;
        for (int neighbor = 0; neighbor < 4; neighbor++) {
            if (neighbor != 1) {  // Skip disconnected node
                shortest_paths3[target] = getMin3(shortest_paths3[target], 
                                                dt3.route_matrix[target][neighbor]);
            }
        }
    }
}

void broadcastUpdates3() {
    for (int receiver = 0; receiver < 4; receiver++) {
        outgoing_msgs3[receiver].sourceid = THIS_NODE;
        outgoing_msgs3[receiver].destid = receiver;
        for (int i = 0; i < 4; i++) {
            outgoing_msgs3[receiver].mincost[i] = shortest_paths3[i];
        }
    }

    for (int receiver = 0; receiver < 4; receiver++) {
        if (receiver != THIS_NODE && receiver != 1 && 
            neighbor_weights3[receiver] < MAX_DIST) {
            tolayer2(outgoing_msgs3[receiver]);
            printf("At %.3f: Node %d -> Node %d costs: [%d %d %d %d]\n",
                   clocktime, THIS_NODE, receiver,
                   shortest_paths3[0], shortest_paths3[1],
                   shortest_paths3[2], shortest_paths3[3]);
        }
    }
}

void processAndBroadcast3() {
    int old_paths[4];
    for (int i = 0; i < 4; i++) old_paths[i] = shortest_paths3[i];
    
    updateMinimumCosts3();
    
    int needs_update = 0;
    for (int j = 0; j < 4; j++) {
        if (old_paths[j] != shortest_paths3[j]) {
            needs_update = 1;
            break;
        }
    }
    
    if (needs_update) {
        printf("\nNode %d: Path costs changed, sending updates\n", THIS_NODE);
        broadcastUpdates3();
    } else {
        printf("\nNode %d: No routing changes detected\n", THIS_NODE);
    }
}

void rtinit3() {
    printf("\n=== Initializing Node %d at %.3f ===\n", THIS_NODE, clocktime);
    
    for (int dest = 0; dest < 4; dest++) {
        for (int via = 0; via < 4; via++) {
            dt3.route_matrix[dest][via] = 
                (dest == via) ? neighbor_weights3[dest] : MAX_DIST;
        }
    }
    
    printdt3(&dt3);
    updateMinimumCosts3();
    broadcastUpdates3();
}

void rtupdate3(struct rtpkt *rcvdpkt) {
    int sender = rcvdpkt->sourceid;
    int new_costs[4];
    for (int i = 0; i < 4; i++) new_costs[i] = rcvdpkt->mincost[i];
    
    printf("\n=== Node %d received update at %.3f ===\n", THIS_NODE, clocktime);
    printf("From node %d: [%d %d %d %d]\n", 
           sender, new_costs[0], new_costs[1], new_costs[2], new_costs[3]);
    
    int modified = 0;
    for (int dest = 0; dest < 4; dest++) {
        int updated_cost = dt3.route_matrix[sender][sender] + new_costs[dest];
        if (updated_cost > MAX_DIST) updated_cost = MAX_DIST;
        
        if (dt3.route_matrix[dest][sender] != updated_cost) {
            dt3.route_matrix[dest][sender] = updated_cost;
            modified = 1;
        }
    }
    
    printdt3(&dt3);
    if (modified) {
        printf("Updated routing table from node %d data\n", sender);
    }
    processAndBroadcast3();
}

void linkhandler3(int link, int new_cost) {
    printf("\n=== Link Update at %.3f ===\n", clocktime);
    printf("Node %d - Node %d cost now %d\n", THIS_NODE, link, new_cost);
    
    int old_cost = neighbor_weights3[link];
    neighbor_weights3[link] = new_cost;
    int diff = new_cost - old_cost;
    
    for (int dest = 0; dest < 4; dest++) {
        if (dt3.route_matrix[dest][link] < MAX_DIST) {
            dt3.route_matrix[dest][link] += diff;
        }
    }
    
    printdt3(&dt3);
    processAndBroadcast3();
}