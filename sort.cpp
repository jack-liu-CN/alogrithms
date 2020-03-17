/*
直接插入排序
	*思想：每趟将一个元素，按其大小插入到它前面已经排序的子序列中，依此重复，直到插入全部元素。
	*场景：元素数量较小。
	*稳定性：稳定。
*/
void direct_insertion_sort(int* seq, int len)
{
	for (int i = 1; i < len; i++)
	{
		int key = seq[i];
		for (int j = i - 1; j >= 0 &&  key < seq[j]; j--)
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
	*稳定性：稳定
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
			int middle = (right + left) /2;
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
		for (int j = i - 1; j >= left ; j--)
		{
			seq[j + 1] = seq[j];
		}
		seq[left] = key;
	}
}

/*
Shell排序
	*思想：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。
*/
void shell_sort(int* seq, int len)
{

 }