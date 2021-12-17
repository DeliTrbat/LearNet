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
transmission (loss, multiplier,…)');

--INSERT INTO data VALUES ('IP – Internet Protocol','IP Protocol
--• IP protocol is used for autonomous systems (AS - Autonomous 
--Systems) in order to interconnect.
--• IPv4 Datagram

