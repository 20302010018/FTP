//
// Created by byy on 2022/10/29.
//

#include <stdio.h>
#include <string.h>
#include <io.h>

static FILE* this_file = NULL;
static int is_open = 0;

int open_file(char* filename,char* mode){
    if(is_open >0){
        return 0;
    }
    is_open = 1;
    this_file = fopen(filename,mode);
    if(this_file == NULL){
        return 0;
    } else{
        return 1;
    }
}

unsigned int write_to_file(char *buff,int size){
    return fwrite(buff,sizeof(char),size,this_file);
}

unsigned int read_from_file(char* buff,int size){
    return fread(buff,sizeof(char),size,this_file);
}

void close_file(){
    fclose(this_file);
    is_open = 0;
}

