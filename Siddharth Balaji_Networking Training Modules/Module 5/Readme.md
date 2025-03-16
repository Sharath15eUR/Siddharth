## Question 1 

ARP is at Data Link layer and is used to reslove IP address to MAC address in the local network.

ARP frames are of two types: Requests and Replies.

Request: Sent by a device to verify whether its IP address is avaiable and gather the MAC address.
This is a broadcast.

Who has 192.168.0.105? Tell 192.168.0.1. The router will no reply with who has that IP.

Reply: It is an acknowldgement and shares its MAC address. This is a unicast.

192.168.0.103 is at 00:11:22:33:44:55:66 MAC address.

## Question 2

In Cisco Packet Tracer "arp -s" command is not allowed. So, I decided to give the smae IP to the attacker PC and another device.

When, the packet is supposed to go to ther other device, it goes to the attcker PC instead, as the attacker makes it look like he is the correct recipient. 

First, I pinged all the other devices to check network connectivity. 
Second, I used "arp -a" to display the MAC addresses. 
Then, I pinged the devices which have the same IP and the attacker captures the packets and steals it. 


## Question 3 

Here, the IP addresses are  manually assigned to the PCs and pinged successfully and network connectivity is established.

## Question 4 

First, I started a Wireshark scan. 
Second, I used the Command Prompt of my host machine to execute "ipconfig /relsease" and  "ipconfig /renew" to make my machine send DHCP Discover message and start the DORA process.

D-Discover:
The client broadcasts a CHCP Discover message to find the available IPs in the DHCP server, 
0.0.0.0 is used as IP and broadcasts to destination IP 255.255.255.0.

O-Offer:
The DHCP server responds with an offer message of available IP address. This maybe broadcast or unicast based on the network setup.

R-Request:
The client send request messae to accept one of the offered IP address with a confirmation.

A-Acknowledge:
An ACK message is sent to confirm the assigned IP address with the necessary data like IP address, lease time, subnet mask, gateway and more. 
