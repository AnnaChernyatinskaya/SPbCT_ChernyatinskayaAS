#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

int pid0, pid1, pid2, N;
void f1(int), f2(int), f0(int);
ofstream text;

int main(){
    setlocale(LC_ALL, ".1251");
    text.open("text.txt");
    cout << "N = ";
    cin >> N;
    setpgrp();
    pid0 = getpid();
    pid1 = fork();
    if (pid1 == 0){ //первый процесс
        signal(SIGUSR2, f1);
        pid1 = getpid();
        pid2 = fork();
        if(pid2 == 0){
            pid2 = getpid();
            signal(SIGUSR2, f2);
        }
    }
    else{ //родительский процесс
        signal(SIGUSR2, SIG_IGN);
        signal(SIGUSR1, f0);
        kill(pid1, SIGUSR2);
        kill(pid2, SIGUSR2);
    }
    return 0;
}

void f1 (int signum){
    for (int i = 0; i < N; i++)
    text << "Pr1: " << i << endl;
    kill(pid0, SIGUSR1);
}

void f2 (int signum){
    for (int i = 0; i < N; i++)
    text << "Pr2: " << i << endl;
    kill(pid0, SIGUSR1);
}

void f0 (int signum){
    ifstream out("text.txt");
    string x;
    while (out) {
        out >> x;
        cout << x << endl ;
    }
}
