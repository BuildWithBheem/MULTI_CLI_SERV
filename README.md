# MULTI_CLI_SERV
A Multiple Client-Server chat using Networking and System design concepts

Multi-client TCP Socket Server (C)

This project demonstrates:
- TCP client-server communication
- Process-based concurrency using fork()
- Linux socket programming fundamentals

Build:
gcc server.c -o server
gcc client.c -o client

Run:
./server 5000
./client localhost 5000
