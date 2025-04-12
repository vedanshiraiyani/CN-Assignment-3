Initializing Node 0 at time 0.000

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1 999 999
   2 | 999   3 999
   3 | 999 999   7
-------------------------
At 0.000: Node 0 -> Node 1 costs: [0 1 3 7]
At 0.000: Node 0 -> Node 2 costs: [0 1 3 7]
At 0.000: Node 0 -> Node 3 costs: [0 1 3 7]

-- Initializing Node 1 at 0.000 --

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1   999
  2 | 999     1
  3 | 999   999
-------------------
TIME 0.000: Node 1 -> Node 0 costs: [1 0 1 999]
TIME 0.000: Node 1 -> Node 2 costs: [1 0 1 999]

=== Starting Node 2 at time 0.000 ===

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3  999  999
     1      | 999    1  999
     3      | 999  999    2
*****************************
At 0.000: Node 2 -> Node 0 costs: [3 1 0 2]
At 0.000: Node 2 -> Node 1 costs: [3 1 0 2]
At 0.000: Node 2 -> Node 3 costs: [3 1 0 2]

=== Initializing Node 3 at 0.000 ===

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7  999
     1      | 999  999
     2      | 999    2
*****************************
At 0.000: Node 3 -> Node 0 costs: [7 999 2 0]
At 0.000: Node 3 -> Node 2 costs: [7 999 2 0]
MAIN: rcv event, t=0.947, at 3 src: 0, dest: 3, contents:   0   1   3   7

=== Node 3 received update at 0.947 ===
From node 0: [0 1 3 7]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7  999
     1      |   8  999
     2      |  10    2
*****************************
Updated routing table from node 0 data

Node 3: Path costs changed, sending updates
At 0.947: Node 3 -> Node 0 costs: [7 8 2 0]
At 0.947: Node 3 -> Node 2 costs: [7 8 2 0]
MAIN: rcv event, t=0.992, at 0 src: 1, dest: 0, contents:   1   0   1 999

Node 0 received update from 1 at 0.992
Received costs: [1 0 1 999]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1 999 999
   2 |   2   3 999
   3 | 999 999   7
-------------------------
Distance table updated
Node 0 detected cost changes
At 0.992: Node 0 -> Node 1 costs: [0 1 2 7]
At 0.992: Node 0 -> Node 2 costs: [0 1 2 7]
At 0.992: Node 0 -> Node 3 costs: [0 1 2 7]
MAIN: rcv event, t=1.209, at 3 src: 2, dest: 3, contents:   3   1   0   2

=== Node 3 received update at 1.209 ===
From node 2: [3 1 0 2]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    5
     1      |   8    3
     2      |  10    2
*****************************
Updated routing table from node 2 data

Node 3: Path costs changed, sending updates
At 1.209: Node 3 -> Node 0 costs: [5 3 2 0]
At 1.209: Node 3 -> Node 2 costs: [5 3 2 0]
MAIN: rcv event, t=1.276, at 3 src: 0, dest: 3, contents:   0   1   2   7

=== Node 3 received update at 1.276 ===
From node 0: [0 1 2 7]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    5
     1      |   8    3
     2      |   9    2
*****************************
Updated routing table from node 0 data

Node 3: No routing changes detected
MAIN: rcv event, t=1.642, at 2 src: 0, dest: 2, contents:   0   1   3   7

=== Node 2 received update at 1.642 ===
From node 0 with costs: [0 1 3 7]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3  999  999
     1      |   4    1  999
     3      |  10  999    2
*****************************
Routing table modified from node 0 update

Node 2: No path cost updates needed
MAIN: rcv event, t=1.871, at 1 src: 0, dest: 1, contents:   0   1   3   7

-- Node 1 received update from 0 at 1.871 --
Received costs: [0 1 3 7]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1   999
  2 |   4     1
  3 |   8   999
-------------------
Distance table modified from node 0 data

Node 1: Path costs changed, sending updates.
TIME 1.871: Node 1 -> Node 0 costs: [1 0 1 8]
TIME 1.871: Node 1 -> Node 2 costs: [1 0 1 8]
MAIN: rcv event, t=2.166, at 2 src: 1, dest: 2, contents:   1   0   1 999

=== Node 2 received update at 2.166 ===
From node 1 with costs: [1 0 1 999]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2  999
     1      |   4    1  999
     3      |  10  999    2
*****************************
Routing table modified from node 1 update

Node 2: Detected path cost changes
At 2.166: Node 2 -> Node 0 costs: [2 1 0 2]
At 2.166: Node 2 -> Node 1 costs: [2 1 0 2]
At 2.166: Node 2 -> Node 3 costs: [2 1 0 2]
MAIN: rcv event, t=2.407, at 0 src: 2, dest: 0, contents:   3   1   0   2

Node 0 received update from 2 at 2.407
Received costs: [3 1 0 2]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4 999
   2 |   2   3 999
   3 | 999   5   7
-------------------------
Distance table updated
Node 0 detected cost changes
At 2.407: Node 0 -> Node 1 costs: [0 1 2 5]
At 2.407: Node 0 -> Node 2 costs: [0 1 2 5]
At 2.407: Node 0 -> Node 3 costs: [0 1 2 5]
MAIN: rcv event, t=2.421, at 2 src: 3, dest: 2, contents:   7 999   2   0

=== Node 2 received update at 2.421 ===
From node 3 with costs: [7 999 2 0]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    9
     1      |   4    1  999
     3      |  10  999    2
*****************************
Routing table modified from node 3 update

Node 2: No path cost updates needed
MAIN: rcv event, t=2.811, at 1 src: 2, dest: 1, contents:   3   1   0   2

-- Node 1 received update from 2 at 2.811 --
Received costs: [3 1 0 2]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     4
  2 |   4     1
  3 |   8     3
-------------------
Distance table modified from node 2 data

Node 1: Path costs changed, sending updates.
TIME 2.811: Node 1 -> Node 0 costs: [1 0 1 3]
TIME 2.811: Node 1 -> Node 2 costs: [1 0 1 3]
MAIN: rcv event, t=3.293, at 2 src: 3, dest: 2, contents:   7   8   2   0

=== Node 2 received update at 3.293 ===
From node 3 with costs: [7 8 2 0]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    9
     1      |   4    1   10
     3      |  10  999    2
*****************************
Routing table modified from node 3 update

Node 2: No path cost updates needed
MAIN: rcv event, t=3.602, at 3 src: 2, dest: 3, contents:   2   1   0   2

=== Node 3 received update at 3.602 ===
From node 2: [2 1 0 2]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    4
     1      |   8    3
     2      |   9    2
*****************************
Updated routing table from node 2 data

Node 3: Path costs changed, sending updates
At 3.602: Node 3 -> Node 0 costs: [4 3 2 0]
At 3.602: Node 3 -> Node 2 costs: [4 3 2 0]
MAIN: rcv event, t=4.063, at 2 src: 0, dest: 2, contents:   0   1   2   7

=== Node 2 received update at 4.063 ===
From node 0 with costs: [0 1 2 7]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    9
     1      |   4    1   10
     3      |  10  999    2
*****************************
Routing table modified from node 0 update

Node 2: No path cost updates needed
MAIN: rcv event, t=4.104, at 0 src: 3, dest: 0, contents:   7 999   2   0

Node 0 received update from 3 at 4.104
Received costs: [7 999 2 0]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4 999
   2 |   2   3   9
   3 | 999   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=4.169, at 2 src: 3, dest: 2, contents:   5   3   2   0

=== Node 2 received update at 4.169 ===
From node 3 with costs: [5 3 2 0]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    7
     1      |   4    1    5
     3      |  10  999    2
*****************************
Routing table modified from node 3 update

Node 2: No path cost updates needed
MAIN: rcv event, t=4.330, at 0 src: 3, dest: 0, contents:   7   8   2   0

Node 0 received update from 3 at 4.330
Received costs: [7 8 2 0]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  15
   2 |   2   3   9
   3 | 999   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=4.643, at 1 src: 0, dest: 1, contents:   0   1   2   7

-- Node 1 received update from 0 at 4.643 --
Received costs: [0 1 2 7]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     4
  2 |   3     1
  3 |   8     3
-------------------
Distance table modified from node 0 data

Node 1: No path cost changes.
MAIN: rcv event, t=5.213, at 0 src: 3, dest: 0, contents:   5   3   2   0

Node 0 received update from 3 at 5.213
Received costs: [5 3 2 0]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 | 999   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=5.384, at 3 src: 0, dest: 3, contents:   0   1   2   5

=== Node 3 received update at 5.384 ===
From node 0: [0 1 2 5]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    4
     1      |   8    3
     2      |   9    2
*****************************
Updated routing table from node 0 data

Node 3: No routing changes detected
MAIN: rcv event, t=5.820, at 1 src: 2, dest: 1, contents:   2   1   0   2

-- Node 1 received update from 2 at 5.820 --
Received costs: [2 1 0 2]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     3
  2 |   3     1
  3 |   8     3
-------------------
Distance table modified from node 2 data

Node 1: No path cost changes.
MAIN: rcv event, t=6.042, at 2 src: 1, dest: 2, contents:   1   0   1   8

=== Node 2 received update at 6.042 ===
From node 1 with costs: [1 0 1 8]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    7
     1      |   4    1    5
     3      |  10    9    2
*****************************
Routing table modified from node 1 update

Node 2: No path cost updates needed
MAIN: rcv event, t=6.071, at 0 src: 1, dest: 0, contents:   1   0   1   8

Node 0 received update from 1 at 6.071
Received costs: [1 0 1 8]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   9   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=6.532, at 1 src: 0, dest: 1, contents:   0   1   2   5

-- Node 1 received update from 0 at 6.532 --
Received costs: [0 1 2 5]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     3
  2 |   3     1
  3 |   6     3
-------------------
Distance table modified from node 0 data

Node 1: No path cost changes.
MAIN: rcv event, t=7.021, at 0 src: 2, dest: 0, contents:   2   1   0   2

Node 0 received update from 2 at 7.021
Received costs: [2 1 0 2]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   9   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=7.160, at 2 src: 0, dest: 2, contents:   0   1   2   5

=== Node 2 received update at 7.160 ===
From node 0 with costs: [0 1 2 5]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    7
     1      |   4    1    5
     3      |   8    9    2
*****************************
Routing table modified from node 0 update

Node 2: No path cost updates needed
MAIN: rcv event, t=7.405, at 0 src: 1, dest: 0, contents:   1   0   1   3

Node 0 received update from 1 at 7.405
Received costs: [1 0 1 3]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   4   5   7
-------------------------
Distance table updated
Node 0 detected cost changes
At 7.405: Node 0 -> Node 1 costs: [0 1 2 4]
At 7.405: Node 0 -> Node 2 costs: [0 1 2 4]
At 7.405: Node 0 -> Node 3 costs: [0 1 2 4]
MAIN: rcv event, t=7.579, at 3 src: 0, dest: 3, contents:   0   1   2   4

=== Node 3 received update at 7.579 ===
From node 0: [0 1 2 4]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    4
     1      |   8    3
     2      |   9    2
*****************************
Updated routing table from node 0 data

Node 3: No routing changes detected
MAIN: rcv event, t=7.941, at 1 src: 0, dest: 1, contents:   0   1   2   4

-- Node 1 received update from 0 at 7.941 --
Received costs: [0 1 2 4]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     3
  2 |   3     1
  3 |   5     3
-------------------
Distance table modified from node 0 data

Node 1: No path cost changes.
MAIN: rcv event, t=8.086, at 0 src: 3, dest: 0, contents:   4   3   2   0

Node 0 received update from 3 at 8.086
Received costs: [4 3 2 0]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   4   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=8.639, at 2 src: 1, dest: 2, contents:   1   0   1   3

=== Node 2 received update at 8.639 ===
From node 1 with costs: [1 0 1 3]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    7
     1      |   4    1    5
     3      |   8    4    2
*****************************
Routing table modified from node 1 update

Node 2: No path cost updates needed
MAIN: rcv event, t=8.943, at 2 src: 3, dest: 2, contents:   4   3   2   0

=== Node 2 received update at 8.943 ===
From node 3 with costs: [4 3 2 0]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    6
     1      |   4    1    5
     3      |   8    4    2
*****************************
Routing table modified from node 3 update

Node 2: No path cost updates needed
MAIN: rcv event, t=9.960, at 2 src: 0, dest: 2, contents:   0   1   2   4

=== Node 2 received update at 9.960 ===
From node 0 with costs: [0 1 2 4]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    6
     1      |   4    1    5
     3      |   7    4    2
*****************************
Routing table modified from node 0 update

Node 2: No path cost updates needed
MAIN: rcv event, t=10000.000, at -1
Link change detected at 10000.000: Node 0 -> Node 1 now cost 20

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |  20   4  10
   2 |  21   3   9
   3 |  23   5   7
-------------------------
Node 0 detected cost changes
At 10000.000: Node 0 -> Node 1 costs: [0 4 3 5]
At 10000.000: Node 0 -> Node 2 costs: [0 4 3 5]
At 10000.000: Node 0 -> Node 3 costs: [0 4 3 5]

-- Link change at 10000.000 --
Link 1->0 now costs 20

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |  20     3
  2 |  22     1
  3 |  24     3
-------------------

Node 1: Path costs changed, sending updates.
TIME 10000.000: Node 1 -> Node 0 costs: [3 0 1 3]
TIME 10000.000: Node 1 -> Node 2 costs: [3 0 1 3]
MAIN: rcv event, t=10000.178, at 1 src: 0, dest: 1, contents:   0   4   3   5

-- Node 1 received update from 0 at 10000.178 --
Received costs: [0 4 3 5]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |  20     3
  2 |  23     1
  3 |  25     3
-------------------
Distance table modified from node 0 data

Node 1: No path cost changes.
MAIN: rcv event, t=10000.702, at 0 src: 1, dest: 0, contents:   3   0   1   3

Node 0 received update from 1 at 10000.702
Received costs: [3 0 1 3]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |  20   4  10
   2 |  21   3   9
   3 |  23   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=10001.166, at 3 src: 0, dest: 3, contents:   0   4   3   5

=== Node 3 received update at 10001.166 ===
From node 0: [0 4 3 5]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    4
     1      |  11    3
     2      |  10    2
*****************************
Updated routing table from node 0 data

Node 3: No routing changes detected
MAIN: rcv event, t=10001.964, at 2 src: 0, dest: 2, contents:   0   4   3   5

=== Node 2 received update at 10001.964 ===
From node 0 with costs: [0 4 3 5]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    6
     1      |   7    1    5
     3      |   8    4    2
*****************************
Routing table modified from node 0 update

Node 2: No path cost updates needed
MAIN: rcv event, t=10003.342, at 2 src: 1, dest: 2, contents:   3   0   1   3

=== Node 2 received update at 10003.342 ===
From node 1 with costs: [3 0 1 3]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    4    6
     1      |   7    1    5
     3      |   8    4    2
*****************************
Routing table modified from node 1 update

Node 2: Detected path cost changes
At 10003.342: Node 2 -> Node 0 costs: [3 1 0 2]
At 10003.342: Node 2 -> Node 1 costs: [3 1 0 2]
At 10003.342: Node 2 -> Node 3 costs: [3 1 0 2]
MAIN: rcv event, t=10003.448, at 0 src: 2, dest: 0, contents:   3   1   0   2

Node 0 received update from 2 at 10003.448
Received costs: [3 1 0 2]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |  20   4  10
   2 |  21   3   9
   3 |  23   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=10004.307, at 1 src: 2, dest: 1, contents:   3   1   0   2

-- Node 1 received update from 2 at 10004.307 --
Received costs: [3 1 0 2]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |  20     4
  2 |  23     1
  3 |  25     3
-------------------
Distance table modified from node 2 data

Node 1: Path costs changed, sending updates.
TIME 10004.307: Node 1 -> Node 0 costs: [4 0 1 3]
TIME 10004.307: Node 1 -> Node 2 costs: [4 0 1 3]
MAIN: rcv event, t=10004.417, at 3 src: 2, dest: 3, contents:   3   1   0   2

=== Node 3 received update at 10004.417 ===
From node 2: [3 1 0 2]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    5
     1      |  11    3
     2      |  10    2
*****************************
Updated routing table from node 2 data

Node 3: Path costs changed, sending updates
At 10004.417: Node 3 -> Node 0 costs: [5 3 2 0]
At 10004.417: Node 3 -> Node 2 costs: [5 3 2 0]
MAIN: rcv event, t=10004.669, at 0 src: 1, dest: 0, contents:   4   0   1   3

Node 0 received update from 1 at 10004.669
Received costs: [4 0 1 3]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |  20   4  10
   2 |  21   3   9
   3 |  23   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=10005.498, at 2 src: 1, dest: 2, contents:   4   0   1   3

=== Node 2 received update at 10005.498 ===
From node 1 with costs: [4 0 1 3]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    5    6
     1      |   7    1    5
     3      |   8    4    2
*****************************
Routing table modified from node 1 update

Node 2: No path cost updates needed
MAIN: rcv event, t=10005.692, at 2 src: 3, dest: 2, contents:   5   3   2   0

=== Node 2 received update at 10005.692 ===
From node 3 with costs: [5 3 2 0]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    5    7
     1      |   7    1    5
     3      |   8    4    2
*****************************
Routing table modified from node 3 update

Node 2: No path cost updates needed
MAIN: rcv event, t=10006.615, at 0 src: 3, dest: 0, contents:   5   3   2   0

Node 0 received update from 3 at 10006.615
Received costs: [5 3 2 0]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |  20   4  10
   2 |  21   3   9
   3 |  23   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=20000.000, at 0
Link change detected at 20000.000: Node 0 -> Node 1 now cost 1

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   4   5   7
-------------------------
Node 0 detected cost changes
At 20000.000: Node 0 -> Node 1 costs: [0 1 2 4]
At 20000.000: Node 0 -> Node 2 costs: [0 1 2 4]
At 20000.000: Node 0 -> Node 3 costs: [0 1 2 4]

-- Link change at 20000.000 --
Link 1->0 now costs 1

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     4
  2 |   4     1
  3 |   6     3
-------------------

Node 1: Path costs changed, sending updates.
TIME 20000.000: Node 1 -> Node 0 costs: [1 0 1 3]
TIME 20000.000: Node 1 -> Node 2 costs: [1 0 1 3]
MAIN: rcv event, t=20000.014, at 2 src: 0, dest: 2, contents:   0   1   2   4

=== Node 2 received update at 20000.014 ===
From node 0 with costs: [0 1 2 4]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    5    7
     1      |   4    1    5
     3      |   7    4    2
*****************************
Routing table modified from node 0 update

Node 2: No path cost updates needed
MAIN: rcv event, t=20000.068, at 0 src: 1, dest: 0, contents:   1   0   1   3

Node 0 received update from 1 at 20000.068
Received costs: [1 0 1 3]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   4   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=20000.885, at 2 src: 1, dest: 2, contents:   1   0   1   3

=== Node 2 received update at 20000.885 ===
From node 1 with costs: [1 0 1 3]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    7
     1      |   4    1    5
     3      |   7    4    2
*****************************
Routing table modified from node 1 update

Node 2: Detected path cost changes
At 20000.885: Node 2 -> Node 0 costs: [2 1 0 2]
At 20000.885: Node 2 -> Node 1 costs: [2 1 0 2]
At 20000.885: Node 2 -> Node 3 costs: [2 1 0 2]
MAIN: rcv event, t=20001.076, at 3 src: 0, dest: 3, contents:   0   1   2   4

=== Node 3 received update at 20001.076 ===
From node 0: [0 1 2 4]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    5
     1      |   8    3
     2      |   9    2
*****************************
Updated routing table from node 0 data

Node 3: No routing changes detected
MAIN: rcv event, t=20001.125, at 3 src: 2, dest: 3, contents:   2   1   0   2

=== Node 3 received update at 20001.125 ===
From node 2: [2 1 0 2]

**** Node 3 Routing Table ****
Destination | Via Nodes
------------+-----------
     0      |   7    4
     1      |   8    3
     2      |   9    2
*****************************
Updated routing table from node 2 data

Node 3: Path costs changed, sending updates
At 20001.125: Node 3 -> Node 0 costs: [4 3 2 0]
At 20001.125: Node 3 -> Node 2 costs: [4 3 2 0]
MAIN: rcv event, t=20001.834, at 0 src: 2, dest: 0, contents:   2   1   0   2

Node 0 received update from 2 at 20001.834
Received costs: [2 1 0 2]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   4   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=20001.961, at 1 src: 0, dest: 1, contents:   0   1   2   4

-- Node 1 received update from 0 at 20001.961 --
Received costs: [0 1 2 4]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     4
  2 |   3     1
  3 |   5     3
-------------------
Distance table modified from node 0 data

Node 1: No path cost changes.
MAIN: rcv event, t=20002.221, at 0 src: 3, dest: 0, contents:   4   3   2   0

Node 0 received update from 3 at 20002.221
Received costs: [4 3 2 0]

Current distance table for Node 0:
Dest | Cost via neighbors
-----+-------------------
   1 |   1   4  10
   2 |   2   3   9
   3 |   4   5   7
-------------------------
Distance table updated
Node 0: No cost changes
MAIN: rcv event, t=20002.854, at 2 src: 3, dest: 2, contents:   4   3   2   0

=== Node 2 received update at 20002.854 ===
From node 3 with costs: [4 3 2 0]

*** Node 2 Routing Table ***
Destination | Via Node
------------+----------------
     0      |   3    2    6
     1      |   4    1    5
     3      |   7    4    2
*****************************
Routing table modified from node 3 update

Node 2: No path cost updates needed
MAIN: rcv event, t=20002.979, at 1 src: 2, dest: 1, contents:   2   1   0   2

-- Node 1 received update from 2 at 20002.979 --
Received costs: [2 1 0 2]

--- Node 1 Distance Table ---
       via
 To |   0     2
----+---------
  0 |   1     3
  2 |   3     1
  3 |   5     3
-------------------
Distance table modified from node 2 data

Node 1: No path cost changes.

Simulator terminated at t=20002.978516, no packets in medium

=================== FINAL ROUTING TABLES ===================
Node 0 minimum costs: [0, 1, 2, 4]
Node 1 optimal paths: [1, 0, 1, 3]
Node 2 optimal path costs: [2, 1, 0, 2]
Node 3 shortest path costs: [4, 3, 2, 0]
===========================================================

