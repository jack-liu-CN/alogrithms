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

