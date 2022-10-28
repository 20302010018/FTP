#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT_CONTROL_MESSAGE 20
#define PORT_DATA 21

int server(){
    WSADATA wsaData; //用于填充套接字库版本的有关信息

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed");
        return -1;

    }

    SOCKET sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);// 创建套接字

    if (sock_fd == INVALID_SOCKET) {
        printf("socket");
    }
    printf("server success");

    struct sockaddr_in control_port;
    control_port.sin_family = AF_INET;
    control_port.sin_port = htons(PORT_CONTROL_MESSAGE);
    control_port.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if(bind(sock_fd,(const struct sockaddr*)&control_port,sizeof(control_port))==SOCKET_ERROR){
        printf("bind error");
    }
    if(listen(sock_fd,SOMAXCONN) == SOCKET_ERROR){
        printf("error");
    }

    struct sockaddr_in client;
    int len = sizeof(client);
    SOCKET socket_client = accept(sock_fd,(struct sockaddr*)&client,&len);

    char buf1[1024];
    printf("scanf any word\n");
    scanf("%s",buf1);
    send(socket_client,buf1,sizeof(buf1),0);
    closesocket(socket_client);
    closesocket(sock_fd);


}