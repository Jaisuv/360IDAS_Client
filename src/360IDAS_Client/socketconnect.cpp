#include "socketconnect.h"
#include <QMessageBox>

SocketConnect* SocketConnect::sc=nullptr;

//构造函数
SocketConnect::SocketConnect()
{
    this->socketfd = socket(AF_INET,SOCK_STREAM,0); //创建套接字描述符
    this->len=sizeof (struct sockaddr_in);  //地址的长度
}

string SocketConnect::getIPAddr() const
{
    return IPAddr;
}

void SocketConnect::setIPAddr(const string &value)
{
    IPAddr = value;
}

int SocketConnect::getPortNum() const
{
    return portNum;
}

void SocketConnect::setPortNum(int value)
{
    portNum = value;
}

//获取单例
SocketConnect *SocketConnect::getInstance()
{
    if(SocketConnect::sc == nullptr)
    {
        SocketConnect::sc = new SocketConnect();
    }
    return SocketConnect::sc;
}

void SocketConnect::createConnect()
{
    if(socketfd == -1)
    {
        perror("socket error1");
    }
    else
    {
        this->sockAddrIn.sin_family= AF_INET; //IPv4协议族
        this->sockAddrIn.sin_port=htons(this->portNum); //端口号
        this->sockAddrIn.sin_addr.s_addr=inet_addr(this->IPAddr.c_str());//服务器的IP地址

        if(::connect(socketfd,(const sockaddr*)&sockAddrIn,len) == -1 )
        {
            /*************************************************************
            if (errno == EINPROGRESS)
            {
               // 连接正在建立中
               fd_set writefds;
               FD_ZERO(&writefds);
               FD_SET(socketfd, &writefds);
               struct timeval tv;
               tv.tv_sec = 5;  // 设置超时时间为5秒
               tv.tv_usec = 0;
               if (select(socketfd + 1, NULL, &writefds, NULL, &tv) > 0)
               {
                   // 连接成功建立
               }
               else
               {
                   // 连接超时或失败
                   perror("connect error2");
                   QMessageBox::warning(nullptr,"连接提示","连接失败！");
                   exit(1);//连接失败直接退出程序
               }
            }
            else
            {
               // 其他错误
               perror("connect error2");
               QMessageBox::warning(nullptr,"连接提示","连接失败！");
               exit(1);//连接失败直接退出程序
           }
            ************************************************************/
            perror("connect error2");
            QMessageBox::warning(nullptr,"连接提示","连接失败！");
            exit(1);//连接失败直接退出程序
        }

    }
}

void SocketConnect::CloseConnect()
{
    if(socketfd==-1)
    {
        perror("socket error..");
    }
    else
    {
        close(socketfd);
    }
}

int SocketConnect::getSocketfd() const
{
    return socketfd;
}
