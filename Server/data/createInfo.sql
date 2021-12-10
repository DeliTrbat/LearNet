CREATE TABLE IF NOT EXISTS courses (no INT NOT NULL, data VARCHAR(50000));

INSERT INTO courses VALUES (1,'Network Architecture

Content

Structure of Computer Networks
- Network Architecture Models (OSI,TCP/IP)
- TCP/IP Model
- ISO/OSI versus TCP/IP

Computers Networks Structure

Computer Network Structure - stack levels

Functionality:

- Interface: ensure communication between two
consecutive levels
- Service: functionality provided by a level
Result: reducing design complexity

The principle of communication: transmitter sends at n
level what the recipient receives at the n level

- Protocol - Rules and conventions through which the
communication takes place

Aspects regarding levels designs

Services types
- Connection-oriented
- Communication requires a connection
- Similar to a telephone service
- Connectionless
- Communication does not require a connection
- Similar to postal service

Network architecture: the set of levels and protocols
- Architecture specification must provide sufficient
information for programs or equipment intended, in
order to offer the specific protocols
- Protocols stack: list of protocols (on all levels) used by a
particular system

Each level must identify transmitters & receivers
through an addressing mechanism
- Data transfer rules identification
- simplex communication
- Example: TV
- half-duplex communication
- Example: "walkie-talkie"
- full-duplex communication
- Example: telephone

In general, communication channels do not preserve the order
of the sent messages => need for a protocol that provides a
mechanism to reconstruct the correct messages order
- Sometimes the receiver cannot manage the variable length
messages => it must be a mechanism to divide/assemble
- High costs in the allocation of separate connections? =>
Multiplexing - use the same connection for independent
conversations
- In general, there are several ways between source and
destination => routing mechanism
- Physical communication circuits are not perfect => it asks for an
error control mechanism

Reference models for network architecture
- ISO/OSI (International Standard Organization/ Open
System Interconnection)
- TCP/IP (Transmission Control Protocol/ Internet
Protocol)

OSI Model- motivation

The need for a different level of abstraction => to create a new level
- Obs. The number of levels must be optimal, therefore each
level has different functions and the whole architecture is
functional
- A level has a clear role; a level function must take into account
protocols that are standardized at international level
- Minimizing the flow of information between levels is accomplished
through good boundary levels => Levels can be modified and
implemented independently
- Each level offers services for superior level (using services from
previous levels)
- “peer” levels of different systems communicate via a protocol');

INSERT INTO courses VALUES (2,' ');
