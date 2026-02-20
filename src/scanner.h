#ifndef SCANNER_H
#define SCANNER_H

#include <string>

class PortScanner {
public:
    void scanRange(const std::string& ip, int startPort, int endPort);

private:
    bool scanSinglePort(const std::string& ip, int port);
};

#endif