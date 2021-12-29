CREATE TABLE IF NOT EXISTS data (type VARCHAR(64) PRIMARY KEY , data VARCHAR(15000));
-- Course 1:
INSERT INTO data VALUES ('Fundamental notions','Concepts and fundamental notions

Content
• Concepts
• Definitions
• Computer networks – necessity and use
• Classification
• Topologies
• Components

Concepts
• Information: anything that can be represented using bits 
• Resource: generic term that can signify data, equipment et. al.
• Package: a way of storing data
• Link: a connection among network members
• Node: a computer from the network which has an address
• Protocol: rules used to communicate
• Communication: information exchanges between network nodes

A protocol defines the format and the order of messages 
exchanged betweentwo or more communicating entities, 
as well as the actions taken on the transmissionand/or 
receipt of a message or other event.

Definitions:
– Interconnected collection of autonomous computers
– A network may be defined recursively as two or more 
nodes physically connected, as well as two or several 
networks connected through one or more nodes.
• Aspects:
– Hardware: connect computers from a physical point of view
– Software: Protocols – specify services provided by the network

Necessity:
• Resource sharing (physical, data)
• Reliability
• Reduced costs
• Impact in real life:
– Remote information access
– Interactive entertainment
– E-Commerce

Networks types- classification

• After the spatial arrangement:
    – PAN (Personal Area Network)
    – LAN (Local Area Network) 
    – MAN (Metropolitan Area Network)
    – WAN (Wide Area Network)
    – Internet

• Depending on transmission technology:
– Broadcast networks (one channel to 
communicate)
    • broadcast, multicast
– Point-to-point networks
    • unicast

Network topologies

Physical topology: the way computers are connected in 
the network
Logical topology: the way in which data are transferd from 
one computer to other
Possible physical topologies for:
– Broadcast networks - LAN
    • Bus
    • Ring
– Point-to-point networks
    • Star
    • Ring
    • Tree
    • Mesh

Networks types- classification

• Depending on the hardware technology (and 
software) used for interconnection:
–Networks using wired transmission medium
–Networks using wireless transmission medium

• Depending on the components:

– Homogeneous: the computer networks use 
similar configurations and protocols
• Example: A network using Microsoft Windows via TCP/IP
– Heterogeneous: the network contains different 
types of computers, operating systems and/or 
different protocols
• Example: a LAN that connects a smart phone with an 
Android and an Apple Machintosh computer

Components

• Host - it’s a computational system connected to the Internet
• Hub Network - a device (often a signal 
booster) used to connect multiple 
devices => network segment
• Switch - a device which filters network 
packets and resends them
• Router - device providing connectivity between networks, perform routing 
packets between these networks
• Bridge - device that connects two LANs or two segments of the same LAN
• Gateway - is a connection point of two networks that use different base 
protocols
• Repeater - device that receives signals that it rebroadcast at a higher level 
or higher power, so that the signal can cover large areas without degrading its quality');

-- Course 2:
INSERT INTO data VALUES ('Computers Networks Structure','Computers Networks Structure

• Computer Network Structure – stack levels

-Functionality:

• Interface: ensure communication between two 
consecutive levels
• Service: functionality provided by a level 
Result: reducing design complexity

-The principle of communication: transmitter sends at n 
level what the recipient receives at the n level 
• Protocol – Rules and conventions through which the 
communication takes place');

INSERT INTO data VALUES ('Aspects regarding levels design','Aspects regarding levels design

• Specifying the service is performed by a set of primitives 
(operations) available to the one who uses the service
• Service!= Protocol

• Services types

– Connection-oriented
• Communication requires a connection
• Similar to a telephone service

– Connectionless
• Communication does not require a connection
• Similar to postal service

• Network architecture: the set of levels and protocols
– Architecture specification must provide sufficient 
information for programs or equipment intended, in 
order to offer the specific protocols
• Protocols stack: list of protocols (on all levels) used by a 
particular system

• Each level must identify transmitters & receivers 
through an addressing mechanism
• Data transfer rules identification
– simplex communication
• Example: TV 
– half-duplex communication
• Example: "walkie-talkie"
– full-duplex communication
• Example: telephone

• In general, communication channels do not preserve the order 
of the sent messages => need for a protocol that provides a 
mechanism to reconstruct the correct messages order 
• Sometimes the receiver cannot manage the variable length 
messages => it must be a mechanism to divide/assemble
• High costs in the allocation of separate connections? => 
Multiplexing - use the same connection for independent 
conversations
• In general, there are several ways between source and 
destination => routing mechanism
• Physical communication circuits are not perfect => it asks for an 
error control mechanism');

INSERT INTO data VALUES ('Network architecture models','Network architecture models
• ISO/OSI (International Standard Organization/ Open 
System Interconnection)
• TCP/IP (Transmission Control Protocol/ Internet 
Protocol)');

INSERT INTO data VALUES ('Devices and appropriate levels','Devices and appropriate levels:

• Application layer - Application gateway
• Transport layer - Transport gateway
• Network layer - Router
• Data link layer - Bridge, Switch
• Physical layer - Repeater, Hub');

INSERT INTO data VALUES ('OSI Model - motivation','OSI Model - motivation
• The need for a different level of abstraction => to create a new level
• Obs. The number of levels must be optimal, therefore each 
level has different functions and the whole architecture is functional
• A level has a clear role; a level function must take into account 
protocols that are standardized at international level 
• Minimizing the flow of information between levels is accomplished 
through good boundary levels => Levels can be modified and 
implemented independently
• Each level offers services for superior level (using services from previous levels)
• “peer” levels of different systems communicate via a protocol');

INSERT INTO data VALUES ('OSI Model – structure','OSI Model – structure
• Physical Level
• Data Link Level
• Network Level
• Transport Level
• Session Level
• Presentation Level
• Application Level');

INSERT INTO data VALUES ('OSI Model - Physical Level','OSI Model - Physical Level
Physical Level: data transmission medium
Role: ensure that the sequence of bits transmitted from 
the transmitter reaches the receiver
– Transmission media:
• Wired (twisted pair, coaxial cable, optical fiber)
• Wireless (electromagnetic spectrum - radio, 
microwave, infrared, ...) -> next course

Data transmission:

• Analog (continuous values)
– Example: telephone systems
– Digital (discrete)
– Example: computers
Data conversion from analog to digital and vice versa:

• Modem: digital data are transmitted in analog format
• Codec (coder/decoder): analog data are transmitted in digitalformat

• Physical Level - aspects

– Bandwidth: the number of bits that can be 
transmitted over the network in a given 
period of time (data transfer speed)
•Usually expressed in bits/seconds

– Latency: represents the maximum time 
required for a bit to propagate in a network, 
from one end to another and it is expressed 
in units of time
    •RTT(Round Trip Time) – the necessary 
    time for a bit to cross from one end to the 
    other and back to the environment

Modification suffered by signals during propagation:
• Attenuation: energy loss during signal propagation through a transmission medium
• Noise: signal change caused by external factors (e.g. lightning, other electronic equipment, etc.) 
– Diaphony = noise from the signal transmitted by a neighbouring transmission medium
• Distortion- is a deterministic change of a signal

• Physical Level - conclusions
Offers transportation services, on which we can identify a number of possible problems
– Data can be altered / destroyed due to the noise
– If the destination cannot process the data in the right time, some will be lost
– If the same transmission medium is used by multiple transmitters, packages may alter each other
– It is less expensive to build logical connections to share the same physical medium, than create independent physical links');

INSERT INTO data VALUES ('OSI Model - Data Link Level','OSI Model - Data Link Level
• Data Link Level:

Offers:
• mechanisms to detect and correct errors
• regulatory mechanisms for dataflow
• control mechanism for media access
• Services at the network level 
• The data unit used at this level is called frame

– The data are encapsulated in frames 
– Analogy: frame= digital envelope

– It provides services at the network level
• Unconfirmed connectionless service
    » The transmitter sends independent frames to the 
    receiver without waiting for any confirmation 
    » A lost frame is not recovered
• Confirmed connectionless service
    » The sent frames are confirmed
    » The frames are not sent in order
• Confirmed connection-oriented services
    » A connection is established before the transmission
    » Frames are numbered to keep the right order

– Divided into two sublevels:
    • LLC (Logical Link Control)
        – Role: Provides an independent view of the medium at a superior level
    • MAC (Medium Access Control)
        – Role: Used to determine who is to transmit into multi-access channel

MAC (Medium Access Control)
– Context of the problem: the same physical environment is used by more emitters (uniquely identified by a 
physical address or MAC address) operating simultaneously, for example:
    – Half-duplex transmission between entities that use 
    the same physical environment for both directions
    – communication by radio when there are stations that 
    emit on the same wavelength (Wireless Ethernet -IEEE 802.11, Bluetooth, etc.)
    – Strategies:
         Static allocation
            » FDM (Frequency Division Multiplexing)
            » TDM (Time Division Multiplexing)
        – Accepting the possibility of collisions and retransmitting 
        packets affected by collisions - dynamic allocation
            Collision = data is simultaneously transmitted
            General mechanism: a station that has data to send, 
        transmit them immediately; if the collision appears, the 
        resend action is performed.

Medium Access Control – protocols:
    – ALOHA
        • Pure ALOHA : “send whenever you want”
    – CSMA (Carrier Sense - Multiple Access): protocol with 
    transmission detection (“free channel before sending?”)
        • 1-persistent CSMA 
        • …
        • p-persistent CSMA
    – CSMA/CD (CSMA with Collision Detection)
        » “free channel while transmit?”
        » Based on Ethernet LAN (IEEE 802.3)
    – MACA (Multiple Access with Collision Avoidance)
        • The basis for wireless networks (IEEE 802.11)
    – MACAW
        • Improves MACA

Medium Access Control – Standards Example

Standard IEEE   |    Description
802             |    Group standards for LAN and MAN
802.2           |    LLC (Logical Link Control) 
802.3           |    Ethernet (Carrier Sense Multiple Access with 
                |    Collision Detect (CSMA/CD))
802.3u          |    Fast Ethernet 
802.3z          |    Gigabit Ethernet 
802.11          |    Wireless (WLAN)
a/b/g/n/ac      |
802.15          |    Wireless PAN ( 802.15.1 Bluetooth, ...)
802.16          |    Wireless WAN

• Data Link Level - equipment

• Bridges
    – Resend frames between two networks (LAN)
    – It doesn’t change the frame content and only headers can be modified
    – Improve safety and performance transmission
    – Can provide flow control and congestion data
    – Retransmission is done via static routes or using a spanning tree
        STP (IEEE 802.1D) – Spanning Tree Protocol');
        
INSERT INTO data VALUES ('OSI Model - Network Level','OSI Model - Network Level
• Network Level:
    – Retrieves packages from the source and transfer them to the destination
    – It provides services to transport level
        • What services?
            – Internet community proposes: 
                » Connectionless services: SEND PACKET, RECEIVE PACKET
                » Packages (called datagrams) are independent and are managed individually
                » Datagram services are similar to a typical post system
            – Telephone companies propose:
                » Connection-oriented service – safe services
                » Before the transfer some negotiations are 
                  initiated to establish a connection (VC-virtual circuit)
                » These services are similar to the telephony system

– Used Protocols
• X.25 (Connection-oriented)
• IP

– Problems

• Protocol conversions and addresses
• Error control (flow, congestion)
• Dividing and recomposing packages
• Security – encryption, firewall');

INSERT INTO data VALUES ('OSI Model - Transport level','OSI Model - Transport level
• Transport level: it offers safe and cost-effective data transport from the source machine to the 
destination machine, independent of physical network or networks currently in use
    Services: provides connection-oriented and connectionless services

– Primitives:
    • LISTEN – it’s a blocking operation until a process tries to connect
    • CONNECT – trying to establish a connection
    • SEND – send data
    • RECEIVE – it’s a blocking operation until data is received
    • DISCONNECT – connection release

– Performance - quality of service (QoS - Quality of Service): establishing /releasing the connection, error rate, protection, 
priority, resilience (the probability that a connection shut down because various internal reasons), duplicate packets, flow control.');

INSERT INTO data VALUES ('OSI Model - Session level','OSI Model - Session level
• Session level: refers to problems linked to session settings (dialogue control services, synchronisation etc.)');

INSERT INTO data VALUES ('OSI Model - Presentation level','OSI Model - Presentation level
• Presentation level: handle data presentation, codified them into standard format
    – To ensure communication among computers with different representations, the presentation level 
      ensures the conversion of internal data in standardized network representation and vice versa');

INSERT INTO data VALUES ('OSI Model - Application level','OSI Model - Application level
• Application level: manage network services: virtual terminal, file transfer, 
electronic mail, remote execution of applications, ...');

INSERT INTO data VALUES ('TCP/IP Model','TCP/IP Model

• Terms:
    – end-system – host
    – network - provides support for data transfer between end systems
    – internet - collection of networks (interconnected)
    – Sub-network - part of the internet
    – intermediate system - connects two subnetworks

• It provides the ability to interconnect multiple network types
• Network and Transport levels are the kernel of this model
• Successfully implemented over Ethernet (IEEE 802.3) -supported by many 
implementations of the physical layer (coaxial cable, twisted pair, fiber optic)');

INSERT INTO data VALUES ('TCP/IP Model - "Physical" level','TCP/IP Model - "Physical" level
• "Physical" level
– Ensure the connection between host and the network 

    Ethernet 
        • It provides multiple access (shared transmission medium) in a network 
        • Collision Detection: CSMA / CD (Carrier Sense Multiple Access with Collision Detection)
        • Each Ethernet interface has a unique address 48 bits: hardware address (MAC) -e.g. C0: B3: 44: 17: 21: 17
        • Addresses are assigned to NIC (Network Interface Card) producers by a central authority
        • Each interface (board) network has a unique MAC address (some operating systems allow it to be modified by software)
        • The first 24 bits identify the manufacturer
        • A frame format:
            - PREAMBLE – Ethernet frame starts with 7-Bytes Preamble. This is a pattern of alternative 0’s and 1’s which indicates starting of the 
            frame and allow sender and receiver to establish bit synchronization. Initially, PRE (Preamble) was introduced to allow for the loss 
            of a few bits due to signal delays. But today’s high-speed Ethernet don’t need Preamble to protect the frame bits.
            PRE (Preamble) indicates the receiver that frame is coming and allow the receiver to lock onto the data stream before the actual 	 frame begins.
            - Start of frame delimiter (SFD) is a 1-Byte field which is always set to 10101011. 
            SFD indicates that upcoming bits are starting of the frame, which is the destination address. 
            Sometimes SFD is considered the part of PRE, this is the reason Preamble is described as 8 Bytes in many places. 
            The SFD warns station or stations that this is the last chance for synchronization.
            - Destination Address is 6-Byte field which contains the MAC address of machine for which data is destined.
            - Source Address is a 6-Byte field which contains the MAC address of source machine. 
            As Source Address is always an individual address (Unicast), the least significant bit of first byte is always 0.
            - Length is a 2-Byte field, which indicates the length of entire Ethernet frame. This 16-bit field can hold the length value 
            between 0 to 65534, but length cannot be larger than 1500 because of some own limitations of Ethernet.
            - Data is the place where actual data is inserted, also known as Payload. Both IP header and data will be inserted here if Internet Protocol 
            is used over Ethernet. The maximum data present may be as long as 1500 Bytes. In case data length is less than minimum length i.e. 46 bytes, 
            then padding 0’s is added to meet the minimum possible length.
            - Cyclic Redundancy Check (CRC) – CRC is 4 Byte field. This field contains a 32-bits hash code of data, 
            which is generated over the Destination Address, Source Address, Length, and Data field. If the checksum computed by destination 
            is not the same as sent checksum value, data received is corrupted.

            Note – Size of frame of Ethernet IEEE 802.3 varies 64 bytes to 1518 bytes including data length (46 to 1500 bytes).

        • Broadcast: the address has all bits set to 1
        • Each network interface inspecting the destination address in each frame
        • If the destination address does not match with the hardware address or the broadcast address, then the frame is ignored

    Ethernet – standards (examples):
        • 10 BASE5: 10 Mbps using thick coaxial cable (Thick Ethernet)-1980
        • 1BASE5: 1 Mbps using two Ethernet cables (Unshilded Twisted Pair)
        • 10BASE-T: 10Mbps using 2 pairs UTP– 1990
        • 10BASE-FL: 10 Mbps optical fiber with point-to-point link
        • 10BASE-FB: 10Mbps backbone with optical fiber
        • 100BASE – FX: 100MBps CSMA/CD with two optical fiber, full duplex
        • … etc

- Gigabit Ethernet
    • Implementations for both copper wires (802.3ab), and fiber (802.3z)
    • The difference from other Ethernet implementations is at physical level
- 10 Gigabit Ethernet
    • Implementations for fiber (802.3ae)
    • Operates at distances of 40km (useful for MAN and WAN)
    • Frame format is similar to other implementations of Ethernet');

INSERT INTO data VALUES ('TCP/IP Model - Network Level','TCP/IP Model - Network Level
• Network Level
    – It allows hosts to emit a packet in any network; packages travel independently up to destination
    – Highlights: routing packets congestion avoidance
    – Level design aimed at achieving the following objectives:
        • The services offered are independent from the technology used (e.g. routers)
        • Provide transport level services, which allow it to operate independently of number, type and topology
        • It provides a unique mechanism to address LANs and WANs
    – IPv4 
    – IPv6 
    – Routing
        • OSPF(Open Shortest Path First) – RFC 1131
        • BGP(Border Gateway Protocol) – RFC 1105
    – Multicast:
        • IGMP (Internet Group Management Protocol) – RFC 1112, 1054
    – Control:
        • ICMP (Internet Control Messages Protocol) - RFC 792,777
        • SNMP (Simple Network Management Protocol) – RFC 1157
        • ICMPv6');

INSERT INTO data VALUES ('TCP/IP Model - Transport level','TCP/IP Model - Transport level
• Transport level
    – Ensures the realization of communication between the source host and destination host
    – Protocols
        • TCP (Transmission Control Protocol) - RFC 793,761
        • UDP (User Datagram Protocol) – RFC 768
        • Other Protocols: SCTP (Stream Control Transmission Protocol) – RFC 4960, 3286 (2960, 3309);DCCP
        (Datagram Congestion Control Protocol) – RFC 4340, 4336;');

INSERT INTO data VALUES ('TCP/IP Model - Application Level','TCP/IP Model - Application Level
• Application Level:
    – Contains high level protocols
    – SMTP (Simple Mail Transfer Protocol) – RFC 5321 (821)
    – POP3(Post Office Protocol) – RFC 1081
    – TELNET – RFC 854,764
    – FTP (File Transfer Protocol) – RFC 454
    – NFS (Network File System) – RFC 1095
    – DNS (Domain Name System) – RFC 1034,1035
    – HTTP (HyperText Transfer Protocol) – RFC 2616
    – RTP (Real-time Transport Protocol) – RFC 3550 (1889)
    – SIP (Session Initiation Protocol) – RFC 3261
    – …etc');

INSERT INTO data VALUES ('TCP/IP Model - Organizations involved in standardization','TCP/IP Model - Organizations involved in standardization
• Organizations involved in standardization:
    – ISOC – Internet Society
    – IAB – Internet Architecture Board
    – IETF – Internet Engineering Task Force
    – IRTF – Internet Research Task Force
    – InterNIC – Internet Network Information Center
    – IANA – Internet Assigned Number Authority
• RFC (Request For Comments) documents
    – Edited by Network Working Group (IETF)
    – RFC 1800 (Internet Official Protocol Standards)
    – More details -> www.ietf.org');
    
INSERT INTO data VALUES ('OSI versus TCP/IP','OSI versus TCP/IP
• Similarities:
    – Both are based on a protocol stack
    – The layer functionalities are somehow similar
    – Both have an application layer on top
    – Are based (directly or not) on transport level

• Differences:
    – ISO/OSI is a theoretical model; TCP/IP is effective in implementation
    – OSI makes explicit the distinction between service, interface and protocol; TCP / IP does not
    – ISO / OSI provides protocols that ensure reliable communication (detection and
    treatment of errors at each level); TCP/IP verifies communication at transport level
    – OSI support both types of communication at network level (connectionless and connection
    oriented); TCP/IP has connectionless services at network level and both types at transport level');
    
-- Course 3:
INSERT INTO data VALUES ('Network Level','Network Level
• Role: offers connectionless services to 
transport datagrams from source to 
destination; source and destination can be 
in different networks
• Each datagram is independent from the 
others
• This level does not guarantee the right 
transmission (loss, multiplier,…)
Protocols:
- ICMP (RFC 792)
- ARP (RFC 826)
- RARP (RFC 903)
- BOOTP (RFC 951,1048,1084)
- DHCP');

INSERT INTO data VALUES ('IP - Internet Protocol','IP Protocol
• IP protocol is used for autonomous systems (AS - Autonomous 
Systems) in order to interconnect.
• IPv4 Datagram:
	IPv4 is a connectionless protocol used for packet-switched networks. It operates on a best effort delivery model, in which neither 	delivery is guaranteed, nor proper sequencing or avoidance of duplicate delivery is assured.
	IPv4 uses 32-bit (4 byte) addressing, which gives 2^32 addresses. IPv4 addresses are written in the dot-decimal notation, which comprises of four octets of the address expressed individually in decimal and separated by periods, for instance, 192.168.1.5.

IPv4 Datagram Header:
- VERSION: Version of the IP protocol (4 bits), which is 4 for IPv4
- HLEN: IP header length (4 bits), which is the number of 32 bit words in the header. The minimum value for this field is 5 and the maximum is 15.
- Type of service: Low Delay, High Throughput, Reliability (8 bits)
- Total Length: Length of header + Data (16 bits), which has a minimum value 20 bytes and the maximum is 65,535 bytes.
- Identification: Unique Packet Id for identifying the group of fragments of a single IP datagram (16 bits)
- Flags: 3 flags of 1 bit each : reserved bit (must be zero), do not fragment flag, more fragments flag (same order)
- Fragment Offset: Represents the number of Data Bytes ahead of the particular fragment in the particular Datagram. Specified in terms of number of 8 bytes, which has the maximum value of 65,528 bytes.
- Time to live: Datagram''s lifetime (8 bits), It prevents the datagram to loop through the network by restricting the number of Hops taken by a Packet before delivering to the Destination.
- Protocol: Name of the protocol to which the data is to be passed (8 bits). Protocols: 1 ICMP (Internet Control Message Protocol), 2 IGMP (Internet Group Message Protocol), 6 TCP (Transmission Control Protocol), 17 UDP (User Datagram Protocol),... etc.(RFC 1700)
- Header Checksum: 16 bits header checksum for checking errors in the datagram header
- Source IP address: 32 bits IP address of the sender
- Destination IP address: 32 bits IP address of the receiver
- Option: Optional information such as source route, record route. Used by the Network administrator to check whether a path is working or not.

IP Datagram
• Datagram''s Fragmentation:
• Each fragment has the same structure as the IP datagram
• Reassembly of datagrams is performed by the receiver
• If a fragment of a datagram is lost, the datagram is 
destroyed (an ICMP - Internet Control Message Protocol 
message is sent to the sender)
• Fragmentation mechanism has been used for some attacks 
- firewall piercing (a "special“ fragment is considered as 
part of a connection already established, so that it can pass 
through a firewall)
• Datagram Filtering:
• It is accomplished by a firewall: it allows access 
from the outside in the internal network, 
according to some policy, certain types of packets 
((used by certain protocols / services)
• Forestall a series of attacks regarding security
• The firewall can be software or hardware 
• The firewall can function as a proxy or a 
gateway

Proxy - role and architecture:
– Indirect access to other networks (Internet) to hosts 
on the local network (via proxy)
– The proxy allows an Internet connection sharing
– The proxy can be software or hardware
– May play roles such us: firewall or cache server
– Used to improve the performance (e.g., caching, flow 
control), filtering messages, ensuring anonymity

IPv4 Addresses:
• Each IP address includes a network 
identifier(NetID) and a host identifier
(HostID) 
• Each network interface has a single IPv4 
address
• An IPv4 address has a length of 32 bits
• Initially (RFC 791) there was a division into 
network classes: A,B,C,D,E
• Class A: 128 possible networks, 224 hosts/network
• Class B: 214 possible networks, 216 hosts/network
• Class C: over 2 million networks, 255 hosts/network
• Network Identifier(NetID) is assigned by a central authority 
(NIC – Network Information Center)
• Host Identifier(HostID) is assigned locally by a network 
administrator 
• Example: 85.122.23.145 – Class A (in decimal notation 
convention) 0101 0101 0111 1010 0001 0111 1001 0001
• For IPv6, hexadecimal representation is recommended
• An interface network has assigned a unique IP address
• A host can have multiple NICs, therefore it has multiple IP 
addresses
• The hosts of the same network have the same network 
identifier (the same NetID)
• Broadcast addresses have HostID''s bites equaled to 1
• The IP address in which all HostID''s bites are 0 is called a 
network address – refers to the hole network
• Example: 85.122.23.0 (network address for a host such 
us 85.122.23.145 and 85.122.23.1)
• 127.0.0.1 - loopback address (localhost)
• From the address space, some addresses are reserved: (RFC 1918):
- 0.0.0.0 - 0.255.255.255
- 10.0.0.0 - 10.255.255.255 (private addresses)
- 127.0.0.0 - 127.255.255.255 (loopback addresses)
- 172.16.0.0 - 172.31.255.255 (private addresses) 
- 192.168.0.0 - 192.168.255.255 (private addresses)
• Private addresses: addresses that are not accessible to the 
outside (the "real" Internet), but only in the organization''s intranet');
INSERT INTO data VALUES ('Private Networks','Private Networks
• Aspects:
- The exponential growth of the hosts number
- Not all hosts offer resources available on the Internet
	Solution: NAT (Network Address Translation) – RFC 3022, 4008
- The private addresses can be reused (RFC 1918)
- It is based on replacing the private IP address with a public IP address (IP masquerading)
• Functionality:
- Routers normally ignore datagrams containing private addresses => private 
IP addresses can be used in the organization''s intranet
- Access to the outside (the "real" Internet ) is achieved via a gate 
(mediating gateway) that rewrites the source IP addresses/destination');
INSERT INTO data VALUES ('IP Protocol - Subnets using network masks','IP Protocol - Subnets using network masks
– It appeared as a solution to the problem of IP address space`s exhaustion
– Simplify Routing
– Subnets cannot be detected externally
- Division into subnetworks will be made via the network mask(netmask): NetID bits are 1, HostID bits are 0
- Subnet identifier (SubnetID) is generally used to group computers based on physical topology
Example:
– Let’s consider the IP address: 160.0.6.7
10100000 00000000 00000110 00000111
– Network mask: 255.255.252.0 
 11111111 11111111 11111100 00000000
– Network address: 160.0.4.0
 10100000 00000000 00000100 00000000
Network address = network mask AND IP address

• Default subnet masks: 
– 255.0.0.0 - Class A
– 255.255.0.0 - Class B
- 255.255.255.0 - Class C

• Convention mark: x.x.x.x/m means that we apply an m bits 
mask to the IP specified x.x.x.x address 
• Example:
- 10.0.0.0/12 – it applies a 12-bits mask to 10.0.0.0 address, we 
select possible values for the last 20 bits (=32-12)
- 85.122.16.0/20 – it applies a 20-bit mask to 85.122.16.0 address');
INSERT INTO data VALUES ('Network Level - ICMP Protocol','ICMP – Internet Control Message Protocol
• Used to exchange control messages
• Use IP
• ICMP messages are processed by the IP software, not by the user processes
• Messages types
Message    			|  Type Description
8 Echo Request 		| Ask if a host is active
0 Echo Replay 			| "Yes, I''m active"
3 Destination Unreachable 	| The package can''t be delivered (e.g. DF is set)
5 Redirect 			| The message is not correctly routed
11 Time Exceeded 		| Time elapsed (TTL=0) <- (e.g. loop, congestions, low values for time)
… etc (RFC 792) 		| http://www.iana.org/assignments/icmp-parameters

• Used by: 
- ping command (Packet Internet Gropher)
- traceroute command
- A package with TTL=1 (1 hop) is sent
- The first router ignores the packet and sends back an ICMP message “time-to-live exceeded”
- A package with TTL=2 is sent (2 hops)
- The second router ignores the packet and sends back an ICMP message “time-to-live exceeded” 
- Repeat until it has received a response from the destination or has reached the maximum number of hops
');
INSERT INTO data VALUES ('Network Level - Address resolution','Address resolution
• IP addresses <-> hardware addresses (physical)
- The process of finding the hardware address of a host, knowing its 
IP address is called address resolution(address resolution) – ARP
protocol (RFC 826)
- ARP –broadcast protocol (each host receives a request for a 
physical address, and the answer is given by the one in question)
- The process of finding the IP address based on the hardware 
address is called reverse address resolution –RARP Protocol (RFC 
903)
	- Used to boot workstations without disks
	- BOOTP (RFC 951,1048,1084)
	- DHCP (Dynamic Host Configuration Protocol) RFC 2131,2132');
INSERT INTO data VALUES ('Network Level - IPv6','IPv6
• Context:
– Issues in IPv4 addresses world:
	• The exponential growth of the hosts` number
	• Very large routing tables
	• Complex configurations, more and more users (and increasing)
	• Failure to ensure QoS
– Pressure from mobile operators

• Objectives for a new protocol:

– Support for billions of hosts
– Reducing routing tables
– Simplifying Protocol
– Support for mobile hosts
– Compatibility with the old IP
– Support for future developments of the Internet
– RFC 2460, 2553

• Aspects:
– IPv6 addresses are 16 bytes in length - 2^128 addresses
– Note: 16 hexadecimal numbers, 2 digits each, separated by “:”
	• Example: 2001:0db8:0000:0000:0000:0000:1428:57ab
	• If one or more groups of 4 digits is 0000, the zeros may be omitted and replaced (once) with "::"
	• Example: 2001:0db8::1428:57ab
– To maintain compatibility, public IP addresses are considered a subset of IPv6 address space
– IPv4 addresses in IPv6 can be written as: 10.0.0.1 -> ::10.0.0.1 or 0:0:0:0:0:0:A00:1

• ICMPv6
– ICMP provides functions (reporting data transmission, errors, etc.) plus:
	• Neighbor Discovery(Neighbor Discovery Protocol –NDP) - Replaces the ARP
	• Multicast listener discovery(Multicast Listener Discovery) – replaces IGMP (Internet Group Management Protocol)
– Details in RFC 4443
');
-- Course 4:
INSERT INTO data VALUES ('Transport Level','Transport Level
• The most important transport layer protocols:
	- TCP (Transmission Control Protocol) – connection-oriented transport protocol; RFC 793 (1122), 1323 
	- UDP (User Datagram Protocol) – connectionless transport protocol; RFC 768

Transport entity: uses the network services level and provides services to a superior level 
TPDU (Transport Protocol Data Unit) – the data transmission unit

- Offers much more reliable services than those at the network layer (e.g. packets lost at the network layer can be detected and the situation can be fixed at the transport level)
- QoS (Quality of Service):
	• The delay in establishing the connection
	• Productivity or transfer rate 
	• Delay in transfer 
	• The residual error rate 
	• Protection 
	• Priority 
	• Resilience
- Provides logical communication between processes running on different hosts (end-to-end communication)
- (Previous Course!) Network level provides logical communication between hosts 

PORT
	- Add a new dimension of IP addresses from the network level
	- It is associated to an application (service) and not a host 
	- A process can provide more services => can use multiple ports 
	- A service can correspond to several processes
• It is a 16-bit number and can be set between 0-65535
	– 1-1024 – reserved values (well-known), 1-512 system services (IANA – Internet Assigned Number Authority: RFC 1700)
Examples: /etc/services : system services are associated with ports HTTP – 80; SMTP – 25; telnet – 23; SSH - 22.
');
INSERT INTO data VALUES ('Transport Level - General primitives','General primitives
– Allow to transport layer users (e.g. application programs) to access services
Primitive |	    TPDU        | Explanation
LISTEN    | (nothing)          | It blocks until a process tries to connect
CONNECT   | CONNECTION REQUEST | Try to establish the connection
SEND      | DATA               | Send information
RECEIVE   | (nothing)          | It blocks until it receives sent data 
DISCONNECT| DISCONNECTION REQ. | Sent by the party that wants to disconnect
');
INSERT INTO data VALUES ('Transport Level - UDP','UDP
• Connectionless transport protocol, unsafe, minimal
• Does not offer any additional quality to services
• There is no negotiation regarding receiving data or data confirmation
• Analogy: UDP – similar to post system
	- Sending a letter
	- Does not guarantee the receiving order
	- The message may be lost
	• Uses IP
• Offers communication services between processes using ports
• UDP sends packages: header (8 bytes) + content
UDP header:
UDP header is an 8-bytes fixed and simple header, while for TCP it may vary from 20 bytes to 60 bytes. The first 8 Bytes contains all necessary header information and the remaining part consist of data. UDP port number fields are each 16 bits long, therefore the range for port numbers is defined from 0 to 65535; port number 0 is reserved. Port numbers help to distinguish different user requests or processes.

1.Source Port: Source Port is a 2 Byte long field used to identify the port number of the source.
2.Destination Port: It is a 2 Byte long field, used to identify the port of the destined packet.
3.Length: Length is the length of UDP including the header and the data. It is a 16-bits field.
4.Checksum: Checksum is 2 Bytes long field. It is the 16-bit one’s complement of the one’s complement sum of the UDP header, the pseudo-header of information from the IP header, and the data, padded with zero octets at the end (if necessary) to make a multiple of two octets.

Applications of UDP:
- Used for simple request-response communication when the size of data is less and hence there is lesser concern about flow and error control.
– DNS (Domain Name System)
– RPC (Remote Procedure Call)

• What doesn’t it offer?
– flow control 
– error control
– Retransmission of an error package
• What does it offer?
– Using ports expands IP protocol for communication between processes running on different hosts (and not only between host as in the IP case) 
');
INSERT INTO data VALUES ('Transport Level - TCP','TCP - Transmission Control Protocol
• Transport connection oriented protocol without information loss
• Aimed at providing maximum quality of service
• Integrates mechanisms of establishing and releasing connections
• Controls the flow of data (stream-oriented)
• Used by many application protocols: HTTP, SMTP, TELNET, SSH ...

• Analogy: TCP – similar to telephony
	-Initiating a call
	-Dialogue between parties
	-Call ends
	
• Uses connections, not ports as fundamental abstractions
• Both parties (sender, recipient) must participate to the connection
• Connections are identified by pairs represented by IP adress :PORT (socket)
– Example: (85.122.23.146: 12345, 85.122.23.146: 22)
• One party provides a passive open - expect occurrence of connection requests; the communication partner accomplishes an active open
• A socket can be shared by multiple connections from the same machine
• TCP connections are full-duplex
• A TCP is a stream of bytes and not a message flow
	Example:
	 - The transmitter sends four fragments of 512 bytes
	 - The receiver may receive:
	 - 1. Two fragments of 1024 bytes
	 - 2. A fragment of one byte and one of 2047 bytes
	 - 3. … (any combination
	 
TCP header structure:
- Source port – The sending device’s port.
- Destination port – The receiving device’s port.
- Sequence number – A device initiating a TCP connection must choose a random initial sequence number, which is then incremented according to the number of transmitted bytes.
- Acknowledgment number – The receiving device maintains an acknowledgment number starting with zero. It increments this number according to the number of bytes received.
- Data offset – This specifies the size of the TCP header, expressed in 32-bit words. One word represents four bytes.
- Reserved data – The reserved field is always set to zero.
- Control flags – TCP uses nine control flags to manage data flow in specific situations, such as the initiating of a reset.
	– URG (URGence) (1 bit) – if it is set, the Urgent Pointer field is used
	– ACK (ACKnowledgment) 
		If it is set the Acknowledge Number field is used;
		It Is set in all acknowledgments packages
	– PSH (PuSH)– data will be transmitted immediately to the recipient`s application
	– RST (ReSeT) – signal connection errors (e.g. opening a connection is refused)
	– SYN (SYNchronize)
		• It is used to establish the connection (The request to start the connection: SYN=1, ACK=0; The answer to the request: SYN=1,ACK=1; ) 
		• Indicates the connection request and the accepted connection
	– FIN (FINish)- indicates the closing of the connection


- Window size TCP checksum – The sender generates a checksum and transmits it in every packet header. The receiving device can use the checksum to check for errors in the received header and payload.
- Urgent pointer – If URG control flag is set, this value indicates an offset from the sequence number, indicating the last urgent data byte.
- Optional data – These are optional fields for setting maximum segment sizes, selective acknowledgments and enabling window scaling for more efficient use of high-bandwidth networks.

Flow Control

General mechanism:
• Simple communication protocol: sending a package and then expect confirmation of receipt from the recipient before sending the next packet.
• If acknowledgment (ACK) is not received within a predetermined time, the packet is sent again
The problem: communication mechanism ensures safety but determines the use of only a portion of available network bandwidth
');

INSERT INTO data VALUES ('Transport Level - TCP connection management','TCP connection management
Sliding window - context:
– TCP provides a stream of bytes => sequence numbers are assigned to each byte of stream
– TCP stream is split into TCP segments; a segment (the sending and the acknowledgments) will carry sequence numbers (see slide 19)
– The window size is expressed in bytes and not the number of packages 
– The window size is determined by the receiver when the connection is established and it is variable during data transfer 
– Each ACK message will include the window size that the receiver is able to operate in the time of communication

Flow Control
• Communication protocol with sliding window:
– The sender groups packages in a buffer
– the transmitter can send packages from the window, without receiving an acknowledgment (ACK), but starts a timer (which will signal exceeding a predetermined time) for each package
– receiver must acknowledge each package received, indicating the sequence number of the last byte correctly received 
– After confirmation, the sender slides the window

Flow control using sliding window – situations
• Package 2 was lost
– the sender does not receive ACK 2, so the window remains on position 1
– receiver does not receive the package 2 and it will not confirm 3,4,5 packages
– The timer will signal that the time is elapsed and the package is retransmitted
– The receiver receives package 2 and will send a ACK 5 confirmation (sequence of 2-5 packets has been received successfully) => sliding window moves four positions after receiving ACK 5
• Package 2 reached its destination but confirmation was lost
– The transmitter does not receive ACK 2 but receives ACK 3 (all packages up to 3 successfully reached) => the sliding window moves to package 4

Sliding Windows assures:
– Safe transmission
– Better use of bandwidth => better transmission speed
– Transmission control (receiver may delay data confirmation, taking into account the free space and the windows size)

Failure detection & data retransmission
– Each segment sent contains a sequence number (Sequence Number) indicating the position of the bytes transmitted in the data stream
– The recipient checks sequence number for each segment (it is tested whether certain segments are lost, duplicated, or are not in order) and sends back a confirmation number to each segment (Acknowledgment Number specifying the sequence number of the next byte that is expected to be received
– Lost segments are detected using a timer 
– Checksums are used to detect errors

Connection Reset
– Sometimes abnormal conditions are forcing network software or applications to destroy the connection
– To reset the connection, an end-point initiate the communication ending by sending a TCP segment with RST bit set
– The other side abandons the connection without transmitting any data remained as undelivered
– Transfer in both directions is stopped, the buffers are emptied

Forcing the data transmission
– TCP data stream may be divided into segments of different sizes, different by packages handled by applications => efficient transmission
– Sometimes there are situations when data must be transmitted, without waiting for the buffers to be filled(e.g., interactive applications)
– Forcing transmission is achieved by push: PSH bit is set and force the transmission of segments, regardless of filling buffers

Closing the connection
– TCP connections are full-duplex, when an application signals that there is no data to send, TCP connection will close only one direction
• Communication partner can send a TCP segment with the FIN bit set; confirmation means that on that direction, the communication is effectively stopped;
– The connection is closed down when both directions are stopped');
INSERT INTO data VALUES ('Transport Level - TCP versus UDP','TCP versus UDP
• Both rely on IP uses ports
• Transmission unit
– TCP -> TCP Segment
– UDP -> UDP Packet
• UDP offers minimal transport services (minimum effort transmission)
• TCP provides connection-oriented, full-duplex, safe - transport streams of bytes (-> complex transmission mechanism)
• Using TCP or UDP depends on the application: e-mail, file transfer, operating in real-time multimedia transmissions in real time chat, ...
');
-- Course 5:
INSERT INTO data VALUES ('Network Communication paradigms','Network Communication paradigms
• Client/Server model
• Remote Procedure Call (RPC)
• Peer-to-Peer (P2P) mechanism – point-to-point communication');
INSERT INTO data VALUES ('Client/Server model','Client/Server model
• Server Process
– Provides network services
– Accept requests from a client process
– Performs a specific service and returns the result
• Client Process
– Initializes communication with the server
– Requests a service and expects the server''s response

• Interaction alternatives:
- Connection-oriented – based on TCP
- Connectionless – based on UDP

• Implementation:
– iterative – each client is treated at a time, sequentially
– Concurrency – the requests are processed concurrently
	• A child process for each request
	• Multiplexing 
	• Combination techniques');
INSERT INTO data VALUES ('API for network programming','API for network programming
• Necessity:
– Generic interface for programming
– Hardware and operating system independence
– Support for different communication protocols
– Support for connection-oriented communications or for connectionless communications
– Independence in address representation
– Compatibility with the common I/O services
• For programming Internet application multiple APIs can be use:
	– BSD Sockets(Berkeley System Distribution)
	– TLI (Transport Layer Interface) – AT&T, XTI (Solaris)
	– Winsock 
	– MacTCP
• Functions offered:
Specifying local and remote endpoints, initiating and accepting connections, sending and receiving data, end connection, error treatments
• TCP/IP does not include an API definition
');
INSERT INTO data VALUES ('Socket','Socket
• General facility, independent of hardware architecture, protocol and type of data transmission for communication among processes on different network machines
• Offers support to multiple family protocols:
	– UNIX domain protocol – used for local communications
	– Internet domain protocol using TCP / IP
	– Other: XNS Xerox,…
• Abstraction of an end-point at the transport level
• Uses the existing I/O programming interface (similar to files, pipes, FIFOs etc.)
• May be associated with one/multiple processes from a communication domain
• It provides an API for network programming, having multiple implementations
• From the point of view of the programmer, a socket is similar to a file descriptor; the differences occur when sockets are created or when you set control options for a socket');
INSERT INTO data VALUES ('Application programming interface based on BSD sockets','Application programming interface based on BSD sockets
Basic primitives:
• socket() – creates a new connection end-point
• bind() - attaches a local address to a socket
• listen() – allows a socket to accept connections
• accept() – blocks the caller until a connection request appears (used by TCP server)
• connect() attempt (active) to establish the connection (used by TCP client)
• send() sending data via socket
• recv() receiving data via socket
• close() releases the connection(close socket)
• shutdown() closes a socket in one direction
Other primitives:
• Data read – read() / readv() / recvfrom() / recvmsg()
• Data sent – write() / writev() / sendto() / sendmsg()
• I/O Multiplexing – select()
• Managing connection – fcntl() / ioctl() / setsockopt() / getsockopt() / getsockname() / getpeername()

');
INSERT INTO data VALUES ('Socket|Creation','Socket|Creation
socket() call system
#include <sys/types.h>
#include <sys/socket.h>
int socket (int domain, int type, int protocol)

Return value
– Success: the socket descriptor
– Error: -1
• Error reporting is done via errno variable - Constants defined in serrno.h
 -EACCES 
 -EAFNOSUPPORT
 -ENFILE 
 -ENOBUFS or ENOMEM 
 -EPROTONOSUPPORT
 -...
Example of possible combinations for the socket()’s arguments:
int socket (int domain, int type, int protocol)
Domain     |       Type        |   Protocol
AF_INET    |   SOCK_STREAM     |    TCP
           |   SOCK_DGRAM      |    UDP
           |   SOCK_RAW        |    IP
AF_INET6   |   SOCK_STREAM     |    TCP
           |   SOCK_DGRAM      |    UDP
           |   SOCK_RAW        |    IPv6
AF_LOCAL   |   SOCK_STREAM     |    Internal communication mechanism
Note: AF_LOCAL=AF_UNIX (for historical reasons)
');
INSERT INTO data VALUES ('Sockets - Observations','Sockets - Observations
• socket() allocates resources for a communication end-point, but it doesn’t state which is the addressing mechanism
• Sockets provide a generic addressing mechanism; for TCP/IP , it must be specified (IP address, port)
• Other protocols suite may use other addressing mechanisms
POSIX types:
int8_t, uint8_t, int16_t, uint16_t, int32_t, int32_t, 
u_char, u_short, u_int, u_long
• POSIX types used by sockets:
– sa_family_t –address family
– socklen_t – structure lenght
– in_addr_t –IP adress (v4) 
– in_port_t – port number
• Specifying generic addresses
struct sockaddr 
{
	sa_family_t sa_family; // Address family: AF_INET, AF_ISO,...
	char sa_data[14]; // 14 bytes – used address
}
• For IPv4 AF_INET a special structure is used: sockaddr_in
struct sockaddr_in 
{
	short int sin_family; // Address family: AF_INET
	unisgned short int sin_port; // Port (2 bytes)
	struct in_addr sin_addr;
	unsigned char sin_zero[8]; // Unused Bytes
}
struct in_addr
{
	in_addr_t s_addr; // 4 bytes for IP address
}

• The values from sokaddr_in are stored in respect to network byte order
• Conversion functions (netinet/in.h)
– uint16_t htons (uint16_t) – converting a short integer (2 bytes) from host to network;
– uint16_t ntohs (uint16_t);
– uint32_t ntohl (uint32_t) – converting a long integer (4 bytes) from network to host;
– uint32_t htonl (unit32_t);
• For IPv6 AF_INET6 sockaddr_in6 structure it is used:
struct sockaddr_in6 
{
	u_int16_t sin6_family; /* AF_INET6*/
	u_int16_t sin6_port;
	u_int32_t sin6_flowinfo;
	struct in6_addr sin6_addr;
	u_int32_t sin6_scope_id;
}
struct in6_addr
{
	unsigned char s6_addr[16];
}

Example:

// IPv4: 
struct sockaddr_in ip4addr; int s;
ip4addr.sin_family = AF_INET;
ip4addr.sin_port = htons(2510); 
inet_pton(AF_INET, "10.0.0.1", &ip4addr.sin_addr); 
s = socket(PF_INET, SOCK_STREAM, 0); 
bind(s, (struct sockaddr*)&ip4addr, sizeof (ip4addr));

// IPv6: 
struct sockaddr_in6 ip6addr; int s; 
ip6addr.sin6_family = AF_INET6; 
ip6addr.sin6_port = htons(2610); 
inet_pton(AF_INET6, "2001:db8:8714:3a90::12", &ip6addr.sin6_addr); 
s = socket(PF_INET6, SOCK_STREAM, 0); 
bind(s, (struct sockaddr*)&ip6addr, sizeof (ip6addr));

');
INSERT INTO data VALUES ('Sockets| Assigning an address','Sockets| Assigning an address
• Assigning an address to an existing socket is made with bind()
int bind ( int sockfd, const struct sockaddr *addr,int addrlen );
• It returns: 0 if successful, -1 on error 
errno variable will contain the corresponding error code: 
EACCES , EADDRINUSE, EBADF, EINVAL, ENOTSOCK,... 
Example:

#define PORT 2021 
struct sockaddr_in address;
int sd;
sd = socket (AF_INET, SOCK_STREAM, 0)) // TCP
address.sin_family = AF_INET; // establish socket family
address.sin_addr.s_addr = htonl (IPaddress); //IP address
address.sin_port = htons (PORT); //port
if (bind (sd, (struct sockaddr *) &address, sizeof (address) == -1) 
{ 
perror ("Error at bind().\\n"); 
}
• bind() uses:
– The server wants to attach a socket to a default port (to provide services via that port)
– The client wants to attach a socket to a specified port
– The client asks the operating system to assign any available port
• Normally, the client does not require attachment to a specified port
• Choose any free port: address.sin_port = htons(0);

• Choosing the IP address - bind()
– If the host has multiple IP addresses assigned?
– How to solve platform independence?
To attach a socket to your local IP address, INADDR_ANY constant will be used instead

• IP address conversion:
int inet_aton (const char *cp, struct in_addr *inp);
ASCII “x.x.x.x” -> 32 bits internal representation (network byte order)
char *inet_ntoa(struct in_addr in);
32 bits representation (network byte order)-> ASCII “x.x.x.x” 
Obs: man inet_addr

• Observations:
– ForPv6 INADDR_ANY will be replaced by IN6ADDR_ANY(netinet/in.h): serv.sin6_addr = in6addr_any;
– The conversion function for IPv6 (that can be used for IPv4) are:
	inet_pton()
	inet_ntop()
');
INSERT INTO data VALUES ('Sockets| listen()','Sockets| listen()
• Passive interaction:
– The system core will wait for connection requests directed to the address where the socket is attached 3-way handshake
– The received connections will be placed in a queue
int listen(int sockfd, int backlog);
sockfd - TCP socket attached to an address
bakclog - The number of connections in the queue
– It returns: 0 – succes, -1 - error

• Observations:
– The backlog value depends on the application (usually 5)
–HTTP servers should specify a bigger value for backlog (due the multiple requests)');
INSERT INTO data VALUES ('Sockets| accept()','Sockets| accept()
• Accepting the connections from clients
– When the application is ready to address a new connection, the system will interrogate for another connection
int accept (int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);

It returns the socket descriptor corresponding to the client end-point or -1 in an error case');
INSERT INTO data VALUES ('Sockets| connect()','Sockets| connect()
• Trying to establish a connection to the server
3-way handshake
int connect (int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen);
sockfd - Socket TCP - does not require attaching with bind(); the operating system will assign a local address (IP, port)
serv_addr - Contains server adress (IP, port)

It returns: 0 on success, -1 on erorr
');
INSERT INTO data VALUES ('I/O TCP| read()','I/O TCP| read()
int read(int sockfd, void *buf, int max);
• The call is usually a blocking one, read() returns only when data are available
• Reading from a TCP socket may return fewer bytes than the maximum number desired
– We must be prepared to read byte-by-byte at a time (see previous course)
• If the communication partner closes the connection and there are no data to receive, 0 (EOF) is returned
• Errors: EINTR – a signal interrupted the reading, EIO –I/O error, EWOULDBLOCK – the socket set in a non-blocking mode, doesn’t have data');
INSERT INTO data VALUES ('I/O TCP| write()','I/O TCP| write()
int write(int sockfd, const void *buf, int count);
• The call is usually a blocking one
• Errors: 
– EPIPE – write to a offline socket
– EWOULDBLOCK – normally writes blocks until the writing operation is complete; if the socket is set in non-blocking mode and some problems occur, it returns this error immediately
');
INSERT INTO data VALUES ('I/O TCP| Example','I/O TCP| Example
#define MAXBUF 127 /* reading buffer length*/
...
char *request= "give me something";
char buf [MAXBUF]; /* response buffer*/
char *pbuf= buf; /* buffer pointer */
int n, length = MAXBUF; /* the no. of bytes read, the no. of free bytes 
in buffer */
...
/* send the request*/
write(sd, request, strlen(request));
/* wait the response*/
while ((n = read (sd, pbuf, length)) > 0) 
{
pbuf+= n;
length -= n;
}');
INSERT INTO data VALUES ('Socket| close()','Socket| close()
int close( int sockfd)
• Effect: 
– closes the connection;
– Frees the memory associated with the socket
• for processes that share the same socket, it decreases the number of references to that socket; if it reaches 0, than the socket is deleted
• Problems:
– The server cannot end the connection, it doesn’t know if and when the client sends other demands
– The client doesn’t know if the data reaches the server');
INSERT INTO data VALUES ('Socket| shutdown()','Socket| shutdown()
• Unidirectional closing
– When a client finishes to send requests, it can call shutdown() to specify that data will be sent no longer (the socket is not deleted)
– The server will receive EOF and after sending the last answer to the client, it will close the connection
#include <sys/socket.h>
int shutdown (int sockfd, int how);
how - 	0 – future reading from the socket will not be allowed (SHUT_RD);
	1 – future writings will not be allowed (SHUT_WR);
	2 - read/write operations are no longer allowed (SHUT_RDWR);
');
INSERT INTO data VALUES ('Client/Server Model - TCP iterative server','
• TCP iterative server:
– Creates socket to address clients: socket()
– Prepares data structures (sockaddr_in) 
– Attaches the socket to the local address (port): bind()
– Prepares the socket to listen in order to establish connections with clients listen()
– The expectation of making a connection with a particular client (passive open): accept()
– Processes customer requests, using the socket returned by accept(): sequence of read()/write() calls
– Closes (unidirectional close) of the connection: close(), shutdown()
TCP client model:
– Creates a socket to connect to a server: socket()
– Prepares data structures (sockaddr_in) 
– Attaches the socket: bind() – optional
– Connects to the server (active open): connect()
– Service request/receives the results sent by the server: sequence of read()/write() calls
– Closes (unidirectional close) the connection: close(), shutdown()
');
-- Course 6:
INSERT INTO data VALUES ('UDP Client/Server model','UDP Client/Server model
• For socket() it is used SOCK_DGRAM
• listen(), accept(), connect() are not usually used
• For datagrams sending it can be used sendto() or send() 
• For datagrams reading it can be used recvfrom() or recv()
• Nobody guarantees that the sent data have reached the addressee or is not duplicate
• UDP sockets can be “connected”: the client can use connect() to specify the server address (IP, port) – pseudo-connections:
– Utility: sending several datagrams to the same server, without specifying server address for each datagram
– For UDP, connect() will retain only the information about the endpoint without getting initiate any data exchange
– Although connect() reports success does not mean that the address is a valid point or the terminal server is available
• UDP Pseudo-connections
– shutdown() can be used to stop transmitting data in one direction, but no message will be sent to the conversation partner
– close() can be called to remove a pseudo-connection
');
INSERT INTO data VALUES ('I/O primitives','I/O primitives
#include <sys/types.h>
#include <sys/socket.h>
int send (int sockfd, char *buff, int nbytes, int flags);
int recv (int sockfd, char *buff, int nbytes, int flags);
• They can be used in the connection-oriented communications or pseudo-connections
• send() and recv() assume that a previous connect() call was performed
• The first 3 arguments argumente sunt similare cu cele de la write(), respectiv read()
• The fourth argument is usually 0, but can have other values ​that specify conditions for the call
• Both calls return at normal execution, the transfer length (in bytes)

#include <sys/types.h>
#include <sys/socket.h>
int sendto ( int sockfd, char *buff, int nbytes, int flags, struct sockaddr *to, int addrlen);
int recvfrom (int sockfd, char *buff, int nbytes, int flags, struct sockaddr *from, int *addrlen);
• Used for connectionless communications
• At sendto() and recvfrom() the elemnts to identify the remote node is specified in the last two arguments
• Both calls return, in normal execution, the transfer length in bytes

#include <sys/uio.h>
 ssize_t readv (int fd, const struct iovec *iov, int iovcnt);
 ssize_t writev (int fd, const struct iovec *iov, int iovcnt);
– Wider than read()/write(), provides the ability to work with data in non-contiguous memory areas
 #include <sys/types.h>
 #include <sys/socket.h>
ssize_t recvmsg (int s, struct msghdr *msg, int flags);
ssize_t sendmsg (int s, const struct msghdr *msg, int flags);
– Receives / transmits messages extract them from the msghdr structure
');
INSERT INTO data VALUES ('Primitives','Primitives
• getpeername() – returns information about the other end of the connection
#include <sys/socket.h> 
int getpeername (int sockfd, struct sockaddr *addr,socklen_t *addrlen); 
• getsockname() – return informations over the specified socket (local) –> (address to which is attached)
#include <sys/socket.h> 
#include <sys/types.h>
int getsockname( int sockfd, struct sockaddr * addr, socklen_t * addrlen);');
INSERT INTO data VALUES ('Primitives | Options','Primitives | Options
• Options attached to sockets
– Attributes used for consulting or changing behavior, general or specific protocol for certain (types of) sockets
– Type of values:
• Boolean (flags)
• Complex types:
	int, timeval, in_addr, sock_addr, etc
• getsockopt() – options consultations
#include <sys/types.h> 
#include <sys/socket.h> 
int getsockopt (int sockfd, int level, int optname, void *optval, socklen_t *optlen);
Level - indicate if option is general or specific to a protocol
Example: 
len = sizeof (optval);
getsockopt (sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, &len);

• setsockopt() – setting options
#include <sys/types.h> 
#include <sys/socket.h> 
int setsockopt (int sockfd, int level, int optname, void *optval, socklen_t *optlen);
Returns: 0 on success,-1 on error: EBADF, ENOTSOCK, ENOPROTOOPT,...

General options:
• Independent of protocol
• Some options are supported only by certain types of sockets (SOCK_DGRAM, SOCK_STREAM)
– SO_BROADCAST
– SO_ERROR
– SO_KEEPALIVE
– SO_LINGER
– SO_RCVBUF, SO_SNDBUF
– SO_REUSEADDR
- SO_OOBINLINE
- ...

• SO_BROADCAST (boolean)
– Enable / disable sending data in broadcast mode
– Used only for SOCK_DGRAM
– Prevents not to send improperly broadcast
• SO_ERROR (int)
– Show error occurred (similar to errno)
– Can be used with getsockopt()
• SO_KEEPALIVE (boolean)
– Used for SOCK_STREAM
– A probe data will be send to the other endoint if no data has been exchange for a long time
– Used by TCP (e.g., telnet): allows processes to determine whether the corresponding process/host has failed

• SO_LINGER (struct linger)
– Controls whether and how long a call after a close will wait for confirmations (ACKs) from the terminal point
– Used only for connection-oriented sockets to ensure that a call close () will not return immediately
– Values will be like: 
struct linger 
{
int l_onoff; /* interpreted as boolean */
int l_linger; /* time in seconds*/
}
– l_onoff = 0: close() returns immediately, but unsent data is transmitted
– l_onoff !=0 and l_linger=0: close() returns immediately and any unsent data are deleted
– l_onoff!=0 and l_linger !=0: close() does not return until the unsent data is transmitted (or the connection is closed by the remote system)

• SO_LINGER – Example
int result;
struct linger lin;
lin.l_onoff=1 ; 
lin.l_linger=1; 
result= setsockopt( sockfd, SOL_SOCKET, SO_LINGER, &lin, sizeof(lin));

• SO_RCVBUF/SO_SNDBUF (int)
– Change the size of buffers for receiving or sending data
– Used for SOCK_DGRAM si SOCK_STREAM

• Example: 
int result; int buffsize = 10000;
result = setsockopt (s, SOL_SOCKET, SO_SNDBUF, &buffsize, sizeof(buffsize));

• SO_REUSEADDR – (boolean)
– Allowing connection to an adress already in use - the unique binding rule is not violated
– Used in a case in which a passive socket can use a port already in use

• If the listening daemon at 2000 port is killed, restarting the demon will fail if SO_REUSEADDR is not set

•Example:
int optval = 1;
setsockopt (sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
bind (sockfd, &sin, sizeof(sin));

Specific options for IP protocol
• IP_TOS allows to set “Type Of Service” field (e.g., ICMP) from the IP header
• IP_TTL allows to set “Time To Live” field from the IP header

There are options for IPv6.(RFC 2460,2462)
-IPV6_V6ONLY, ...

Specific options for TCP protocol:
• TCP_KEEPALIVE set waiting time if SO_KEEPALIVE is activated
• TCP_MAXSEG sets the maximum length of a segment (not all implementations allow change this value by the application)
• TCP_NODELAY disabling the Nagle algorithm (reducing the number of small packets in a network WAN, TCP always sends packets of maximum size, if possible) - used to generate small packets (e.g., interactive clients such as telnet)
');
INSERT INTO data VALUES ('I/O Multiplexing','I/O Multiplexing
• The opportunity to monitor more I/O descriptors 
– A generic TCP client (e.g., telnet)
– An interactive client (e.g., ftp, scp, Web browser ...)
– A server that can handle multiple protocols (TCP and UDP) simultaneously 
– Solving unexpected situations (i.e. fall in the middle of communication)
• Example: data read from the standard input must be written to a socket, and the data received through the network should be displayed to stdout

I/O Multiplexing | Solutions

• Using non-blocking mechanism using primitives: fcntl() / ioctl()
• Using asynchronous mechanism
• Using alarm() to interrupt slow system calls
• Use of processes/threads (multitasking)
• Using primitives that allows checking from multiple inputs: select() and poll()

• Using non-blocking mechanism using fcntl() 
– Set I/O calls as a no-blocking 
int flags; 
flags = fcntl ( sd, F_GETFL, 0 );
fcntl( sd, F_SETFL, flags | O_NONBLOCK);
– If no data are available, read() will return -1 or if there is insufficient space in the buffer write() will return -1 (with the error EAGAIN)

Using non-blocking mechanism using ioctl()
#include <sys/ioctl.h>
ioctl (sd, FIOSNBIO, &arg); -arg is a pointer to an int 
- if arg is 0, the socket is set in blocking mode
- if arg is 1, the socket is set to non-blocking mode
If the socket is in non-blocking mode, we have:
• accept() – if there is no request, accept() returns with the error EWOULDBLOCK
• connect() – if the connection can not be established immediately, connect() returns with the error EINPROGRESS
• recv() – if no data is received, recv() returns -1 with the error EWOULDBLOCK
• send() – if there is no buffer space for data to be transmitted, send() returns -1 with the error EWOULDBLOCK

Sending and receiving data asynchronously
– Problem: Given that sockets are created by default in blocking mode (I/O), how a process can be notified when "something" happens to a socket?
– asynchronous sockets allows sending a signal (SIGIO) to the process
– SIGIO signal generation is dependent on protocol

• For TCP SIGIO signal can occur when:
– The connection has been fully established 
– A disconnect request was initiated
– A disconnect request is completed
– shutdown() is called for one communication sense
– Data from the corresponding endpoint appear
– Data were send
– Error

– For UDP SIGIO signal occurs when:
• It receives a datagram
• ...
–We allow processes to carry out other activities and monitor UDP transfers

• Implementation
– Socket must be set as asynchronous 
#include <sys/unistd.h> 
#include <sys/fcntl.h> 
int fcntl (int s, int cmd, long arg)
• Example: 
int sd = socket(PF_INET, SOCK_STREAM, 0); 
fcntl (sd, F_SETFL, O_ASYNC);

• Alarms use
while(...)
{
signal (SIGALRM, alarmHandler);
alarm (MAX_TIME);
read (0,...);
signal (SIGALRM, alarmHandler);
alarm (MAX_TIME);
read (tcpsock,...);...
}

Concurrent Servers – per-client process

Pre-forked Concurrent Servers 
– It creates a number of child processes immediately at initialization and every process freely interact with a specific client 
Pre-threaded Concurrent Servers 

– There are used threads instead of processes (see POSIX threads –pthread.h)
– Example: Apache server

Problems:
– The number of clients greater than the number of processes / threads 
– Number of processes / threads too large in relation to clients number 
– OS overhead

Problems that arise:
• Using non-blocking calls, the processor is intensively used
• For alarm(), which is the optimal value MAX_TIME?');
INSERT INTO data VALUES ('I/O Multiplexing | select()','I/O Multiplexing | select()
• Allows use of blocked calls for descriptors (files, pipes, sockets,…)
• Suspend the program until descriptors from the manageed list are ready for I/O operations
#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h> 
int select (int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
nfds - The maximum value of descriptors plus 1
readfds - The set of descriptors for reading, writing, exception
timeout - waiting time

Handling the descriptors set (fd_set type) is performed using macros:

FD_ZERO (fd_set *set); Delete the descritors set.
FD_SET (int fd, fd_set *set); Add the fd descriptor in the set.
FD_CLR (int fd, fd_set *set); Delete the fd descriptor in the set.
FD_ISSET(int fd, fd_set *set); Test if the fd descriptor belongs to the set.

For waiting time the structure defined in sys/time.h is used:
struct timeval 
{
long tv_sec;/* seconds*/
long tv_usec;/* microseconds*/
}
• If timeout is NULL, select() will return immediately
• If timeout is !=0 specify the timeframe in which select() will wait

A socket descriptor is ready for reading if :
• There are bytes received in the input buffer (read() will return >0)
• A TCP connection received a FIN bit(read() return 0)
• The Socket is a listening socket and there are some connection requests (accept() can be used)
• An error occurred on the socket (read() returns –1, with errno set) – errors can be filtered via getsockopt() using SO_ERROR
A socket descriptor is ready for writing if:
– There are a number of bytes available in the writing buffer (write() will return a value > 0)
– The connection is closed in the sense of writing(attempt to write() will generate SIGPIPE)
– A writing error occurred (write() return –1,  with errno set) – errors can be filtered via getsockopt() with the SO_ERROR option
• A socket descriptor is in an exception state if:
– There are out-of-band data or socket is marked as out-of-band
– If the remote endpoint has been closed while there were data on the channel, the read/write operation will return ECONNRESET

select() may return
– The number of descriptors which are in read, write or exceptioon state
– 0 – the time has elapsed, no descriptor is ready
– –1 on error
The use of select() – general steps:
– fd_set declaration
– Initialization with FD_ZERO()
– Adding using FD_SET() of each descriptor intended to be monitored
– Calling select() primitive
– Upon returning successfully, FD_ISSET() is used for descriptors checking
');
INSERT INTO data VALUES ('BSD Sockets - Use and Critics','BSD Sockets | Use
• Internet Services (services use sockets for communication among remote hosts)
– Example of distributed applications
• World Wide Web
• Remote access to a database 
• Distribution of tasks on multiple hosts 
• On-line games
• ...
BSD Sockets | Critics
The API based on BSD sockets has a number of limitations:
– It has a high complexity, because it was designed to support multiple protocols family (but rarely used in practice)
– No portability (some calls/types has different names/representations on other platforms; filenames - antet.h depend on system)
– Example: in WinSock the descriptors are pointers, in Unix we are using Int
');
-- Course 7:
--INSERT INTO data VALUES ('','');
--INSERT INTO data VALUES ('','');
