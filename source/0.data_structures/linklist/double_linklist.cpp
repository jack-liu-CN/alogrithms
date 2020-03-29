/*
双向链表结点
*/
struct dnode
{
	int value;
	dnode* prev;
	dnode* next;

	dnode(int v)
	{
		value = v;
		prev = nullptr;
		next = nullptr;
	}
};

/*
双向链表
*/
struct dlinklist
{
	dnode* head;
	dnode* tail;

	bool add(dnode* value);
	bool remove(dnode* value);
	bool reverse();
};