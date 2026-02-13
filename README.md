# MULTI_CLI_SERV
A Multiple Client-Server chat using Networking and System design concepts

Multi-client TCP Socket Server (Using C)

- Supports TCP client-server communication
- Handles multiple clients via process-based concurrency (`fork()`)
 
Demonstrates:
  - Socket lifecycle (`socket → bind → listen → accept → read → write → close`)
  - Descriptor handling

Concepts learnt :

- TCP Socket Programming
- Types of Networking Systems
- Process based concurrency
- File Descriptor Management
- How read() and write() work
- Usage of htons()
- Process Lifecycle

Future Modifications :

- Better message protocol instead of raw strings
- Logging / error handling cleanup
- Facilitate input for client's Name 

System Calls Used :

- fork() — create child process for each client
- exit() — terminate process
- read() — receive data from socket
- write() — send data to socket
- close() — release file descriptors
- socket() — create communication endpoint
- bind() — attach socket to address/port
- listen() — enable incoming connections
- accept() — accept client connection
- connect() — client-side connection to server
- gethostbyname() — resolve hostname

Build:
gcc server.c -o server
gcc client.c -o client

Run:
./server 5000
./client localhost 5000
