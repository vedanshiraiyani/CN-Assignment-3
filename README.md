# CS-331: Computer Networks — Assignment 3  

---

## Task 1: Network Loops

### Objective
Simulate a switching loop in a network topology and demonstrate how enabling Spanning Tree Protocol (STP) resolves the issue.

### How to Run

#### Step 1: Launch the Topology (Without STP)
sudo mn -c
sudo python3 q1.py
Step 2: Test Pings (Without STP)

h3 ping -c 1 h1
h5 ping -c 1 h7
h8 ping -c 1 h2
These pings will fail (100% packet loss) due to network loops.

Step 3: Enable STP
In q1.py, modify the switch definitions as follows:


s1 = self.addSwitch('s1', stp=True)
s2 = self.addSwitch('s2', stp=True)
s3 = self.addSwitch('s3', stp=True)
s4 = self.addSwitch('s4', stp=True)
Step 4: Run the Topology Again (With STP)

sudo mn -c
sudo python3 q1.py
Step 5: Test Pings Again
Run each ping 3 times, waiting 30 seconds between each:


h3 ping -c 1 h1
h5 ping -c 1 h7
h8 ping -c 1 h2
Pings should now succeed, indicating that STP has resolved the loop.

Task 2: Host-based NAT
Objective
Implement NAT using host h9 as the gateway between an internal private network and external hosts.

Topology Changes
New host h9 connected to switch s1 with a 5ms delay.

Hosts h1 and h2 are now connected to h9, simulating an internal private network.

h9 is assigned a public IP 172.16.10.10, while h1 and h2 use private IPs.

How to Run
Ensure Mininet and Python 3 are installed.

Save your topology script as q2.py.


sudo mn -c
chmod +x q2.py
sudo python3 q2.py
Testing
Part A: Internal → External

h1 ping -c 1 10.0.0.6   # h1 to h5
h2 ping -c 1 10.0.0.3   # h2 to h3
Part B: External → Internal

h8 ping -c 1 172.16.10.11  # h8 to h1
h6 ping -c 1 172.16.10.12  # h6 to h2
Part C: Bandwidth Tests (iperf3)
Test 1: h1 (Server) and h6 (Client)


h1 iperf3 -s &
h6 iperf3 -c 172.16.10.11 -t 120
Test 2: h8 (Server) and h2 (Client)


h8 iperf3 -s &
h2 iperf3 -c 172.16.10.12 -t 120
Repeat both tests three times.

Task 3: Distance Vector Routing
Objective
Simulate Distance Vector Routing among 4 nodes with dynamic updates and cost changes.

Network Costs
Node 0 ↔ Node 1: 1

Node 0 ↔ Node 2: 3

Node 0 ↔ Node 3: 7

Node 1 ↔ Node 2: 1

Node 2 ↔ Node 3: 2

All other costs = 999 (infinite)

Implemented Functions
Function	Description
rtinitX()	Initializes the routing table for Node X
rtupdateX()	Updates routing table on receiving neighbor updates
linkhandlerX()	Handles dynamic cost changes (extra credit)
