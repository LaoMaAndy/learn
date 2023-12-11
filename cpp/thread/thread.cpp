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

传递参数：
    thread t(函数名，参数_1, 参数_2)
    举例：
    void foo(int);
    thread t(foo, 23, "this");

合并执行、分离执行
    t.join()   t.detach()

线程对象支持 move 操作
    thread t2, t1{foo};
    t2 = std::move(t1);
    注意：如果 t2 已经被初始化，则会调用std::terminate()退出程序。

线程标识符
    thread::id 表示符, 64位
    获得 thread::get_id()

互斥 mutex
    模版 std::lock_guard
*/
#include <iostream>
#include <thread>
#include <cstdlib>
using namespace std;

int main()
{
    //void test_1(); test_1();
    // void test_2(); test_2();
    // void test_3(); test_3();
    // void test_4(); test_4();
    void test_mutex(); test_mutex();
    return 0;
}
// 使用 mutex 互斥元
void test_mutex()
{

}
// 线程 id
void test_4()
{
    void hello();
    thread t1{hello};

    cout << "Thead id: " << t1.get_id() << endl;
    cout << "sizeof(id): " << sizeof(t1.get_id()) << endl;
    cout << "If don't join() a thread, it will terminate" << endl;
    //t1.join();
}
// 线程对象，可以使用std::move() 函数，转移
// 即，可以定义某个函数，返回新增的线程
void test_3()
{
    void hello();
    void prn_num();

    thread t1{hello};
    thread t2;

    t2 = std::move(t1);
    t2.join();
    // t1.join();
    // t2.join();
}
// 返回  当前系统支持的线程数量
void test_2()
{
    cout << "thread::hardware_concurrency(): " << thread::hardware_concurrency() << endl;
}
// 一些 操作
void hello()
{
    for (int i = 0; i < 10; ++i)
        cout << i << " :hello, world" << endl;
}
void prn_chr()
{
    for (int i = 0; i < 10; ++i)
        cout << i << " :abcdefghijklmnopq" << endl;
}
void prn_num()
{
    for (int i = 0; i < 10; ++i)
        cout << i << " :12345678901234567890" << endl;
}
/* 建立3个线程，合并运行 */
void test_1()
{
    thread a(hello), b{prn_chr}, c{prn_num};
    a.join();
    b.join();
    c.join();
}
