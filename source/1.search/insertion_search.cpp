/*
插值查找
	限制：有序查找。
	时间复杂度:O(lg(lgn))。
	思想：基于二分查找算法，根据关键字在整个有序表中所处的位置，让mid值的变化更靠近关键字key，这样也就间接地减少了比较次数。
*/
int insertion_search(int* seq, int len, int value)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		//与二分查找对比 int mid = left + (right-left) * 1/2
		int mid = left + (right - left) * (value - seq[left]) / (seq[right] - seq[left]);
		if (seq[mid] > value)
		{
			right = mid - 1;
		}
		else if (seq[mid] > value)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}