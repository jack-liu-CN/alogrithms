/*
�������������кϲ�Ϊһ���������С�
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
�鲢����
	*˼�룺���Ρ�
	*�ȶ��ԣ����ȶ���
	*ʱ�临�Ӷȣ�O(nlgn)��
	*�ռ临�Ӷȣ�O(n)��
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