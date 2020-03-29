#include<iostream>

/*
	保持最大堆
*/
void max_heapify(int* heap, int index, int size)
{
	int left = 2 * index + 1, right = 2 * index + 2, max = index;
	if (left < size && heap[left] > heap[index])
	{
		max = left;
	}
	if (right < size && heap[right] > heap[max])
	{
		max = right;
	}
	if (index != max)
	{
		std::swap(heap[index], heap[max]);
		max_heapify(heap, max, size);
	}
}
/*
选择排序：
	时间复杂度：O(n^2)
*/
void heap_sort(int* seq, int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		max_heapify(seq, i, len);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		std::swap(seq[0], seq[i]);
		max_heapify(seq, 0, i);
	}
}