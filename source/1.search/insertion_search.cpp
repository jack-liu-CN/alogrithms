/*
��ֵ����
	���ƣ�������ҡ�
	ʱ�临�Ӷ�:O(lg(lgn))��
	˼�룺���ڶ��ֲ����㷨�����ݹؼ����������������������λ�ã���midֵ�ı仯�������ؼ���key������Ҳ�ͼ�ӵؼ����˱Ƚϴ�����
*/
int insertion_search(int* seq, int len, int value)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		//����ֲ��ҶԱ� int mid = left + (right-left) * 1/2
		int mid = left + (right - left) * (value - seq[left]) / (seq[right] - seq[left]);
		if (seq[mid] > value)
		{
			right = mid - 1;
		}
		else if (seq[mid] > value)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}