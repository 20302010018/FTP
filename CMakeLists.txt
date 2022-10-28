cmake_minimum_required(VERSION 3.21)
project(FTP_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(source/FTPClient)
link_libraries(ws2_32 wsock32)

add_executable(FTP_Project
        source/FTPClient/client.c
        source/FTPClient/ftp_def.h
        source/FTPServer/server.c)
