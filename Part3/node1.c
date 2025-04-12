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

#define INFINITY 999
#define THIS_NODE 1

struct distance_table {
  int path_costs[4][4];
} dt1;

int neighbor_costs1[4] = {1, 0, 1, 999};
struct rtpkt outgoing1[4];
int optimal_paths1[4];

int getMin1(int first, int second) {
    return first <= second ? first : second;
}

int findMinimum1(int numbers[4]) {
    int current_min = numbers[0];
    for (int k = 1; k < 4; k++) {
        if (numbers[k] < current_min) {
            current_min = numbers[k];
        }
    }
    return current_min;
}

void printdt1(struct distance_table *dt) {
    printf("\n--- Node %d Distance Table ---\n", THIS_NODE);
    printf("       via\n");
    printf(" To |   0     2\n");
    printf("----+---------\n");
    printf("  0 | %3d   %3d\n", dt->path_costs[0][0], dt->path_costs[0][2]);
    printf("  2 | %3d   %3d\n", dt->path_costs[2][0], dt->path_costs[2][2]);
    printf("  3 | %3d   %3d\n", dt->path_costs[3][0], dt->path_costs[3][2]);
    printf("-------------------\n");
}

void printmincost1() {
    printf("Node %d optimal paths: [%d, %d, %d, %d]\n",
           THIS_NODE, optimal_paths1[0], optimal_paths1[1],
           optimal_paths1[2], optimal_paths1[3]);
}

void updateMinimumCosts1() {
    for (int destination = 0; destination < 4; destination++) {
        optimal_paths1[destination] = dt1.path_costs[destination][0];
        for (int neighbor = 1; neighbor < 4; neighbor++) {
            if (dt1.path_costs[destination][neighbor] < optimal_paths1[destination]) {
                optimal_paths1[destination] = dt1.path_costs[destination][neighbor];
            }
        }
    }
}

void broadcastUpdates1() {
    for (int receiver = 0; receiver < 4; receiver++) {
        outgoing1[receiver].sourceid = THIS_NODE;
        outgoing1[receiver].destid = receiver;
        for (int i = 0; i < 4; i++) {
            outgoing1[receiver].mincost[i] = optimal_paths1[i];
        }
    }

    for (int receiver = 0; receiver < 4; receiver++) {
        if (receiver != THIS_NODE && neighbor_costs1[receiver] < INFINITY) {
            tolayer2(outgoing1[receiver]);
            printf("TIME %.3f: Node %d -> Node %d costs: [%d %d %d %d]\n",
                   clocktime, THIS_NODE, receiver,
                   optimal_paths1[0], optimal_paths1[1],
                   optimal_paths1[2], optimal_paths1[3]);
        }
    }
}

void processAndBroadcast1() {
    int old_paths[4];
    for (int i = 0; i < 4; i++) old_paths[i] = optimal_paths1[i];

    updateMinimumCosts1();

    int needs_update = 0;
    for (int j = 0; j < 4; j++) {
        if (old_paths[j] != optimal_paths1[j]) {
            needs_update = 1;
            break;
        }
    }

    if (needs_update) {
        printf("\nNode %d: Path costs changed, sending updates.\n", THIS_NODE);
        broadcastUpdates1();
    } else {
        printf("\nNode %d: No path cost changes.\n", THIS_NODE);
    }
}

void rtinit1() {
    printf("\n-- Initializing Node %d at %.3f --\n", THIS_NODE, clocktime);

    for (int dest = 0; dest < 4; dest++) {
        for (int via = 0; via < 4; via++) {
            dt1.path_costs[dest][via] = (dest == via) ? neighbor_costs1[dest] : INFINITY;
        }
    }

    printdt1(&dt1);
    updateMinimumCosts1();
    broadcastUpdates1();
}

void rtupdate1(struct rtpkt *rcvdpkt) {
    int sender = rcvdpkt->sourceid;
    int new_costs[4];
    for (int i = 0; i < 4; i++) new_costs[i] = rcvdpkt->mincost[i];

    printf("\n-- Node %d received update from %d at %.3f --\n",
           THIS_NODE, sender, clocktime);
    printf("Received costs: [%d %d %d %d]\n",
           new_costs[0], new_costs[1], new_costs[2], new_costs[3]);

    int modified = 0;
    for (int dest = 0; dest < 4; dest++) {
        int updated_cost = dt1.path_costs[sender][sender] + new_costs[dest];
        if (updated_cost > INFINITY) updated_cost = INFINITY;

        if (dt1.path_costs[dest][sender] != updated_cost) {
            dt1.path_costs[dest][sender] = updated_cost;
            modified = 1;
        }
    }

    printdt1(&dt1);
    if (modified) {
        printf("Distance table modified from node %d data\n", sender);
    }
    processAndBroadcast1();
}

void linkhandler1(int link, int new_cost) {
    printf("\n-- Link change at %.3f --\n", clocktime);
    printf("Link %d->%d now costs %d\n", THIS_NODE, link, new_cost);

    int old_cost = neighbor_costs1[link];
    neighbor_costs1[link] = new_cost;
    int diff = new_cost - old_cost;

    for (int dest = 0; dest < 4; dest++) {
        if (dt1.path_costs[dest][link] < INFINITY) {
            dt1.path_costs[dest][link] += diff;
        }
    }

    printdt1(&dt1);
    processAndBroadcast1();
}