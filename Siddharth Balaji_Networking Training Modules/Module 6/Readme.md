## Q1

ARP is at Data Link layer and is used to reslove IP address to MAC address in the local network.

"arp" display filter is applied in WIreshark to display arp packets.

Request: Sent by a device to verify whether its IP address is avaiable and gather the MAC address. This is a broadcast.

Who has 192.168.0.105? Tell 192.168.0.1 (router) . The router will now reply with who has that IP.

Reply: It is an acknowldgement and shares its MAC address. This is a unicast.

192.168.0.103 is at 00:11:22:33:44:55:66 MAC address.

The Address Resolution Protocol (ARP) is crucial in packet forwarding because it maps a device's IP address to its corresponding MAC address, enabling proper data transmission within a local network. Without ARP, devices wouldn't know the destination MAC address required for forwarding packets at the data link layer (Layer 2), leading to communication failure.

## Q 2

I have set up two different subnets which are connected to a router. 

It is important that we give the correct gateway as mentioned in the image so that data reaches the correct destination. 

"ping" and "tracert" commands have been used to verify connectivity.

Packets reached the correct destination and connectivtiy was established successfully. 

## Q 3

The /24 subnet has 256 total IPs (2⁸ = 256).

To create 4 subnets, we will borrow 2 more bits from the host portion:
Original subnet mask: 255.255.255.0 (/24)
New subnet mask: 255.255.255.192 (/26)

Each subnet gets: 2⁶ = 64 IP addresses (including network and broadcast).

Subnet Ranges are as follows:

The subnet increments by 64 IPs.

Subnet Number   Network Address	   First Host	    Last Host	      Broadcast Address
Subnet 1	      10.0.0.0/26	       10.0.0.1	      10.0.0.62	      10.0.0.63
Subnet 2	      10.0.0.64/26	     10.0.0.65	    10.0.0.126	    10.0.0.127
Subnet 3	      10.0.0.128/26	     10.0.0.129	    10.0.0.190	    10.0.0.191
Subnet 4	      10.0.0.192/26	     10.0.0.193	    10.0.0.254	    10.0.0.255

Entering the new subnet mask as 255.255.255.192 is the most important part otherwise, the subnets will overlap with the other GigabitEthernet.

## Q 4

192.168.10.5 belongs to Class C and is a private IP address. Range: 192.168.0.0 - 192.168.255.255

172.20.15.1 belongs to Class B and is a private IP address.  Range: 172.16.0.0 - 172.31.255.255

8.8.8.8 belongs to Class A and is a public IP address.  Range: 1.0.0.0 - 126.255.255.255

Private IP addresses cannot be routed on the internet. 

Network Address Translation (NAT) allows devices with private IPs to access the internet by translating them into a public IP assigned by an ISP.

The router replaces it with the public IP assigned by the ISP.

NAT table that maps the private IP and port to the public IP and port.

When a response is returned, the NAT table is checked and the packet is sent to the correct device.

## Q 5



