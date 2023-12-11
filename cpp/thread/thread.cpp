// C++ 多线程
/*
编译参数
    c++ -std=c++11 -pthread
头文件
    <thread>
    <mutex>
    <condition_variable>
    <atomic>
    <future>

建立线程
    thread t(func)
    t.join()

合并执行、分离执行
    t.join()   t.detach()
*/
#include <iostream>
#include <thread>
#include <cstdlib>
using namespace std;

/* 测试函数 */
void hello(int n=10)
{
    for (int i = 0; i < n; ++i)
        cout << i << " :hello, world" << endl;
}
void prn_chr(int n=10)
{
    for (int i = 0; i < n; ++i)
        cout << i << " :abcdefghijklmnopq" << endl;
}
void prn_num(int n=10)
{
    for (int i = 0; i < n; ++i)
        cout << i << " :12345678901234567890" << endl;
}
/* 建立3个线程，合并运行 */
void test_1()
{
    thread a(hello, 10), b{prn_chr, 10}, c{prn_num, 10};
    a.join();
    b.join();
    c.join();
}

int main()
{
    test_1();

    return 0;
}