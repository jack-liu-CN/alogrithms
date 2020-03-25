#include<iostream>

/*
计数排序法
	限制：数组元素为0-k区间上的整数。
	时间复杂度：O(n)
*/
void counting_sort(int* A, int* B, int len, int k)
{
	int* C = new int[k + 1]{ 0 };
	//C[i]保存A中i的个数
	for (int i = 0; i < len; i++)
	{
		C[A[i]]++;
	}
	//C[i]保存A中小于等于i的个数
	for (int i = 1; i <= k; i++)
	{
		C[i] += C[i - 1];
	}
	//B保存排好序的数组
	for (int i = len - 1; i >= 0; i--)
	{
		//小于等于A[i]的个数有C[A[i]]个,所以A[i]的位置就在第C[A[i]]位
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}