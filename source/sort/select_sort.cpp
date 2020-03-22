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