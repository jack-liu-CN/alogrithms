/*
	��̬�滮

*/
#include <algorithm>

/*
1.��������������
	���ƣ������ڱ��뺬������(�ܹؼ�)
	f(i)��ʾ��i��β���������������͡�
	״̬ת�Ʒ��̣�
		f(i) = seq[i],			i=0��f(i-1)<=0
		f(i) = f(i-1) + seq[i], f(i-1)>0��i>0
*/
int find_max_subarray(int* seq, int len)
{
	//��ǰ����������͵����ֵ
	int result = seq[0];
	//��i��β���������������͡�
	int max = seq[0];
	
	for (int i = 1; i < len; i++)
	{
		max = std::max(max + seq[i], seq[i]);
		result = std::max(max, result);
	}
	return result;
}