# NetProbe - TCP Port Scanner (C++ | Winsock)

## Overview

NetProbe is a TCP-based port scanner developed in C++ using the Windows Winsock API.  
The application performs connection-based scanning to detect open TCP ports on a target host within a user-specified port range.

This project demonstrates practical knowledge of:

- TCP/IP networking fundamentals  
- Socket programming using Winsock2  
- Non-blocking I/O  
- Timeout handling with `select()`  
- Modular object-oriented C++ design  

The scanner performs a TCP connect scan by attempting to establish a full TCP handshake with each port.

---

## Features

- TCP connect-based port scanning  
- Non-blocking socket configuration  
- Timeout-controlled connection attempts  
- Class-based modular architecture  
- Custom port range scanning  
- Windows-compatible implementation  

---

## Project Structure

NetProbe-TCP-Scanner/

├── src/  
│   ├── main.cpp  
│   ├── scanner.cpp  
│   ├── scanner.h  

├── build/  

└── README.md  

---

## How It Works

For each port in the specified range:

1. A TCP socket is created using Winsock.
2. The socket is set to non-blocking mode.
3. A connection attempt is initiated using `connect()`.
4. The `select()` function is used with a timeout to determine whether the connection succeeds.
5. If the socket becomes writable within the timeout period, the port is considered open.
6. The socket is closed and the scan proceeds to the next port.

This approach reduces blocking delays and improves scanning efficiency compared to simple blocking connect calls.

---

## Compilation (MinGW)

From the project root directory:

g++ src/main.cpp src/scanner.cpp -o build/scanner.exe -lws2_32

Run the executable:

build\scanner.exe

---

## Usage

Example input:

Enter target IP: 127.0.0.1  
Enter start port: 1  
Enter end port: 100  

Example output:

Scanning 127.0.0.1...

[OPEN] Port 8000

Scan complete.

---

## Networking Concepts Demonstrated

- TCP three-way handshake  
- Open vs closed port behavior  
- Blocking vs non-blocking sockets  
- Timeout-based connection handling  
- Windows Socket API (Winsock2)  
- Connection-oriented scanning logic  

---

## Limitations

- Performs TCP connect scanning (not SYN scan).
- Sequential scanning (single-threaded).
- Does not perform service detection or banner grabbing.
