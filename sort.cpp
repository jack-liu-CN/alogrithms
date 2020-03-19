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
	*�ȶ��ԣ����ȶ���
*/
void shell_sort(int* seq, int len)
{
	//�����зֳ�gap��
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		//��ÿ��ĵڶ���Ԫ�ؿ�ʼ����ֱ������
		for (int i = gap; i < n; i++)
		{
			int key = seq[i];
			for (int j = i - gap; j >= 0 && seq[j] > key; j -= gap)
			{
				seq[j+ gap] = seq[j];
			}
			seq[j + gap] = key;
		}
	}
 }

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
	*ʱ�临�Ӷȣ���(nlgn)��
	*�ռ临�Ӷȣ���(n)��
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