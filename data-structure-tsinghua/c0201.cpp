#include <iostream>
using namespace std;

/* 
ADT list
some operation of list:
	create		: 初始化 
	resize		: 重新调整内存
	free		: 释放
	clear		: 重置为空
	empty		: 是否为空
	size		: 尺寸
	get			: 获取元素
	set			: 设定元素
	seek		: 查找
	prior		: 前一个元素
	next		: 后一个元素
	insert		: 插入
	delete		: 删除
	traverse	: 遍历

	sort		: 排序 

mass operation
	fuse
	cat
	camp
	dup

// from wikipedia:
a constructor for creating an empty list;
an operation for testing whether or not a list is empty;
an operation for prepending an entity to a list
an operation for appending an entity to a list
an operation for determining the first component (or the "head") of a list
an operation for referring to the list consisting of all the components of a list except for its first (this is called the "tail" of the list.)

Lists are typically implemented either as linked lists (either singly or doubly linked) or as arrays, usually variable length or dynamic arrays.
*/


/* sequential list */
class Data
{
private:
	int val;
public:
	int get();
	int set();
};
	
class Arlist
{
private:
	long memsize;
	long current;
	Data *dp;				
public:
	int create();
	int free();
	int resize();
	int get();
	int set();
	int append();
	int prepend();
	int cur();
	int next();
	int prior();
	int size();
};
		


	
	

