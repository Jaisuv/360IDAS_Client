//网络连接单例类
#ifndef SOCKETCONNECT_H
#define SOCKETCONNECT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <QMessageBox>
#include <fcntl.h>
using namespace std;

class SocketConnect
{
public:
    static SocketConnect* getInstance();
    void createConnect();
    void CloseConnect();

    int getSocketfd() const;

    //端口号的获取与设置
    int getPortNum() const;
    void setPortNum(int value);

    //IP地址的获取和设置
    string getIPAddr() const;
    void setIPAddr(const string &value);

private:
    SocketConnect();
    static SocketConnect* sc;
    struct sockaddr_in sockAddrIn;
    int socketfd;
    int len;

    unsigned short portNum;
    string IPAddr;

};

#endif // SOCKETCONNECT_H
