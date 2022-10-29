cmake_minimum_required(VERSION 3.21)
project(FTPtest)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)

add_executable(FTPtest server.c ftp_def.h file/ls.c file/ls.h file/file_class.c file/file_class.h)
