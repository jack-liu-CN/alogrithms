#include<iostream>

/*
	返回一个位置q，使得 左边子数组 <= seq[q] <= 右边子数组
*/
int partition(int* seq, int left, int right)
{
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (seq[j] <= seq[right])
		{
			i = i + 1;
			std::swap(seq[i], seq[j]);
		}
	}
	std::swap(seq[i + 1], seq[right]);
	return i + 1;
}

/*
	快速排序
*/
void quick_sort(int* seq, int p, int r)
{
	if (p < r)
	{
		int q = partition(seq, p, r);
		quick_sort(seq, p, q - 1);
		quick_sort(seq, q + 1, r);
	}
}
