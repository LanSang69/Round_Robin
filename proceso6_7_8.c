#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>

int main(){
    int pid1;
    pid1 = fork();
    if(pid1 == 0){
        printf("SOY EL HIJO 1\n");
        printf("PID HIJO 1: %d\n", getpid());
       for(int i=1;i<=50;i++){
            sleep(1);
            printf("%d HIJO 1\n", i);
        }
    }
    
    else{
       int pid2 = fork();
        if(pid2==0){
            printf("SOY EL HIJO 2\n");
            printf("PID HIJO 2: %d\n", getpid());
            for(int i=1;i<=50;i++){
                    sleep(1);
                    printf("%d HIJO 2 \n", i);
                }
        }else{
            printf("SOY PADRE\n");
            printf("PID PADRE: %d\n", getpid());

            for(int i=1;i<=30;i++){
                    sleep(2);
                    printf("%d PADRE\n", i);
                }
                for(int i=0;i<2;i++)
                    wait(NULL);
        }
    }
    return 0;
}