#include "scanner.h"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

bool PortScanner::scanSinglePort(const std::string& ip, int port) {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) return false;

    u_long mode = 1;
    ioctlsocket(sock, FIONBIO, &mode);

    sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

    connect(sock, (sockaddr*)&target, sizeof(target));

    fd_set writeSet;
    FD_ZERO(&writeSet);
    FD_SET(sock, &writeSet);

    timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 200000;  

    int result = select(0, NULL, &writeSet, NULL, &timeout);

    closesocket(sock);

    return (result > 0);
}

void PortScanner::scanRange(const std::string& ip, int startPort, int endPort) {
    std::cout << "\nScanning " << ip << "...\n\n";

    for (int port = startPort; port <= endPort; port++) {
        if (scanSinglePort(ip, port)) {
            std::cout << "[OPEN] Port " << port << std::endl;
        }
    }

    std::cout << "\nScan complete.\n";
}