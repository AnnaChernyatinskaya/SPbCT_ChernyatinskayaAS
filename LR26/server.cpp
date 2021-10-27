#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#define NAME "sfifo.cc"
using namespace std;
int main()
{ char text[100];
FILE* p;
int fd;
if((fd=open(NAME, O_WRONLY))==-1) {
perror("Ошибка открытия клиента");
 return 1;
}
p = popen("ps", "r");
while (!feof(p))
    if ( fgets(text, 100 , p) != NULL ) write(fd, text, strlen(text));
write(fd, "exit", 5);
fclose(p);
close(fd);
return 0;
} 