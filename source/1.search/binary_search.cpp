/*
二分查找
	限制：有序查找。
	时间复杂度:O(lgn)。
	说明：不适用于频繁增加、修改元素值的数组。
*/
int binary_search(int* seq, int len, int value)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int middle =  left + (right - left) / 2;
		if (seq[middle] > value)
		{
			right = middle - 1;
		}
		else if (seq[middle] < value)
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}