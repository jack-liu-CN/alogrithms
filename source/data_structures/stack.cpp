/*
ջ
	1.�Ƚ������
	2.�����ɾ��ֻ��ջ�����С�
	3.STLĬ��ѡ��deque˫�����ʵ�֣�����ʹ��alloc�ڴ���䣬��������СΪ512B��
*/
struct stack 
{
	int* seq;
	//ջ��
	int top;

	void push(int value);
	int pop();
	bool is_empty();
	//ջ��Ԫ�ظ���
	int size();
};