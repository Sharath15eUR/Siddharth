## Question 1

Search for Windows Powershell on your host machine's search box and click enter to exceute the commands.

Enter the command Test-Connection and type the websites one by one to view the source, destination and IP addresses of the websites. 

Enter the nslookup command to view the name, addresses and aliases of the websites. 

## Question 2

Use the dns, tcp and udp display filters on Wireshark to view the corresponding packets.

Click the packets and view the various components that make these packets.

DNS  has 5 headers inlcudes:
Transcation id - same for both query and response
Flag - query (0x0100) , response (0x8108)
Question and Answer 
TTl - response time

TCP is connection oriented and has the following information: 
Souce port and destination port number
Sequence and  acknowledge number
Flag 
Window size

UDP is a connection less transmission and has the sourece and destination port number.

## Question 3

tracert is used to find out the path or the route packets take to reach their destination. 

-h is used to restrct the hops and -4/-6 for IPv4 or IPv6 addresses.


## Question 4

All the questions from question 5 onwards come under question 4. Q4 in itself has no questions but sub questions.

## Question 5

VLAN is used to communicate between members of the same department and ensure that others don't receive the message.

Here, two members of the Sales department are able to communicate while Sales to HR doesn't happen as the ports are configured that way.

The images also display the commands that should be used both switches to configure the ports and that the trunk is established to enable communication between
two VLANs.

## Question 6

Here, I have changed the native VLAN to disable the communication between VLANs by creating an issue called "Mismatch".

Then, I changed the native VLAN with correct one to remove this mismatch and enable communication by making both VLAN 99 instead of one having 99
and the other having 50.

On using the command "sh interface trunk", Native VLAN is listed as 99, thus sloving the problem.

## Question 7


## Question 8


## Question 9 

Troubleshooting technique:

Use "sh vlan bief" to check whether the ports are assigned properly. If vlan 10 and 20 are not assigned to their corresponding ports, use the below commands on 
both the switches to configure ports correctly.

````
Switch(config)#interface FastEthernet0/1
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 10
Switch(config-if)#exit

Switch(config)#interface FastEthernet0/2
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 20
Switch(config-if)#exit
````

On using "sh vlan breif", we can see vlan 10 and 20 listed.
