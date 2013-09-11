// Project name : FileChmodFuncDemo
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Aug  4 20:07:27 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int f;
    const char *f_path = "test";
    mode_t f_attrib;
    struct stat *buf = malloc(sizeof(stat));
    f_attrib = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    f = creat(f_path, f_attrib);
    if (f == -1)
    {
        puts("文件创建失败");
        return 1;
    }
    else
    {
        puts("文件创建成功");
    }
    fstat(f, buf);
    if (buf->st_mode & S_IRUSR)
    {
        puts("所有者用于读权限");
    }
    if (buf->st_mode & S_IRGRP)
    {
        puts("群组拥有读权限");
    }
    close(f);
    chmod(f_path, 0771);
    stat(f_path,  buf);

    if (buf->st_mode & S_IWUSR)
    {
        puts("所有者拥有写权限");
    }
    if (buf-<st_mode & S_IWGRP)
    {
        puts("群组拥有写权限");
    }

    free(buf);
    return 0;
}

// end 
// ism 

