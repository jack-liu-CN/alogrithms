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