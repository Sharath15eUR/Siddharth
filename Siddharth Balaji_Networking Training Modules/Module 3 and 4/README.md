## Question 1:

Image 1.1 shows three PCs connected to 2096 swicth. The PCs are set with the IP addresses 192.168.1.1, 2 and 3 respectively with a subnet mask of 255.255.255.0.
A ping is sent from PC1 to PC2. The packets reach the intended destination and network with multiple devices is simulated. 

Image 1.2 shows the MAC address table of Switch0 using the command "show mac address-table" in the CLI of Swicth0. 

Image 1.3 shows the source and destination MAC addresses of packet that is sent. It also tells the type of protocol used for this transmission.

## Question 2: 

Image 2.1 simulates a network that contains two PCs and 2096 switch and ping command is sent from 
PC0 to PC1 through Swicth0. NO packets are lost.

Image 2.2 shows the execution of "show mac address-table" in the CLI of Swicth0 to indicate that the presence both the devices are recognised and the successful trasnfer of packets from one to another.

Image 2.3 shows the execution of "arp -a" in command PC0 to show that PC0 knows the presence of PC1
by displaying PC1's MAC address.

Image 2.4 shows the simulation of the packets in the Simulation tab of Cisco packet tracer.

Image 2.5 of a Wireshark scan report shows the following:

Frame 1: total packet size, actual data stored and on which interface.

Ethernet II: destination MAc of the reciever, 
source MAC of the sender, 
EtherType which indicates the protocol, payload which is the data.
Internet Protocol Version is the protocol used. 

## Question 3:

Image 3.1 shows the visual representation of a network and the configuration of a static IP to PC0 

Image 3.2 shows a ping from PC0 to PC1 to ensure that packets are transmitted successfully.

Image 3.3 shows a focused screenshot of the ping.

Image 3.4 shows the MAC addresses of the both the PCs connected to the switch. 

Image 3.5, 3.6 and 3.7 are used to show the modification of MAC addresses and its verification.

Image 3.5 shows the usage of ifconfig command to display the various network connections and piped with grep to find the MAC address.

Image 3.6 shows how to down the connection to modify the MAC address. sudo ifconifg enp0s3 hw ether 00:11:22:33:44:55 shows the new MAC address assigned and verifying the new MAC.  

Image 3.7 verifies network connectivity.

## Question 4:

Image 4.1 shows the use if ifconfig to get information on the network. The ping to on IP failed.
Now it is tested with a public IP and it succeeded.

Image 4.2 shows traceroute to the failed ping and then to the other IP tp understand where it failed and succeeded.

Image 4.3 shows the MAC addresss and shows the route to which information travels.

## Question 5:

Image 5 shows a simple LAN setup with two Linux machines i.e. two PCs are connected via a swicth.

## Question 6: 

Image 6 shows the simulation of successful packet transfer from one machine to another. tracert is used to see whcih hops worked and failed. If it had failed ifconfig would be used, like in the one of the previous question to detect where the problem is. 

## Question 7:

Image 7.1 and 7.2 show a network and the tracrt command is used to find out where the packet were dropped. 

## Question 8:

q8 will have report and not images uploaded.

All physical ethernet device will be represented as its own within the kernel. This allows us to interact with the hardware more easily.
Each device can be operated on its own for transmission and receiving data by having a modular nature. 
Network device drivers are used for this purpose.
Each device is considered as a file as in /sys/class/net/

Internet Layer (IP) determines routing, while the Transport Layer (TCP/UDP) ensures reliable or fast delivery, depending on the protocol used. 

The kernel optimizes performance with offloading techniques such as Generic Receive Offload (GRO) and TCP Segmentation Offload (TSO)

Linux commands like ip link, ifconfig, and ethtool to set IP addresses, adjust MAC addresses, or enable/disable interfaces.

## Question 9:

First I will use the "ip link show" to display the network connections. It will show loop back connection and the ethernet.

Second, I will assign an IP address using "sudo ip address 192.168.1.100/24 dev enp0s3" (example) for the interface to be configured. Then I will verify using "ip address show enp0s3".

Third, I will activate the specific network interface using "ip link show enp0s3".

Fourth, I will set a default gateway using "sudo ip route add default via 192.168.1.1" and verify using "ip route show".

Fifth, I will ping the gateway and a public network like google.com to ensure network connectivity. 

Sixth, as I am using Ubuntu on Oracle VirtualBox I will have to make these changes permanent. 
I will edit /etc/netplan/01-netcfg.yaml file.

## Question 10:

Image 10 shows the connected networks and and the "bridge fdb show" command displays the MAC address table of a bridge/switch. 




