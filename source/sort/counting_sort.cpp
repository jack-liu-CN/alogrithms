#include<iostream>

/*
��������
	���ƣ�����Ԫ��Ϊ0-k�����ϵ�������
	ʱ�临�Ӷȣ�O(n)
*/
void counting_sort(int* A, int* B, int len, int k)
{
	int* C = new int[k + 1]{ 0 };
	//C[i]����A��i�ĸ���
	for (int i = 0; i < len; i++)
	{
		C[A[i]]++;
	}
	//C[i]����A��С�ڵ���i�ĸ���
	for (int i = 1; i <= k; i++)
	{
		C[i] += C[i - 1];
	}
	//B�����ź��������
	for (int i = len - 1; i >= 0; i--)
	{
		//С�ڵ���A[i]�ĸ�����C[A[i]]��,����A[i]��λ�þ��ڵ�C[A[i]]λ
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}