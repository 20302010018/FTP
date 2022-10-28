//
// Created by byy on 2022/10/28.
//

#include <stdio.h>
#include "server.h"
#include <windows.h>
#include <io.h>

int main() {
	//SetConsoleOutputCP(65001);
	/*printf("Hello, World!\n");
	char buff[1024];
	GetCurrentDirectory(1024, buff);
	printf("%s\n", buff);
	struct _finddata_t fileInfo;
	intptr_t hFile = _findfirst(strcat(buff, "\\*"), &fileInfo);

	if (hFile == -1) {
		return -1;
	}

	do {
		printf("%s %lu\n", fileInfo.name, fileInfo.size);

	} while (_findnext(hFile, &fileInfo) == 0);

	GetCurrentDirectory(1024, buff);
	char *fileName = strcat(buff, "\\1.docx");
	FILE *readfile = fopen(fileName, "rb");
	GetCurrentDirectory(1024, buff);
	char *fileName_write = strcat(buff, "\\2.docx");
	FILE *writefile = fopen(fileName_write, "wb+");
	char buff1[1024];

	while (fread(buff1, sizeof(char), 1024, readfile)) {
		fwrite(buff1, sizeof(char), 1024, writefile);
	}

	fclose(readfile);
	fclose(writefile);
	printf("中文捏");

	if (access("mkdir", 0) == 0) {
		mkdir("mkdir1");
	} else {
		mkdir("中文中文");
	}

	getcwd(buff, 1024);
	printf("%s\n", buff);
	chdir("中文中文");
	//chdir("D:\\往年课件\\大三??);
	getcwd(buff, 1024);
	printf("%s\n", buff);


	chdir("D:\\");
	getcwd(buff, 1024);
	hFile = _findfirst(strcat(buff, "\\*"), &fileInfo);

	if (hFile == -1) {
		return -1;
	}

	do {
		printf("%s %lu\n", fileInfo.name, fileInfo.size);

	} while (_findnext(hFile, &fileInfo) == 0);*/


	server();
	return 0;
}