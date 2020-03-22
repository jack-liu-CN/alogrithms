struct linknode
{
	int value;
	linknode* next;

	linknode(int v)
	{
		value = v;
		next = NULL;
	}
};

linknode* reverse_linklist(linknode* head)
{
	linknode* p_cur = head;
	linknode* p_pre = NULL;
	linknode* temp;
	while (p_cur != NULL)
	{
		temp = p_pre;
		p_pre = p_cur;
		p_cur = p_cur->next;
		p_pre->next = temp;
	}
	return p_pre;
}