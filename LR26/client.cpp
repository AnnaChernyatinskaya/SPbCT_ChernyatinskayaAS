#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#define NAME "sfifo.cc"
using namespace std;

int main()
{ 
    setlocale(LC_ALL, ".1251");
    int fd; char buf[100]; 
unlink(NAME);
if(mkfifo(NAME, S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO))
{ perror("Ошибка FIFO"); return 1;
}
if((fd=open(NAME, O_RDONLY))==-1)
{ perror("Ошибка открытия файла сервера");
}
cout<<"Получено->"<<endl;
read(fd, buf, sizeof(buf));
do{
cout << buf; 
read(fd, buf, sizeof(buf));
} while (string(buf).find("exit") == -1);
close(fd);
unlink(NAME); return 0; }