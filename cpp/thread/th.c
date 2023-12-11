/*
在C语言中使用 多线程thread 
    需要使用 <pthread.h> 头文件
    定义一个 pthread_t 类型的结构对象
    调用 pthread_create() 即可启动该线程

同步和互斥
互斥相关函数：
    pthread_mutex_init()
    pthread_mutex_destroy()
    pthread_mutex_lock()
    pthread_mutex_trylock()
    pthread_mutex_unlock()
条件变量（同步）
    pthread_cond_init()
    pthread_cond_destroy()
    pthread_cond_wait()
    pthread_cond_signal()
    pthread_cond_broadcast()

编译 无需额外参数
    gcc 
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* 线程数量 */
#define THREAD_NUMBER 10

/* 全局变量， 计数器*/
int counter = 0;

/* 线程执行的函数 */
void *thread_print(void *tid)
{
    printf("This is thread: %d, counter: %d\n", *((int *)tid), counter);
    ++counter;
    pthread_exit(0);
}
int main()
{
    /* 定义线程数组 */
    pthread_t td[THREAD_NUMBER];
    int i, status;

    for (i = 0; i < THREAD_NUMBER; ++i)
    {
        printf("Main function. Attempting to creat thread: %d\n", i);

        /* 建立线程，马上执行*/
        status = pthread_create(&td[i], NULL, thread_print, (void *)(&i));
        if (status != 0)
            printf("Pthread_create return error, code: %d\n", status);
    }
    exit(0);
}

