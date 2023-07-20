#!/usr/bin/env python3
r'''
# with 上下文管理类型 Context Manager Types
  with 语句支持通过上下文管理器所定义的运行时上下文这一概念。

# Context Manager Types方法
    contextmanager.__enter__()
      进入上下文，并返回 as 子句的标识符
      例如：
        with expression as target_var:
            do_something(target_var)
    contextmanager.__exit__(exc_type, exc_val, exc_tb)
      退出运行时上下文，并返回一个布尔标志，指示是否应抑制发生的
        任何异常。如果在执行with语句主体时发生异常，
        则参数包含异常类型、值和回溯信息。

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('with and others')
    test()
