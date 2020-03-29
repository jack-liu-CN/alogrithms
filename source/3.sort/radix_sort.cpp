/*
基数排序
	限制：元素都为整数。
	思想：将整数按位数切割，对位数从低有效位开始，往高有效位排序，且排序必须稳定。
	稳定性：稳定。
	时间复杂度：O(n)。
*/
#include<algorithm>

void counting_sort(int* seq, int len, int radix)
{
	//A中保存按当前基数排序后的数组
	int* A = new int[len];
	//B[i]中保存要比较的位数
	int* B = new int[len];
	//C[i]中保存小于等于i的个数
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
	//radix==1表示最低有效位
	for (int radix = 1; max > 0; radix *= 10)
	{
		//采用任意一种时间复杂度为O(n)的稳定排序算法即可
		counting_sort(seq, len, radix);
		max /= 10;
	}
}