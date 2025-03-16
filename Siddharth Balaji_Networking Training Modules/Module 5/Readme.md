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
