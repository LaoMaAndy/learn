/*
2023-12-7:
本文件内容：

完整的类定义结构
    包含： 无参数构造函数
          拷贝构造
          移动构造
          赋值运算符重载
          移动运算符重载
          析构函数
构造函数修饰：
    explicit, =delete, =default

异常的语法
    try
    {
        throw 
    }
    catch()
    catch(...)

类构造函数的完整例子和测试
    静态成员的初始化
    对象初始化时，使用的构造函数
    对象作为函数参数时，临时变量的使用
    对象作为函数返回值时，临时变量的使用
*/
#include <iostream>
#include <string>
using namespace std;
/*
编译参数：
g++ -std=c++11 -O0 -fno-elide-constructors
*/
//
//编译器常量
// __FUNCTION__
// __FILE__ 
// __LINE__
// 完整的类的结构：
// 
class Z{
public:
    //Z(int a){}         // 有参数的构造函数
    Z(){}              // 无参数的构造函数
    Z(const Z& para){}  // 拷贝构造
    Z(Z&& para){}       // 移动构造
    Z& operator=(const Z& para){return *this;} // 赋值运算符重载
    Z& operator=(Z&& para){return *this;}      // 移动运算符重载
    ~Z(){}            // 析构函数
private:
    int *ip;
};

// explicit, default, delete:
class Y{
public:
    Y() = default;
    explicit Y(int a){}
    Y(const Y& para) = delete;
};

// 异常的普通语法
class T {};
class S : public T {};
void test_try_catch()
{
    try
    {
        float f = 0;
        int i = 0;
        double d = 0.0;
        T t1;
        S s1;
        throw s1;
    }
    catch (int)
    {
        cout << "int catched" << endl;
    }
    catch (double)
    {
        cout << "double catched" << endl;
    }
    catch (T)
    {
        cout << "T catched" << endl;
    }
    catch (...)
    {
        cout << "... catched" << endl;
    }
}

// 类 A 定义了：
// 构造函数， 拷贝构造， 赋值运算符重载
class A{
public:
    A() : mem_s() {cout << i << ": " << "调用 无参数 构造函数" << endl; ++i;}
    A(const char *p) : mem_s(p) {cout << i << ": " << mem_s << "-调用 构造函数" << endl; ++i;}
    A(const A& p) : mem_s(p.mem_s) {mem_s = "(对象由 " + p.mem_s + " 拷贝构造)"; cout << i << ": "  << mem_s << "-调用拷贝构造" << endl; ++i; }
    A(A &&p) : mem_s(p.mem_s) {mem_s = "(对象由 " + p.mem_s + " 移动构造)"; cout << i << ": "  << mem_s << "-调用移动构造" << endl; ++i; }
    A& operator=(const A &p) {cout << i << ": " << mem_s << "-调用 赋值运算符重载" << endl; ++i; return *this; }
    A& operator=(const A &&p) {cout << i << ": " << mem_s << "-调用 移动运算符重载" << endl; ++i; return *this; }
    A& operator+(const A& p) {cout << i << ": " << mem_s << "-加法运算符重载" << endl; return *this; }
    ~A(){cout << i << ": " << mem_s << "-调用 析构函数" << endl; ++i;}
private:
    static int i;
    string mem_s;
};
int A::i = 0;

// 先构造, 后析构
void test_0()
{
    cout << "=== 测试函数-构造和析构的次序：先构造，后析构 ===" << endl;
    A a1("a1"), a2("a2"), a3("a3");
    cout << "**  函数主体执行完毕 **" << endl;
}

// 被调用函数f1，以对象为参数，不执行操作
void f1(A p)
{
    cout << "-- 子函数：以对象为参数，不执行操作 --" << endl;
}

// 函数执行顺序：
//    构造函数(对象a) -> 拷贝构造(临时参数) -> 调用函数f1 -> 立刻 析构函数(临时参数) -> 最后语句 -> 析构函数（a)
// 注意：无名临时变量，立刻执行析构
void test_1()
{
    cout << "=== 定义一个对象，作为参数，调用函数 === " << endl;
    A a("对象a");
    f1(a);
    cout << "**  函数主体执行完毕 **" << endl;
}
// 函数执行测序：
//  如果无 移动构造， 同 test_1()
//  如果有 移动构造， 则：构造函数(无名) -> 移动构造(临时参数) -> 调用函数 -> 析构函数(临时参数) -> 析构函数(无名)
// 注：调用函数，出现无名变量，优先使用 移动构造
void test_10()
{
    cout << "=== 采用紧凑形式调用函数 ===" << endl;
    f1(A("无名"));
    cout << "**  函数主体执行完毕 **" << endl;
}

// 被调用函数，返回一个对象，函数执行次序：
//   如果无 移动构造：构造函数(a) -> 拷贝构造(返回值) -> 析构函数(a)
//   如果有 移动构造：构造函数(a) -> 移动构造(返回值) -> 析构函数(a)
//注： 函数返回值，优先使用 移动构造
A f2()
{
    cout << "-- 子函数：定义一个对象，并返回 --" << endl;
    A a("a");
    return a;
}

// 执行次序： 调用函数f2() -> 析构函数(返回值)
// 调用一个有返回值的函数，可简单看做：
//      在函数位置定义了一个对象，类型为函数返回值类型,该变量无名称，是右值
void test_2()
{
    cout << "=== 调用有返回值的子函数 ===" << endl;
    f2();
}

// 同f2()
// 返回一个对象，
// 函数执行次序：
//   如果无 移动构造：构造函数(无名) -> 拷贝构造(返回值) -> 析构函数(a)
//   如果有 移动构造：构造函数(无名) -> 移动构造(返回值) -> 析构函数(无名)
//注： 函数返回值，优先使用 移动构造
A f20()
{
    cout << "-- 子函数：采用紧凑格式，返回一个对象  " << endl;
    return A("无名");
}

// 等同于test_2()
// 执行次序： 调用函数f20() -> 析构函数(返回值)
void test_20()
{
    cout << "=== 调用一个有返回值的子函数 ===" << endl;
    f20();
    cout << "**  函数主体执行完毕 **" << endl;
}

// 执行顺序：
//    如果无 移动构造函数： 调用f20() -> 拷贝构造(a) -> 析构函数(返回值) -> 析构函数(a)
//    有过有 移动构造函数： 调用f20() -> 移动构造(a) -> 析构函数(a) -> 析构函数(返回值)
void test_3()
{
    cout << "=== 定义一个对象，使用有返回值的子函数，进行初始化 ===" << endl;
    A a = f20();
    cout << "**  函数主体执行完毕 **" << endl;
}

// 执行顺序: 
//    如果无 移动构造函数：拷贝构造(返回值)
//    如果有 移动构造函数：移动构造(返回值)
A f4(A p)
{
    cout << "-- 子函数：直接将参数返回 --" << endl;
    return p;
}
// 执行顺序：构造函数(a) -> 拷贝构造（临时参数） -> 赋值函数（返回值） 
//      析构函数（返回值）-> 析构函数（临时参数) -> 最后语句 -> 析构函数（a)
// 函数参数变量 / 返回值变量，马上析构
void test_4()
{
    cout << "=== 定义一个对象，作为参数传递给函数，将返回值赋值给这个对象 ===" << endl;
    A a("对象a");
    a = f4(a);
    cout << "**  函数主体执行完毕 **" << endl;
}
// 表达式 r = a + b
// 执行3次构造函数：r, a, 
// 执行1次 加法运算符重载
// 执行1次 赋值运算符重载
void test_5()
{
    cout << "=== 表达式 r = a + b + c ===" << endl;
    A r("对象r"), a("对象a"), b("对象b"), c("对象c");
    r = a + b + c;
    cout << "**  函数主体执行完毕 **" << endl;
}
int main()
{
    // test_0();
    //test_1();
    //test_10();
    // test_2();
    // test_20();
    // test_3();
    // test_4();
    test_5();
    //test_try_catch();

    return 0;
}
