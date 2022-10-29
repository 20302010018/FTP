//
// Created by byy on 2022/10/29.
//

#ifndef FTPTEST_FILE_CLASS_H
#define FTPTEST_FILE_CLASS_H

int open_file(char* filename,char* mode);
unsigned int write_to_file(char *buff,int size);
unsigned int read_from_file(char* buff,int size);
void close_file();

#endif //FTPTEST_FILE_CLASS_H
