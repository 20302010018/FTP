#include<stdio.h>
#include<dirent.h>
#include<unistd.h>

int main(){
    char buff[1024];
    getcwd(buff,1024);
    printf("%s\n",buff);
    chdir("file");
    getcwd(buff,1024);
    printf("%s\n",buff);
    return 0;
}