#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>

int main(){
    int pid;
    pid = fork();
    if(pid == 0){
        printf("SOY EL HIJO\n");
        printf("PID HIJO: %d\n", getpid());
       for(int i=1;i<=50;i++){
            sleep(1);
            printf("%d HIJO \n", i);
        }
    }
    
    else{
        printf("SOY PADRE\n");
        printf("PID PADRE: %d\n", getpid());

       for(int i=1;i<=30;i++){
            sleep(2);
            printf("%d PADRE\n", i);
        }
        wait(NULL);
    }
    return 0;
}