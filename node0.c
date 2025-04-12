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
#define NODE_ID 0

struct distance_table {
  int costs[4][4];
} dt0;

int directCosts0[4] = {0, 1, 3, 7};
struct rtpkt outPackets0[4];
int bestCost0[4];

int getMin0(int x, int y) {
    return (x <= y) ? x : y;
}

int findMinimum0(int arr[4]) {
    int m = arr[0];
    for (int i = 1; i < 4; i++) {
        if (arr[i] < m) m = arr[i];
    }
    return m;
}

void printdt0(struct distance_table *dt) {
    printf("\nCurrent distance table for Node %d:\n", NODE_ID);
    printf("Dest | Cost via neighbors\n");
    printf("-----+-------------------\n");
    for (int dest = 1; dest < 4; dest++) {
        printf("%4d |", dest);
        for (int via = 1; via < 4; via++) {
            printf(" %3d", dt->costs[dest][via]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

void printmincost0() {
    printf("Node %d minimum costs: [%d, %d, %d, %d]\n",
           NODE_ID, bestCost0[0], bestCost0[1], bestCost0[2], bestCost0[3]);
}

void updateMinimumCosts0() {
    for (int i = 0; i < 4; i++) {
        bestCost0[i] = dt0.costs[i][0];
        for (int j = 1; j < 4; j++) {
            if (dt0.costs[i][j] < bestCost0[i]) {
                bestCost0[i] = dt0.costs[i][j];
            }
        }
    }
}

void broadcastUpdates0() {
    for (int neighbor = 1; neighbor < 4; neighbor++) {
        if (directCosts0[neighbor] != INFINITY) {
            outPackets0[neighbor].sourceid = NODE_ID;
            outPackets0[neighbor].destid = neighbor;
            for (int i = 0; i < 4; i++) {
                outPackets0[neighbor].mincost[i] = bestCost0[i];
            }
            tolayer2(outPackets0[neighbor]);
            printf("At %.3f: Node %d -> Node %d costs: [%d %d %d %d]\n",
                   clocktime, NODE_ID, neighbor,
                   bestCost0[0], bestCost0[1], bestCost0[2], bestCost0[3]);
        }
    }
}

void processAndBroadcast0() {
    int oldCosts[4];
    for (int i = 0; i < 4; i++) oldCosts[i] = bestCost0[i];
    
    updateMinimumCosts0();
    
    int changed = 0;
    for (int i = 0; i < 4 && !changed; i++) {
        changed = (oldCosts[i] != bestCost0[i]);
    }
    
    if (changed) {
        printf("Node %d detected cost changes\n", NODE_ID);
        broadcastUpdates0();
    } else {
        printf("Node %d: No cost changes\n", NODE_ID);
    }
}

void rtinit0() {
    printf("\nInitializing Node %d at time %.3f\n", NODE_ID, clocktime);
    
    for (int dest = 0; dest < 4; dest++) {
        for (int via = 0; via < 4; via++) {
            dt0.costs[dest][via] = (dest == via) ? directCosts0[dest] : INFINITY;
        }
    }
    
    printdt0(&dt0);
    updateMinimumCosts0();
    broadcastUpdates0();
}

void rtupdate0(struct rtpkt *rcvdpkt) {
    printf("\nNode %d received update from %d at %.3f\n",
           NODE_ID, rcvdpkt->sourceid, clocktime);
    printf("Received costs: [%d %d %d %d]\n",
           rcvdpkt->mincost[0], rcvdpkt->mincost[1],
           rcvdpkt->mincost[2], rcvdpkt->mincost[3]);
    
    int src = rcvdpkt->sourceid;
    int changed = 0;
    
    for (int dest = 0; dest < 4; dest++) {
        int newCost = directCosts0[src] + rcvdpkt->mincost[dest];
        if (newCost > INFINITY) newCost = INFINITY;
        
        if (dt0.costs[dest][src] != newCost) {
            dt0.costs[dest][src] = newCost;
            changed = 1;
        }
    }
    
    printdt0(&dt0);
    if (changed) {
        printf("Distance table updated\n");
        processAndBroadcast0();
    } else {
        printf("No updates needed\n");
    }
}

void linkhandler0(int linkid, int newcost) {
    printf("\nLink change detected at %.3f: Node %d -> Node %d now cost %d\n",
           clocktime, NODE_ID, linkid, newcost);
    
    int oldcost = directCosts0[linkid];
    directCosts0[linkid] = newcost;
    int diff = newcost - oldcost;
    
    for (int dest = 0; dest < 4; dest++) {
        if (dt0.costs[dest][linkid] != INFINITY) {
            dt0.costs[dest][linkid] += diff;
        }
    }
    
    printdt0(&dt0);
    processAndBroadcast0();
}