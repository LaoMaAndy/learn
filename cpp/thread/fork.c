/*
C语言 多进程 process
头文件 <unistd.h>, <sys/wait.h>
函数
    fork()
    wait()
    signal()
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int x = 1;
    int j;

    pid = fork();
    if (pid == 0)
    {
        x += 1;
        printf("Child: x = %d\n", x);
        printf("This is from child\n");
        for (j = 0; j < 5; ++j) 
            printf("%c \n", 'k');
        _exit(0);
    }
    x -= 1;
    printf("Parent: x = %d\n", x);
    printf("PID size: %lu\n", sizeof(pid));
    printf("PID value: %X\n", pid);
    for (j = 0; j < 5; ++j)
        printf("%c \n", '0');
    return 0;
    //int status;
    // (void)waitpid(pid, &status, 0);

}