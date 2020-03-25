/*
��������
	���ƣ�Ԫ�ض�Ϊ������
	˼�룺��������λ���и��λ���ӵ���Чλ��ʼ��������Чλ��������������ȶ���
	�ȶ��ԣ��ȶ���
	ʱ�临�Ӷȣ�O(n)��
*/
#include<algorithm>

void counting_sort(int* seq, int len, int radix)
{
	//A�б��水��ǰ��������������
	int* A = new int[len];
	//B[i]�б���Ҫ�Ƚϵ�λ��
	int* B = new int[len];
	//C[i]�б���С�ڵ���i�ĸ���
	int* C = new int[10]{ 0 };

	for (int i = 0; i < len; i++)
	{
		B[i] = seq[i] / radix % 10;
	}
	for (int i = 0; i < len; i++)
	{
		C[B[i]]++;
	}
	for (int i = 1; i < 10; i++)
	{
		C[i] += C[i - 1];
	}
	for (int i = len - 1; i >= 0; i--)
	{
		A[C[B[i]] - 1] = seq[i];
		C[B[i]]--;
	}
	for (int i = 0; i < len; i++)
	{
		seq[i] = A[i];
	}
}

void radix_sort(int* seq, int len)
{
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		max = std::max(max, seq[i]);
	}
	//radix==1��ʾ�����Чλ
	for (int radix = 1; max > 0; radix *= 10)
	{
		//��������һ��ʱ�临�Ӷ�ΪO(n)���ȶ������㷨����
		counting_sort(seq, len, radix);
		max /= 10;
	}
}