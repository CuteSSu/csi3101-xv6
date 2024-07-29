#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    int pid;
    int i;

    printf(1, "1. fork() 실행하여 A 프로세스 생성\n");
    // nice(-7) 으로 했을 때 우선순위 -4로 되는것 확인
    nice(-7);
    ps();
    
    // 자식프로세스 생성
    pid = fork();
    if (pid < 0) {
        printf(1, "Fork failed \n");
        exit();
    } else if (pid == 0) {
        printf(1, "child process yes \n");
        for (i = 0; i < 100000; i++);
        nice(3);
        ps();
        exit();
    } else {
       printf(1, "parent process yes\n");
       exit();
    }
}

