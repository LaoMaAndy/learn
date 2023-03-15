* chmod 
    chmod -R 递归调用  
    对所有目录执行 chmod -R -x *后
    无法使用 cd 进入目录，提示需要权限

* find
    查找 普通文件： -type f
    f  普通文件
    d  目录文件
    l  链接文件
    b  块设备文件
    c  字符设备文件
    p  管道文件
    s  socket文件

find 所有文件
‘’‘
    find . -type f
’‘’
find 
