/*
Shell排序
	*思想：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”(gap == 1)时，再对全体记录进行依次直接插入排序。
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