/*#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include<sys/types.h>
#include <fcntl.h>
#include<./ftp_def.h>

int sock_con = 0, sock_data = 0;
struct sockaddr_in serv_addr_con, serv_addr_data;
int createSocket(const int net_protocol, const int trans_protocol, const int ip, 
                 const int port, struct sockaddr_in* serv_addr);
void command_help();
void command_quit();
int command_ls();
int command_get(char* command);
int command_put(char* command);
int command_cd(char* command);
int command_pwd();

int createSocket(const int net_protocol, const int trans_protocol, const int ip, 
                 const int port, struct sockaddr_in* serv_addr){
    int sock = 0;
    
	if ((sock = socket(net_protocol, trans_protocol, ip)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

    serv_addr->sin_family = net_protocol;
	serv_addr->sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(net_protocol, "127.0.0.1", &(serv_addr->sin_addr))<= 0) {
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
    return sock;
}

int createSocketFd(int sock, struct sockaddr_in serv_addr){
    int client_fd;
    client_fd = connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
    if ( client_fd < 0) {
		printf("\nConnection Failed \n");
		return -1;
	}else{
        printf("Connected to server...");
    }
    return client_fd;
}

void command_help(){
    printf("****************** user help ******************\n");
    printf("*\n");
    printf("* 'help': get user help\n");
    printf("*\n");
    printf("* 'get [remote filename]': copy file from remote to local directory\n");
    printf("*\n");
    printf("* 'put [local  filename]': copy file from local to remote directory\n");
    printf("*\n");
    printf("* 'ls': list the files and subdirectories in the remote directory\n");
    printf("*\n");
    printf("* 'cd [path]': change working directory to [path]\n");
    printf("*\n");
    printf("* 'pwd': print current working directory\n");
    printf("*\n");
    printf("* 'quit': terminate ftp session.\n");
    printf("*\n");
    printf("****************** end help ******************\n");
}

void command_quit(){
    printf("Bye!\n");
}

int command_ls(){
    int ls_msg, client_fd_con, client_fd_data;
	char buffer[BYTE_LENGTH] = { 0 };
    
    // Connect to server
    if ((client_fd_con = createSocketFd(sock_con, serv_addr_con)) < 0){
        return -1;
    } 
    if ((client_fd_data = createSocketFd(sock_data, serv_addr_data)) < 0){
        close(client_fd_con);
        return -1;
    } 

    // Communicate with server:

    //send message from control port
    if (send(sock_con, LS, strlen(LS), 0) < 0){
        printf("send: error.\n");
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }
	printf("ls message sent\n");

    //read message from data port
	if ((ls_msg = read(sock_data, buffer, BYTE_LENGTH)) < 0){
        printf("read: error.\n");
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }
	printf("%s\n", buffer);

    // Closing the connected socket fd
	close(client_fd_con);
    close(client_fd_data);
    return 0;
}

int command_get(char* command){
    int client_fd_con, client_fd_data, bytes;
    char* filename;
	char buffer[BYTE_LENGTH] = { 0 };
    
    // Connect to server
    if ((client_fd_con = createSocketFd(sock_con, serv_addr_con)) < 0){
        return -1;
    } 
    if ((client_fd_data = createSocketFd(sock_data, serv_addr_data)) < 0){
        close(client_fd_con);
        return -1;
    } 

    // Communicate with server:

    //send message from control port
    if ( send(sock_con, command, strlen(command), 0) < 0 ){
        printf("send: error.\n");
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }
	printf("get message sent\n");

    //read message from data port
    if( (bytes = read(sock_con, buffer, BYTE_LENGTH)) < 0){
        printf("read: error.\n");
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }
    if( strcmp(buffer,FAILED) == 0){
        printf("Can not %s from server.\n",command);
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }

    printf("get filename : [ %s ]\n",filename);
    bzero(&buffer, sizeof(buffer));
    
    int fd = 0;
    if((fd=open(command+4, O_WRONLY|O_CREAT|O_TRUNC, 0644)) < 0){
        printf("Open Error!\n");
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }

    while ((bytes = read(sock_data, buffer, BYTE_LENGTH)) > 0){
        
        if(write(fd, buffer, bytes) < 0){
            printf("write local file: error.\n");
            close(client_fd_con);
            close(client_fd_data);
            return -1;
        }

    }
    if(bytes < 0){
        printf("read: error.\n");
    }
    // Close the socket fd and file fd
    close(fd);
	close(client_fd_con);
    close(client_fd_data);
    return 0;
}

int command_put(char* command){
    int client_fd_con, client_fd_data, bytes;
    char* filename;
	char buffer[BYTE_LENGTH] = { 0 };
    
    // Connect to server
    if ((client_fd_con = createSocketFd(sock_con, serv_addr_con)) < 0){
        return -1;
    } 
    if ((client_fd_data = createSocketFd(sock_data, serv_addr_data)) < 0){
        close(client_fd_con);
        return -1;
    } 

    // Communicate with server:

    //send message from control port
    if ( send(sock_con, command, strlen(command), 0) < 0 ){
        printf("send: error.\n");
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }
	printf("put message sent\n");

    int fd;
    //read file (read-only)
    if((fd=open(command+4, O_RDONLY)) < 0){
        printf("Open Error!\n");
        close(client_fd_con);
        close(client_fd_data);
        return -1;
    }

    //sent file conten to server
    while((bytes=read(fd, buffer, BYTE_LENGTH)) > 0){
        if(write(client_fd_data, buffer, bytes) < 0){
            printf("write: error!\n");
        }
    }

    //close connection and fd
    close(fd);
    close(client_fd_con);
    close(client_fd_data);
    return 0;
}

int main(int argc, char const* argv[])
{
    // Create socket connection:
    // AF_INET: IPV4
    // SOCK_STREAM: TCP
    // 0:Protocol value for Internet Protocol(IP)
	if((sock_con = 
        createSocket(AF_INET, SOCK_STREAM, 0, PORT_CONTROL_MESSAGE, &serv_addr_con)) < 0){
        printf("socket creation failed\n");
        return -1;
    }

    if((sock_data = 
        createSocket(AF_INET, SOCK_STREAM, 0, PORT_DATA, &serv_addr_data)) < 0){
        printf("socket creation failed\n");
        return -1;
    }

    // Interact with user
    char user_command[N];
    while(1){
        printf("ftp>");
        if (fgets(user_command,N,stdin) == NULL){
            printf("Fgets: read error\n");
            return -1;
        }
        user_command[strlen(user_command)-1] = '\0'; // repalce the '\n' to '\0'`
        printf("this is your command: <%s>\n",user_command);
        
        if (strcmp(user_command,HELP) == 0){
            command_help();
        } else if (strcmp(user_command,QUIT) == 0){
            command_quit();
            break;
        } else if (strcmp(user_command,LS) == 0){
            command_ls();
        } else if (strncmp(user_command, GET, 3) == 0 
                    && strlen(user_command) > 3 
                    && (user_command[3] == ' ' ||user_command[3] == '\t')){
            command_get(user_command);
        } else if (strncmp(user_command,PUT, 3) == 0
                    && strlen(user_command) > 3 
                    && (user_command[3] == ' ' ||user_command[3] == '\t')){
            command_put(user_command);
        } else if (strncmp(user_command,CD, 2) == 0
                    && strlen(user_command) > 2 
                    && (user_command[2] == ' ' ||user_command[2] == '\t')){
            printf("cd function not finish yet.");
            continue;
            command_cd(user_command);
        }else if (strcmp(user_command,PWD) == 0){
            printf("pwd function not finish yet.");
            continue;
            command_pwd();
        }else{
            printf("Command <%s> not found.\n",user_command);
        }
    }
	return 0;
}*/