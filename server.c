#include <stdio.h>
#include "ftp_def.h"
#pragma once
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>
#pragma  comment(lib,"WS2_32.lib")
#define TRUE 1
#define FALSE 0
//#define AF_INET 2

SOCKET creat_socket(int nServerPort);
int process_msg(SOCKET sAccept);

int main() {

    //启动socket库
    WSADATA wsadata;

    if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))  // 启动协议,成功返回0
    {
        printf("WSAStartup faild: %d\n", WSAGetLastError());
        system("pause");
        return -1;
    }
    printf("Server startup...\n");

    //创建套接字
    SOCKET sListen = creat_socket(PORT_CONTROL_MESSAGE);
    if (sListen == -1)
        return -1;

    SOCKET sData = creat_socket(PORT_DATA);
    if (sData == -1)
        return -1;

    // 监听客户端连接
    if (0 != listen(sListen, 10))                  // 10为队列最大数
    {
        printf("listen failed on %d", WSAGetLastError());
        return -1;
    }

    // 有客户端连接，接受连接
    struct sockaddr_in cliAddr;
    int len = sizeof(cliAddr);

    SOCKET sAccept = accept(sListen, (struct sockaddr*)&cliAddr, &len);

    if (INVALID_SOCKET == sAccept)
    {
        printf("accept failed on %d", WSAGetLastError());
        return -1;
    }

    printf("Succeed link to %s\n",inet_ntoa(cliAddr.sin_addr));

    //处理数据
    while (process_msg(sAccept)){
        Sleep(100);
    }

    //关闭socket
    if (0 != WSACleanup())
    {
        printf("WSACleanup failed in %d\n", WSAGetLastError());
        return -1;
    }
    printf("Server shutdown...\n");
    system("Pause");

    return 0;
}

SOCKET creat_socket(int nServerPort){

    SOCKET socket1 = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(INVALID_SOCKET == socket1)
    {
        //失败
        printf("Fail to create socket on %d\n",nServerPort);
        system("pause");
        return -1;
    }

    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_port=htons(nServerPort);
    addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);

    if(SOCKET_ERROR == bind(socket1,(SOCKADDR*)&addr,sizeof(addr)))
    {
        //失败
        printf("Fail to bind socket\n");
        system("pause");
        return -1;
    }

    return socket1;
}

int process_msg(SOCKET sAccept){
    char buff[BYTE_LENGTH] = {0};
    int Byte = recv(sAccept, buff, BYTE_LENGTH, 0);         // 接收

    if (SOCKET_ERROR == Byte)
    {
        printf("Receive error...%d", WSAGetLastError());
        return TRUE;
    }

    //判断指令
    if (buff[0] == 'l' && buff[1] == 's')//ls
    {

        //todo

        return TRUE;
    }else if (buff[0] == 'e')//exit
    {
        memset(buff,0, sizeof(buff));
        strcpy(buff,"Server shutdown...\n");

        if(SOCKET_ERROR == send(sAccept,buff,BYTE_LENGTH,0))
        {
            printf("Error sending msg in %d",WSAGetLastError());
        }
        return FALSE;//退出循环
    }else if (buff[0] == 'p')//put
    {

        //todo

        return TRUE;
    }

    return TRUE;
}