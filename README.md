# FTP_Project

#### 介绍
复旦大学计算机网络2022秋课程PJ

#### 软件架构
软件架构说明:
- source 文件夹下为源码区域
- port 
```c 
#define PORT_CONTROL_MESSAGE 8080
#define PORT_DATA 8000
```
- 传输约定
  - get
  - put
#### 安装教程

#### 使用说明

```bash
$ cd source
$ gcc server.c -o server
$ gcc client.c -o client
$ ./server
$ ./client
```

#### 参与贡献

1.  Fork 本仓库
2.  新建 name/develop 分支 如 yilin/develop
3.  提交代码
4.  新建 Pull Request
