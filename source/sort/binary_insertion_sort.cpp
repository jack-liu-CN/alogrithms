/*
���ֲ�������
	*˼�룺��ֱ�Ӳ�������Ļ����ϣ�Ϊ���ٱȽϴ�����ʹ�ö��ֲ���Ѱ�Ҳ���λ�á�
	*�ȶ��ԣ��ȶ���
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
			int middle = (right + left) / 2;
			//�������Ϊseq[middle] >= key���������ȶ�
			if (seq[middle] > key)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}
		for (int j = i - 1; j >= left; j--)
		{
			seq[j + 1] = seq[j];
		}
		seq[left] = key;
	}
}