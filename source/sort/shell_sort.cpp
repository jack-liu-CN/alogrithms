/*
Shell����
	*˼�룺�Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ������򣬴����������еļ�¼����������(gap == 1)ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������
	*�ȶ��ԣ����ȶ���
*/
void shell_sort(int* seq, int len)
{
	//�����зֳ�gap��
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		//��ÿ��ĵڶ���Ԫ�ؿ�ʼ����ֱ������
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