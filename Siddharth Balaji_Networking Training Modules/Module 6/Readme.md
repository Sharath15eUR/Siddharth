## Q1

ARP is at Data Link layer and is used to reslove IP address to MAC address in the local network.

"arp" display filter is applied in WIreshark to display arp packets.

Request: Sent by a device to verify whether its IP address is avaiable and gather the MAC address. This is a broadcast.

Who has 192.168.0.105? Tell 192.168.0.1 (router) . The router will now reply with who has that IP.

Reply: It is an acknowldgement and shares its MAC address. This is a unicast.

192.168.0.103 is at 00:11:22:33:44:55:66 MAC address.

The Address Resolution Protocol (ARP) is crucial in packet forwarding because it maps a device's IP address to its corresponding MAC address, enabling proper data transmission within a local network. Without ARP, devices wouldn't know the destination MAC address required for forwarding packets at the data link layer (Layer 2), leading to communication failure.

## Q 2

