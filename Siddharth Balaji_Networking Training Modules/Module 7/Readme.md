![image](https://github.com/user-attachments/assets/c7ce2da9-8538-4349-83f5-9f39db879bca)## Question 1

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

Type the following commands in switch CLI to enable telnet.

````
Switch>enable
Switch#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
Switch(config)#vlan 99
Switch(config-vlan)#name Management
Switch(config-vlan)#exit
Switch(config)#interface vlan 99
Switch(config-if)#
%LINK-5-CHANGED: Interface Vlan99, changed state to up

Switch(config-if)#ip address 192.168.1.100 255.255.255.0
Switch(config-if)#no shutdown
Switch(config-if)#exit
Switch(config)#
Switch(config)#interface FastEthernet0/1
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 99
Switch(config-if)#
%LINEPROTO-5-UPDOWN: Line protocol on Interface Vlan99, changed state to up
exit
Switch(config)#hostname MySwitch
MySwitch(config)#ip domain-name example.com
MySwitch(config)#crypto ket generate rsa
                          ^
% Invalid input detected at '^' marker.
	
MySwitch(config)#crypto key generate rsa
The name for the keys will be: MySwitch.example.com
Choose the size of the key modulus in the range of 360 to 4096 for your
  General Purpose Keys. Choosing a key modulus greater than 512 may take
  a few minutes.

How many bits in the modulus [512]: 2048
% Generating 2048 bit RSA keys, keys will be non-exportable...[OK]

MySwitch(config)#ip ssh version 2
*Mar 1 0:4:52.21: %SSH-5-ENABLED: SSH 1.99 has been enabled
MySwitch(config)#username admin secret xyz
MySwitch(config)#
MySwitch(config)#line vty 0 4
MySwitch(config-line)#login local
MySwitch(config-line)#transport input shh
                                       ^
% Invalid input detected at '^' marker.
	
MySwitch(config-line)#transport input ssh
MySwitch(config-line)#exit
MySwitch(config)#
````

When I login to the telnet in the command prompt of the PC, I am able to login and gain access with the creadentials I had set in CLI of the switch.


## Question 8


## Question 9 

Troubleshooting technique:

Use "sh vlan brief" to check whether the ports are assigned properly. If vlan 10 and 20 are not assigned to their corresponding ports, use the below commands on 
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

On using "sh vlan brief", we can see vlan 10 and 20 listed.
