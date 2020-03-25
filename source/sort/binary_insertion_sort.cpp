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