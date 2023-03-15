- MD在线编辑器
https://pandao.github.io/editor.md/index.html

##  MacOS / Linux 指令
### === chmod ===
    chmod -R 递归调用  
    对所有目录执行 chmod -R -x *后
    无法使用 cd 进入目录，提示需要权限

### === find ====
##### find 基本用法
    完整形式：
    find path  -option  [-print]  [-exec  -ok  command] { } \;
    简化为：
    find  [path...]  [expression]
    查找某种类型文件：
    find  .  -type f
##### expression 表达式
    可以分为 “-options [-print -exec -ok ...]”

    -options，指定find命令的常用选项，下节详细介绍
    -print，find命令将匹配的文件输出到标准输出
    -exec，find命令对匹配的文件执行该参数所给出的shell命令。相应命令的形式为'command' { } \;，注意{ }和\；之间的空格
    find ./ -size 0 -exec rm {} \; 删除文件大小为零的文件 （还可以以这样做：rm -i find ./ -size 0 或 find ./ -size 0 | xargs rm -f &）
    为了用ls -l命令列出所匹配到的文件，可以把ls -l命令放在find命令的-exec选项中：find . -type f -exec ls -l { } \;
    在/logs目录中查找更改时间在5日以前的文件并删除它们：find /logs -type f -mtime +5 -exec rm { } \;
    -ok，和-exec的作用相同，只不过以一种更为安全的模式来执行该参数所给出的shell命令，在执行每一个命令之前，都会给出提示，让用户来确定是否执行。
    find . -name "*.conf" -mtime +5 -ok rm { } \; 在当前目录中查找所有文件名以.conf结尾、更改时间在5日以上的文件，并删除它们，只不过在删除之前先给出提示

##### find option 选项
    -mount, -xdev : 只检查和指定目录在同一个文件系统下的文件，避免列出其它文件系统中的文件
    -amin n : 在过去 n 分钟内被读取过
    -anewer file : 比文件 file 更晚被读取过的文件
    -atime n : 在过去n天内被读取过的文件
    -cmin n : 在过去 n 分钟内被修改过
    -cnewer file :比文件 file 更新的文件
    -ctime n : 在过去n天内被修改过的文件
    -empty : 空的文件-gid n or -group name : gid 是 n 或是 group 名称是 name
    -ipath p, -path p : 路径名称符合 p 的文件，ipath 会忽略大小写
    -name name, -iname name : 文件名称符合 name 的文件。iname 会忽略大小写
    -size n : 文件大小 是 n 单位，b 代表 512 位元组的区块，c 表示字元数，k 表示 kilo bytes，w     是二个位元组。
    -type c : 文件类型是 c 的文件

##### 文件类型 -type f
    f  普通文件
    d  目录文件
    l  链接文件
    b  块设备文件
    c  字符设备文件
    p  管道文件
    s  socket文件

##### find实例-1 按文件名
    *号 表示通配任意的字符
    find /etc -name "*passwd"     
    
    ？表示通配任意的单个字符
    find /etc -name "passwd?"
    
    [ ]表示通配括号里面的任意一个字符
    find /etc -name "[ab].sh"

##### find实例2 按用户和组
    -user //根据属主来查找文件
    -group //根据属组来查找文件

##### find实例3 按 uid 和 gid
    find  /tmp  -uid  500  //查找uid是500 的文件
    find  /tmp  -gid  1000 // 查找gid是1000的文件

##### find实例4 -a and -o and –not的使用
    -a 连接两个不同的条件（两个条件必须同时满足）
    -o 连接两个不同的条件（两个条件满足其一即可）
    -not 对条件取反的

    find /tmp -name "*.sh" -a -user root
    find /tmp -not -user root

##### find实例5 按时间戳
    可以使用stat命令来查看一个文件的时间信息如下：
    stat /etc/passwd
    -atime
    -mtime
    -ctime
    -amin
    -mmin
    -cmin
###### 所以这里atime, mtime, ctime就是分别对应的 
“最近一次访问时间”   
“最近一次内容修改时间”   
“最近一次属性修改时间”，  
这里的atime的单位指的是“天”，amin的单位是分钟  

    find /tmp –atime +5      //表示查找在五天内没有访问过的文件（也就是5天前天没访问的文件）
    find /tmp -atime -5      //表示查找在五天内访问过的文件
    ps：在清理日志的时候，一般使用的是——最近一次内容修改的时间
    find -mtime +30 -name "*[0-9]*" -exec rm {} \;

##### find实例6 按文件类型 -type
    f // 普通文件
    d //目录文件
    l //链接文件
    b //块设备文件
    c //字符设备文件
    p //管道文件
    s //socket文件
    find /tmp -type s

##### find实例7 按大小 -size
    find /tmp -size 2M       //查找在/tmp 目录下等于2M的文件
    find /tmp -size +2M      //查找在/tmp 目录下大于2M的文件
    find /tmp -size -2M      //查找在/tmp 目录下小于2M的文件

##### find实例8 按文件权限 -perm
    find /tmp -perm 755      //查找在/tmp目录下权限是755的文件
    find /tmp -perm +222     //表示只要有一类用户（属主，属组，其他）的匹配写权限就行
    find /tmp -perm -222     //表示必须所有类别用户都满足有写权限

##### find实例9 -nouser and -nogroup
find / -nogroup –a –nouser    
//在整个系统中查找既没有属主又没有属组的文件（
这样的文件通常是很危险的，作为系统工程师的我们应该及时清除掉）

#### 查找完执行的action
    -print //默认情况下的动作
    -ls //查找到后用ls 显示出来
    -ok [commend] //查找后执行命令的时候询问用户是否要执行
    -exec [commend] //查找后执行命令的时候不询问用户，直接执行

##### 举例
```
    find /tmp -name "*.sh" -exec chmod u+x {} \;
    这里要注意{}的使用：替代查找到的文件
    
    find /tmp "*.sh" -exec cp {} {}.old \;
    删除查找到的超过30天没有访问过文件
    
    find  /tmp  -atime  +30  –exec rm –rf  {}  \； 
    也可以使用xargs来对查找到的文件进一步操作
    
    find /tmp -name "*.old" | xargs chmod 700
```
##### 案例详细说明
###### 删除文件
    find 对应目录 -mtime +天数 -name "文件名" -exec rm -rf {} \;

###### 删除文件举例
    find /opt/soft/log/ -mtime +30 -name "*.log" -exec rm -rf {} \;
###### 说明
```bash
删除/opt/soft/log/目录下所有
30天前带".log"的文件删除。具体参数说明如下：
find linux的查找命令，用户查找指定条件的文件；
/opt/soft/log/：想要进行清理的任意目录；
-mtime：标准语句写法；
+30：查找30天前的文件，这里用数字代表天数；
"*.log"：希望查找的文件名正则表达式，
"*.jpg"表示查找扩展名为jpg的所有文件，
"*"表示查找所有文件，这个可以灵活运用，举一反三；
-exec：固定写法；
rm -rf：强制删除文件，包括目录；
{} ; ：固定写法，一对大括号+空格+\+;
```
