/*
ֱ�Ӳ�������
	*˼�룺ÿ�˽�һ��Ԫ�أ������С���뵽��ǰ���Ѿ�������������У������ظ���ֱ������ȫ��Ԫ�ء�
	*������Ԫ��������С��
	*�ȶ��ԣ��ȶ���
*/
void direct_insertion_sort(int* seq, int len)
{
	for (int i = 1; i < len; i++)
	{
		int key = seq[i];
		for (int j = i - 1; j >= 0 &&  key < seq[j]; j--)
		{
			//����Ԫ��
			seq[j + 1] = seq[j];
		}
		seq[j + 1] = key;
	}
}

/*
���ֲ�������
	*˼�룺��ֱ�Ӳ�������Ļ����ϣ�Ϊ���ٱȽϴ�����ʹ�ö��ֲ���Ѱ�Ҳ���λ�á�
	*�ȶ��ԣ��ȶ�
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
		for (int j = i - 1; j >= left ; j--)
		{
			seq[j + 1] = seq[j];
		}
		seq[left] = key;
	}
}

/*
Shell����
	*˼�룺�Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ������򣬴����������еļ�¼����������ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������
*/
void shell_sort(int* seq, int len)
{

 }