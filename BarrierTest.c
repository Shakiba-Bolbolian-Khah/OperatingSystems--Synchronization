#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
barrierTest()
{
    printf(1,"BarrierTest: Initializing barrier!\n");
    initBarrier(5);
    int pid;
    int parPid = getpid();
    for(int i = 0; i< 5; i++){
        if((pid = fork())==0){
            sleep(i*20+2);
            printf(1,"Process child number %d slept for %d seconds, stopped before barrier!\n", i, i*20+2);
            barrier();
            sleep(i*20+2);
            printf(1,"Process child number %d after barrier! Process slept for %d ms\n", i,20*i+2);
            break;
        }
    }
    if(getpid() == parPid){ 
        for(int i =0; i< 5; i++){
            wait();
        }
    }
    return;

}

int
main(int argc, char *argv[])
{
    if(argc > 1){
        printf(1, "BarrierTest: Invalid Num Of Arguments!\n");
        exit();
    }

    barrierTest();
    exit();
}
