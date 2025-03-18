## Module 7 and 8 Answers

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

## Question 10

Here, PC0 belongs to vlan 10 and PC1 belongs to vlan 20 respectively. 

We are supposed to configure using a technique called "Router on Stick". 

We must conifgure the swtich to enbale access to the ports to receive data from the two vlans.

Then, the router must be conifgured to recieve packets through its corresponding port.

On pinging from PC0 in vlan 10 to PC1 in vlan 20, the packets are received completely.

Switch:
````
Switch>
Switch>
Switch>enable
Switch#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
Switch(config)#vlan 10 name Sales
                       ^
% Invalid input detected at '^' marker.
	
Switch(config)#vlan 10
Switch(config-vlan)#name Sales
Switch(config-vlan)#exit
Switch(config)#valn 20
                ^
% Invalid input detected at '^' marker.
	
Switch(config)#vlan 20
Switch(config-vlan)#name HR
Switch(config-vlan)#exit
Switch(config)#
Switch(config)#
Switch(config)#interface FastEthernet0/2
Switch(config-if)#siwtchport mode access
                   ^
% Invalid input detected at '^' marker.
	
Switch(config-if)#switchport mode access
Switch(config-if)#swicthport access vlan 10
                     ^
% Invalid input detected at '^' marker.
	
Switch(config-if)#switchport access vlan 10
Switch(config-if)#exit
Switch(config)#
Switch(config)#interface FasEthernet0/3
                            ^
% Invalid input detected at '^' marker.
	
Switch(config)#interface FastEthernet0/3
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 20
Switch(config-if)#exit
Switch(config)#
Switch(config)#interface FastEthernet0/24
Switch(config-if)#switchport mode trunk
Switch(config-if)#switchport trunk encapsulation dot1q
                                   ^
% Invalid input detected at '^' marker.
	
Switch(config-if)#
Switch#
%SYS-5-CONFIG_I: Configured from console by console

Switch#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
Switch(config)#interface FastEthernet0/24
Switch(config-if)#switchport mode access
Switch(config-if)#switchport mode trunk
Switch(config-if)#switchport trunk allowed vlan all
Switch(config-if)#exit
Switch(config)#
%LINK-5-CHANGED: Interface FastEthernet0/24, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/24, changed state to up


Switch con0 is now available


Press RETURN to get started.


Switch>
Switch>sh vlan brief

VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    Fa0/1, Fa0/4, Fa0/5, Fa0/6
                                                Fa0/7, Fa0/8, Fa0/9, Fa0/10
                                                Fa0/11, Fa0/12, Fa0/13, Fa0/14
                                                Fa0/15, Fa0/16, Fa0/17, Fa0/18
                                                Fa0/19, Fa0/20, Fa0/21, Fa0/22
                                                Fa0/23, Gig0/1, Gig0/2
10   Sales                            active    Fa0/2
20   HR                               active    Fa0/3
1002 fddi-default                     active    
1003 token-ring-default               active    
1004 fddinet-default                  active    
1005 trnet-default                    active    
Switch>sh interface trunk
Port        Mode         Encapsulation  Status        Native vlan
Fa0/24      on           802.1q         trunking      1

Port        Vlans allowed on trunk
Fa0/24      1-1005

Port        Vlans allowed and active in management domain
Fa0/24      1,10,20

Port        Vlans in spanning tree forwarding state and not pruned
Fa0/24      1,10,20

Switch>sh ip interface brief
Interface              IP-Address      OK? Method Status                Protocol 
FastEthernet0/1        unassigned      YES manual down                  down 
FastEthernet0/2        unassigned      YES manual up                    up 
FastEthernet0/3        unassigned      YES manual up                    up 
FastEthernet0/4        unassigned      YES manual down                  down 
FastEthernet0/5        unassigned      YES manual down                  down 
FastEthernet0/6        unassigned      YES manual down                  down 
FastEthernet0/7        unassigned      YES manual down                  down 
FastEthernet0/8        unassigned      YES manual down                  down 
FastEthernet0/9        unassigned      YES manual down                  down 
FastEthernet0/10       unassigned      YES manual down                  down 
FastEthernet0/11       unassigned      YES manual down                  down 
FastEthernet0/12       unassigned      YES manual down                  down 
FastEthernet0/13       unassigned      YES manual down                  down 
FastEthernet0/14       unassigned      YES manual down                  down 
FastEthernet0/15       unassigned      YES manual down                  down 
FastEthernet0/16       unassigned      YES manual down                  down 
FastEthernet0/17       unassigned      YES manual down                  down 
FastEthernet0/18       unassigned      YES manual down                  down 
FastEthernet0/19       unassigned      YES manual down                  down 
FastEthernet0/20       unassigned      YES manual down                  down 
FastEthernet0/21       unassigned      YES manual down                  down 
 --More-- 

`````

Router:
````
Router#
Router#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#interface GigabitEthernet0/0
Router(config-if)#no shutdown
Router(config-if)#exit
Router(config)#interface GigabitEthernet0/0.10
Router(config-subif)#
%LINK-5-CHANGED: Interface GigabitEthernet0/0.10, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface GigabitEthernet0/0.10, changed state to up

Router(config-subif)#ip address 192.168.10.1 255.255.255.0

% Configuring IP routing on a LAN subinterface is only allowed if that
subinterface is already configured as part of an IEEE 802.10, IEEE 802.1Q,
or ISL vLAN.

Router(config-subif)#ip address 192.168.10.1 255.255.255.0

% Configuring IP routing on a LAN subinterface is only allowed if that
subinterface is already configured as part of an IEEE 802.10, IEEE 802.1Q,
or ISL vLAN.

Router(config-subif)#interface GigabitEthernet0/0.10
Router(config-subif)#encapsulation dot1Q 10
Router(config-subif)#ip address 192.168.10.1 255.255.255.0
Router(config-subif)#exit
Router(config)#
Router(config)#interface GigabitEthernet0/0.20
Router(config-subif)#
%LINK-5-CHANGED: Interface GigabitEthernet0/0.20, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface GigabitEthernet0/0.20, changed state to up

Router(config-subif)#encapsulation dot1Q 20
Router(config-subif)#ip address 192.168.20.1 255.255.255.0
Router(config-subif)#exit
Router(config)#
````


## Question 11

There are a few ways doing this.

One is using the web browser in the PC1 to access http://192.168.1.1. However, Cisco Packet Tracer doesn't permit this. 

The other is using ssh -l admin 192.168.1.1

Or telnet 192.168.1.1

Even after several attempts to troubleshoot for all the three methods, it didn't work.
The vlan was active with the intended port. All access restrictions were removed. Router was conifgured properly, so was the Switch. 

# However, I gained valuable knowledge of conifguring a ssh, telnet and http and to remove access controls and various other troubleshooting methods and the various dependenices that have to checked in order for it to work.

These are the commands used in the router:
````
MyRouter#show ip ssh
SSH Enabled - version 2.0
Authentication timeout: 120 secs; Authentication retries: 3
MyRouter#show ip interface brief
Interface              IP-Address      OK? Method Status                Protocol 
GigabitEthernet0/0     192.168.1.1     YES manual up                    up 
GigabitEthernet0/1     unassigned      YES unset  administratively down down 
GigabitEthernet0/2     unassigned      YES unset  administratively down down 
Vlan1                  unassigned      YES unset  administratively down down
MyRouter#%IP-4-DUPADDR: Duplicate address 192.168.1.1 on GigabitEthernet0/0, sourced by 0001.C972.5291

MyRouter#
MyRouter#
MyRouter#show ip interface brief
Interface              IP-Address      OK? Method Status                Protocol 
GigabitEthernet0/0     192.168.1.1     YES manual up                    up 
GigabitEthernet0/1     unassigned      YES unset  administratively down down 
GigabitEthernet0/2     unassigned      YES unset  administratively down down 
Vlan1                  unassigned      YES unset  administratively down down
MyRouter#show vlan brief

VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    
1002 fddi-default                     active    
1003 token-ring-default               active    
1004 fddinet-default                  active    
1005 trnet-default                    active    
MyRouter#
MyRouter#
MyRouter#
MyRouter#exit




MyRouter con0 is now available



Press RETURN to get started.



MyRouter>
MyRouter>
MyRouter>
MyRouter>exit




MyRouter con0 is now available


Press RETURN to get started.




MyRouter>
MyRouter>
MyRouter>
MyRouter>exit



MyRouter con0 is now available



Press RETURN to get started.



MyRouter>
MyRouter>
MyRouter>
MyRouter>
MyRouter>enable
MyRouter#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
MyRouter(config)#line vty 0 4
MyRouter(config-line)#transport input telnet
MyRouter(config-line)#login local
MyRouter(config-line)#exit
MyRouter(config)#ip telnet source-interface GigabitEthernet0/0
                     ^
% Invalid input detected at '^' marker.
	
MyRouter(config)#username admin privilege 15 password myTelnetPass
ERROR: Can not have both a user password and a user secret.
Please choose one or the other.
MyRouter(config)#
MyRouter(config)#show ip interface brief
                  ^
% Invalid input detected at '^' marker.
	
MyRouter(config)#sh ip interface brief
                  ^
% Invalid input detected at '^' marker.
	
MyRouter(config)#exit
MyRouter#
%SYS-5-CONFIG_I: Configured from console by console

MyRouter#show ip interface brief
Interface              IP-Address      OK? Method Status                Protocol 
GigabitEthernet0/0     192.168.1.1     YES manual up                    up 
GigabitEthernet0/1     unassigned      YES unset  administratively down down 
GigabitEthernet0/2     unassigned      YES unset  administratively down down 
Vlan1                  unassigned      YES unset  administratively down down
MyRouter#show ip interface brief
Interface              IP-Address      OK? Method Status                Protocol 
GigabitEthernet0/0     192.168.1.1     YES manual up                    up 
GigabitEthernet0/1     unassigned      YES unset  administratively down down 
GigabitEthernet0/2     unassigned      YES unset  administratively down down 
Vlan1                  unassigned      YES unset  administratively down down
MyRouter#
MyRouter#
MyRouter#show running-config | section line vty
line vty 0 4
 login local
 transport input telnet
MyRouter#show access-lists
Extended IP access list 100
    10 permit tcp any any eq www
    20 deny tcp any any (48 match(es))
    30 permit tcp any any

MyRouter#
MyRouter#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
MyRouter(config)#ip access-list extended 100
MyRouter(config-ext-nacl)#permit tcp any any eq telnet
MyRouter(config-ext-nacl)#exit
MyRouter(config)#exit
MyRouter#
%SYS-5-CONFIG_I: Configured from console by console

MyRouter#write memory
Building configuration...
[OK]
MyRouter#
````

These are the commands I used in the Switch:
````
Switch>enable
Switch#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
Switch(config)#interface FastEthernet0/2
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 1
Switch(config-if)#exit
Switch(config)#interface FastEthernet0/3
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 1
Switch(config-if)#exit
Switch(config)#
Switch(config)#exit
Switch#
%SYS-5-CONFIG_I: Configured from console by console

Switch#show cdp neighbours
                       ^
% Invalid input detected at '^' marker.
	
Switch#show cdp neighbors
Capability Codes: R - Router, T - Trans Bridge, B - Source Route Bridge
                  S - Switch, H - Host, I - IGMP, r - Repeater, P - Phone
Device ID    Local Intrfce   Holdtme    Capability   Platform    Port ID
MyRouter     Fas 0/1          135            R       C2900       Gig 0/0
Switch#sh vlan brief

VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    Fa0/1, Fa0/2, Fa0/3, Fa0/4
                                                Fa0/5, Fa0/6, Fa0/7, Fa0/8
                                                Fa0/9, Fa0/10, Fa0/11, Fa0/12
                                                Fa0/13, Fa0/14, Fa0/15, Fa0/16
                                                Fa0/17, Fa0/18, Fa0/19, Fa0/20
                                                Fa0/21, Fa0/22, Fa0/23, Fa0/24
                                                Gig0/1, Gig0/2
1002 fddi-default                     active    
1003 token-ring-default               active    
1004 fddinet-default                  active    
1005 trnet-default                    active    
Switch#
Switch#conf t
Enter configuration commands, one per line.  End with CNTL/Z.
Switch(config)#interface FastEthernet0/1
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 1
Switch(config-if)#exit
Switch(config)#
Switch(config)#exit
Switch#
%SYS-5-CONFIG_I: Configured from console by console

Switch#write memory
Building configuration...
[OK]
Switch#
Switch#sh vlan brief

VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    Fa0/1, Fa0/2, Fa0/3, Fa0/4
                                                Fa0/5, Fa0/6, Fa0/7, Fa0/8
                                                Fa0/9, Fa0/10, Fa0/11, Fa0/12
                                                Fa0/13, Fa0/14, Fa0/15, Fa0/16
                                                Fa0/17, Fa0/18, Fa0/19, Fa0/20
                                                Fa0/21, Fa0/22, Fa0/23, Fa0/24
                                                Gig0/1, Gig0/2
1002 fddi-default                     active    
1003 token-ring-default               active    
1004 fddinet-default                  active    
1005 trnet-default                    active    
Switch#sh vlan brief

VLAN Name                             Status    Ports
---- -------------------------------- --------- -------------------------------
1    default                          active    Fa0/1, Fa0/2, Fa0/3, Fa0/4
                                                Fa0/5, Fa0/6, Fa0/7, Fa0/8
                                                Fa0/9, Fa0/10, Fa0/11, Fa0/12
                                                Fa0/13, Fa0/14, Fa0/15, Fa0/16
                                                Fa0/17, Fa0/18, Fa0/19, Fa0/20
                                                Fa0/21, Fa0/22, Fa0/23, Fa0/24
                                                Gig0/1, Gig0/2
1002 fddi-default                     active    
1003 token-ring-default               active    
1004 fddinet-default                  active    
1005 trnet-default                    active    
````

## Question 12

The goal is the conifgure a standard ACL on the router to permit traffic only from a specific IP range i.e. to permit traffic from some and deny all others.

First, we create a standard ACL to permit traffic within the range 192.168.1.0 to 192.168.1.255 and deny all others.

Second, we test the connectivity. A ping from PC0 to 192.168.1.1 will run successfully.
A ping from PC1 with IP address 10.10.10.100 will fail because it is blocked.


## Question 13

Here, we are supposed to create the extneded ACL to block http and ftp.
````
Router(config)# access-list 101 deny tcp any any eq 80   
Router(config)# access-list 101 deny tcp any any eq 21   
Router(config)# access-list 101 permit ip any any      
````
This will Block HTTP, Block FTP and Allow all other traffic.

On trying http://192.168.2.2 in the web browser, it times out.
On trying ftp access with C:\> ftp 192.168.2.2, it is blcoked.




To remove the block, we remove the existing ACL from the interface temporarily.
````
Router(config-ext-nacl)# permit tcp any host 192.168.2.2 eq ftp
````
OR delete the 'deny ftp' rule
````
Router(config)# ip access-list extended 101
Router(config-ext-nacl)# no 20
Router(config-ext-nacl)# exit
Router(config)# interface GigabitEthernet0/1
Router(config-if)# ip access-group 101 in
Router(config-if)# exit
````
Now, ftp 192.168.2.2 will work successfully and ask for username and password to login. 


## Question 14

Here, we try to ping the Google web server through a NAT router.

Private IP is transalted into Public IP.

Two routers are conifgured accordingly for inside and outside to enable this process.

When PC0 pings 8.8.8.8, NAT translations are shown in the router as shown in the image.
