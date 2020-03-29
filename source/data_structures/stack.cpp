/*
栈
	1.先进后出。
	2.插入和删除只在栈顶进行。
	3.STL默认选择deque双向队列实现，并且使用alloc内存分配，缓冲区大小为512B。
*/
struct stack 
{
	int* seq;
	//栈顶
	int top;

	void push(int value);
	int pop();
	bool is_empty();
	//栈中元素个数
	int size();
};