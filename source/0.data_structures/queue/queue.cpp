/*
单向队列
	1.先进先出。
	2.插入在队尾进行，删除在队头进行。
*/
struct queue
{
	int* seq;
	int head;
	int tail;

	void enqueue(int value);
	int dequeue();
};

/*
双向队列
*/
struct deque
{

};

/*
循环队列
*/