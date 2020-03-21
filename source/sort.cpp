﻿/*
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

/*
选择排序
	*时间复杂度：O(n²)
*/
void select_sort(int* seq, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < len; j++)
		{
			if (seq[min_index] > seq[j])
			{
				min_index = j;
			}
		}
		if (seq[min_index] != seq[i])
		{
			std::swap(seq[i], seq[min_index]);
		}
	}
}

/*
直接插入排序
	*思想：每趟将一个元素，按其大小插入到它前面已经排序的子序列中，依此重复，直到插入全部元素。
	*场景：元素数量较小。
	*稳定性：稳定。
	*时间复杂度：O(n²)。
*/
void direct_insertion_sort(int* seq, int len)
{
	for (int i = 1; i < len; i++)
	{
		int key = seq[i], j = i - 1;
		for (; j >= 0 && key < seq[j]; j--)
		{
			//后移元素
			seq[j + 1] = seq[j];
		}
		seq[j + 1] = key;
	}
}

/*
二分插入排序
	*思想：在直接插入排序的基础上，为减少比较次数，使用二分查找寻找插入位置。
	*稳定性：稳定。
*/
void binary_insertion_sort(int* seq, int len)
{
	for (int i = 1; i < len; i++)
	{
		int key = seq[i];
		int left = 0;
		int right = i - 1;
		while (left <= right)
		{
			int middle = (right + left) / 2;
			//如果条件为seq[middle] >= key，则排序不稳定
			if (seq[middle] > key)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}
		for (int j = i - 1; j >= left; j--)
		{
			seq[j + 1] = seq[j];
		}
		seq[left] = key;
	}
}

/*
Shell排序
	*思想：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。
	*稳定性：不稳定。
*/
void shell_sort(int* seq, int len)
{
	//将序列分成gap组
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		//从每组的第二个元素开始进行直插排序
		for (int i = gap; i < len; i++)
		{
			int key = seq[i], j = i - gap;
			for (; j >= 0 && seq[j] > key; j -= gap)
			{
				seq[j + gap] = seq[j];
			}
		}
	}
}

/*
将两个有序序列合并为一个有序序列。
*/
void merge(int* seq, int left, int middle, int right)
{
	int* temp = new int[right - left + 1];
	int i = left, j = middle + 1, k = 0;
	while (i <= middle && j <= right)
	{
		temp[k++] = seq[i] <= seq[j] ? seq[i++] : seq[j++];
	}
	while (i <= middle)
	{
		temp[k++] = seq[i++];
	}
	while (j <= right)
	{
		temp[k++] = seq[j++];
	}
	for (int i = 0; i <= right - left; i++)
	{
		seq[i + left] = temp[i];
	}
}
/*
归并排序
	*思想：分治。
	*稳定性：不稳定。
	*时间复杂度：O(nlgn)。
	*空间复杂度：O(n)。
*/
void merge_sort(int* seq, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		merge_sort(seq, left, middle);
		merge_sort(seq, middle + 1, right);
		merge(seq, left, middle, right);
	}
}

/*
	*维持最大堆的性质
	*时间复杂度：O(lgn)
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
堆排序
	*时间复杂度：O(nlgn).
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
