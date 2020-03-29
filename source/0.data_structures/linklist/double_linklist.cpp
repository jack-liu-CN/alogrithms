/*
˫��������
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
˫������
*/
struct dlinklist
{
	dnode* head;
	dnode* tail;

	bool add(node* value);
	bool remove(node* value);
	bool reverse();
};