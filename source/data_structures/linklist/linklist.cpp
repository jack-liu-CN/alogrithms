/*
单向链表结点
*/
struct node
{
	int value;
	node* next;

	node(int v)
	{
		value = v;
		next = nullptr;
	}
};

/*
单向链表
*/
class linklist
{
	node* head;

	bool add(node* value);
	bool remove(node* value);
	bool reverse();
};

node* reverse_linklist(node* head)
{
	node* p_cur = head;
	node* p_pre = nullptr;
	node* temp;
	while (p_cur != nullptr)
	{
		temp = p_pre;
		p_pre = p_cur;
		p_cur = p_cur->next;
		p_pre->next = temp;
	}
	return p_pre;
}

