#include<iostream>

/*
冒泡排序
	*时间复杂度：O(n²)
*/
void bubble_sort(int* seq, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (seq[j] > seq[j + 1])
			{
				std::swap(seq[j], seq[j + 1]);
			}
		}
	}
}