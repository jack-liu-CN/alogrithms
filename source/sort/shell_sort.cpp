/*
Shell排序
*/
void shell_sort(int* seq, int len)
{
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
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