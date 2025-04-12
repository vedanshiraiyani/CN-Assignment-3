# Computer Networks (CS-331) - Assignment 3

# Task-1: Network Loops

## Steps to Run the Topology and Perform Ping Tests

## 1. Run the Topology without STP
```bash
sudo mn -c
sudo python3 q1.py
```
## 2. Test Pings without STP
```bash
h3 ping -c 1 h1
h5 ping -c 1 h7
h8 ping -c 1 h2
```

## 3. Enable STP in the Code
In q1.py file, ```stp=True``` is added:
```bash
s1 = self.addSwitch('s1', stp=True)
s2 = self.addSwitch('s2', stp=True)
s3 = self.addSwitch('s3', stp=True)
s4 = self.addSwitch('s4', stp=True)
```
## 4. Run the Topology Again (With STP)
```bash
sudo mn -c
sudo python3 q1.py
```
## 5. Test Pings Again (With STP Enabled)
Run each ping 3 times with atleast 30 seconds gap:
```bash
h3 ping -c 1 h1
h5 ping -c 1 h7
h8 ping -c 1 h2
```



# Task-2 : Configure Host-based NAT


## Setup

1. **Install Mininet**:
   - Install Mininet by following the [Mininet Installation Guide](http://mininet.org/download/).
   - Ensure Python 3.x is installed along with Mininet and its dependencies.

2. **Run Mininet with Custom Python Script**:
   - Save the Python script in a file named `q2.py` and run Mininet with the following commands:

     ```bash
     sudo mn -c
     chmod +x q2.py
     sudo python3 q2.py
     ```
---

## Testing Procedure

### Part A: Testing Communication from Internal Hosts to External Hosts

1. **Ping Test: From `h1` to `h5` (External Host)**
   - The goal is to verify if the internal host (`h1`) can successfully ping the external host (`h5`).
   - To perform this test, use the following command in the Mininet CLI:
     ```bash
     h1 ping -c 1 10.0.0.6
     ```

2. **Ping Test: From `h2` to `h3` (External Host)**
   - This test checks whether the internal host (`h2`) can ping the external host (`h3`).
   - Run the following command in Mininet CLI:
     ```bash
     h2 ping -c 1 10.0.0.3
     ```



### Part B: Testing Communication from External Hosts to Internal Hosts

1. **Ping Test: From `h8` to `h1` (Internal Host)**
   - The objective is to check if the external host (`h8`) can successfully ping the internal host (`h1`).
   - To execute this test in the Mininet CLI, use the following command:
     ```bash
     h8 ping -c 1 172.16.10.11
     ```

2. **Ping Test: From `h6` to `h2` (Internal Host)**
   - This test verifies whether the external host (`h6`) can ping the internal host (`h2`).
   - Run the following command in Mininet CLI:
     ```bash
     h6 ping -c 1 172.16.10.12
     ```


### Part C: Run `iperf3` Bandwidth Tests

1. **`iperf3` Test 1: h1 (Server) and h6 (Client)**:
   - **Start the `iperf3` server on `h1`:**
     ```bash
     h1 iperf3 -s &
     ```

   - **Run the `iperf3` client on `h6`:**
     ```bash
     h6 iperf3 -c 172.16.10.11 -t 120
     ```

2. **`iperf3` Test 2: h8 (Server) and h2 (Client)**:
   - **Start the `iperf3` server on `h8`:**
     ```bash
     h8 iperf3 -s &
     ```

   - **Run the `iperf3` client on `h2`:**
     ```bash
     h2 iperf3 -c 172.16.10.12 -t 120
     ```



# Task-3: Network Routing 

## Network Setup
The network topology is as follows:

- Cost between Node 0 and Node 1 → 1  
- Cost between Node 0 and Node 2 → 3  
- Cost between Node 0 and Node 3 → 7  
- Cost between Node 1 and Node 2 → 1  
- Cost between Node 2 and Node 3 → 2  
- All other connections are assumed to be disconnected with cost = 999 (infinity)

---

## Code Implementation

### Description of Implemented Functions

The following functions form the core logic of the distance vector routing simulation:

- **`rtinitX()`**  
  Initializes the distance table for node `X`. It sets initial costs to directly connected neighbors and broadcasts this information to adjacent nodes.

- **`rtupdateX()`**  
  Handles incoming routing updates from neighboring nodes. It processes the received distance vectors, updates the node’s distance table, and broadcasts updates if any shorter paths are discovered.

- **`linkhandler0()`**  
  Manages dynamic link cost changes for Node 0. When a link cost is updated, it recalculates the shortest paths and updates its neighbors with the new distance vector if necessary.

- **`linkhandler1()`**  
  Similar to `linkhandler0()`, this function handles link cost changes for Node 1 and ensures the node's routing table stays consistent with the updated network topology.


These functions were implemented in the respective files: `node0.c`, `node1.c`, `node2.c`, `node3.c`

## Running the Code

```bash
gcc distance_vector.c node0.c node1.c node2.c node3.c -o distance_vector
./distance_vector > results.txt
```
