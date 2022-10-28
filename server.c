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
SOCKET listen_and_connect(SOCKET sPort);
int process_msg(SOCKET sCliControl, SOCKET sData);

int main() {

    // 启动socket库
    WSADATA wsadata;

    if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))  // 启动协议,成功返回0
    {
        printf("WSAStartup faild: %d\n", WSAGetLastError());
        system("pause");
        return -1;
    }
    printf("Server startup...\n");

    while(1){//服务器始终保持开启
        // 创建本地端口套接字
        SOCKET sControl = creat_socket(PORT_CONTROL_MESSAGE);//指令接发端口
        if (sControl == SOCKET_ERROR)
            break;

        SOCKET sData = creat_socket(PORT_DATA);//数据接发端口
        if (sData == SOCKET_ERROR)
            break;

        // PORT CONTROL端口监听并连接
        SOCKET sCliControl = listen_and_connect(sControl);

        // 处理数据
        while (process_msg(sCliControl,sData)){
            Sleep(100);
        }

    }

    // 关闭socket
    if (0 != WSACleanup())
    {
        printf("WSACleanup failed in %d\n", WSAGetLastError());
        system("pause");
        return -1;
    }
    printf("Server shutdown...\n");
    system("pause");

    return 0;
}

SOCKET creat_socket(int nServerPort){

    SOCKET socket1 = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(INVALID_SOCKET == socket1)
    {
        //失败
        printf("Fail to create socket on %d\n",nServerPort);
        system("pause");
        return SOCKET_ERROR;
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
        return SOCKET_ERROR;
    }

    return socket1;
}

SOCKET listen_and_connect(SOCKET sPort){
    // 监听客户端连接
    if (0 != listen(sPort, 10))                  // 10为队列最大数
    {
        printf("listen failed on %d", WSAGetLastError());
        return SOCKET_ERROR;
    }

    // 有客户端连接，接受连接
    struct sockaddr_in cliAddr;
    int len = sizeof(cliAddr);

    SOCKET sAccept = accept(sPort, (struct sockaddr*)&cliAddr, &len);

    if (INVALID_SOCKET == sAccept)
    {
        printf("accept failed on %d", WSAGetLastError());
        return SOCKET_ERROR;
    }

    printf("Succeed link to %s\n",inet_ntoa(cliAddr.sin_addr));

    return sAccept;
}

int process_msg(SOCKET sCliControl, SOCKET sData){
    char buff[BYTE_LENGTH] = {0};
    int Byte = recv(sCliControl, buff, BYTE_LENGTH, 0);  // 接收指令内容

    if (SOCKET_ERROR == Byte)
    {
        printf("Receive error...%d", WSAGetLastError());
        return TRUE;
    }


    // 判断指令
    if (buff[0] == 'l' && buff[1] == 's')//**************   ls
    {
        SOCKET sCliData = listen_and_connect(sData);// PORT DATA端口监听并连接

        /**
        TODO
        */

        closesocket(sCliData);
        return TRUE;

    }else if (buff[0] == 'e')//**************************   exit
    {
        memset(buff,0, sizeof(buff));
        strcpy(buff,"Connect close...\n");

        if(SOCKET_ERROR == send(sCliControl,buff,BYTE_LENGTH,0))
        {
            printf("Error sending msg in %d",WSAGetLastError());
        }

        closesocket(sCliControl);//关闭本次连接
        closesocket(sData);
        return FALSE;//退出循环

    }else if (buff[0] == 'p')//**************************   put
    {
        SOCKET sCliData = listen_and_connect(sData);// PORT DATA端口监听并连接

        /**
        TODO
        */

        closesocket(sCliData);
        return TRUE;

    }else
        return TRUE;

    return TRUE;
}