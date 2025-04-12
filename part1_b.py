from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import OVSBridge
from mininet.link import TCLink
from mininet.cli import CLI
from mininet.log import setLogLevel


class CustomLoopTopology(Topo):
    def build(self):
        # Creating switches with Spanning Tree Protocol enabled
        switches = {}
        for i in range(1, 5):
            switch_name = f's{i}'
            switches[switch_name] = self.addSwitch(switch_name, stp=True)

        # Defining hosts with their respective IPs
        host_ips = {
            'h1': '10.0.0.2/24',
            'h2': '10.0.0.3/24',
            'h3': '10.0.0.4/24',
            'h4': '10.0.0.5/24',
            'h5': '10.0.0.6/24',
            'h6': '10.0.0.7/24',
            'h7': '10.0.0.8/24',
            'h8': '10.0.0.9/24'
        }

        # Mapping hosts to their connected switch
        host_connections = {
            'h1': 's1', 'h2': 's1',
            'h3': 's2', 'h4': 's2',
            'h5': 's3', 'h6': 's3',
            'h7': 's4', 'h8': 's4'
        }

        # Adding hosts and linking them to switches with 5ms delay
        for host, ip in host_ips.items():
            host_node = self.addHost(host, ip=ip)
            switch_node = switches[host_connections[host]]
            self.addLink(host_node, switch_node, delay='5ms')

        # Interconnecting switches with 7ms delay links
        inter_switch_links = [('s1', 's2'), ('s2', 's3'), ('s3', 's4'), ('s4', 's1'), ('s1', 's3')]
        for sw1, sw2 in inter_switch_links:
            self.addLink(switches[sw1], switches[sw2], delay='7ms')


def start_network():
    topology = CustomLoopTopology()
    network = Mininet(topo=topology, link=TCLink, switch=OVSBridge, controller=None)
    network.start()
    CLI(network)
    network.stop()


if __name__ == '__main__':
    setLogLevel('info')
    start_network()
