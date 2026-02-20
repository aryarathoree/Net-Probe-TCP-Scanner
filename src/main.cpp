#include <iostream>
#include <winsock2.h>
#include "scanner.h"

int main() {
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "WSAStartup failed.\n";
        return 1;
    }

    std::string targetIP;
    int startPort, endPort;

    std::cout << "Enter target IP: ";
    std::cin >> targetIP;

    std::cout << "Enter start port: ";
    std::cin >> startPort;

    std::cout << "Enter end port: ";
    std::cin >> endPort;

    PortScanner scanner;
    scanner.scanRange(targetIP, startPort, endPort);

    WSACleanup();
    return 0;
}