//
// Created by byy on 2022/10/29.
//

#include <io.h>
#include<string.h>

char* ls(char* buff,int length){
    getcwd(buff,length);
    struct _finddata_t fileInfo;
    intptr_t hFile=_findfirst(strcat(buff,"\\*"),&fileInfo);
    unsigned int now_length = 0;
    if (hFile == -1) {
        return strcat(buff,"the path not exist!");
    }do{
        now_length+=(strlen(fileInfo.name)+1);//length of buff ++ (fileInfo.name+\n)
        if(now_length>=length){
            buff = "The buffer length is too short, and the array is out of bounds";
            break;
        }
        strcat(buff,fileInfo.name);//printf("%s %lu\n",fileInfo.name,fileInfo.size);
        strcat(buff,"\n");
    } while (_findnext(hFile,&fileInfo)==0);
    return buff;
}
