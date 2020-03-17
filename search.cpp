/*
二分查找
	*必须采用顺序存储结构。
	*必须按关键字大小有序排列。
*/
int binary_search(int* seq, int len, int value)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int middle = (right + left) / 2;
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