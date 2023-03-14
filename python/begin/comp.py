def test_compre():
    girls = ['alice', 'bernice', 'clarice', 'billy']
    boys = ['chris', 'arnold', 'bob']
    letterGirls = {}
    for girl in girls:
        letterGirls.setdefault(girl[0], []).append(girl)
    print(letterGirls)
    print([b+'+'+g for b in boys for g in letterGirls[b[0]]])

def test_del():
    j = i = ['1', '2', '3']
    print('test del:')
    print("i value: ", i)
    del i
    print("i been deleted")
    # print("after delete, i:", i)
    print("j : ", j)

def test_exec():
    print("exec a statment:")
    exec("print('This is exec from a string....jkkk d')")
    #s = input("input a python statement:")
    #i = exec(s)
    ns = {}
    command_str = '''
print("test a longer statment.")
i = 0
for j in range(10):
    print("i + j = ", i + j)
    i += 1
print("end")
    '''
    print(command_str, ns)
    exec(command_str, ns)
    print("exec finished")

def test_doc():
    ''' There some docstring,
    for some reason, 
    it can be nothing'''
    print(test_doc.__name__)
    print("function's docstring:")
    print(test_doc.__doc__)
    # print("Calling help():")

def main():
    test_compre()
    test_del()
    test_exec()
    test_doc()


if __name__ == '__main__':
    main()


