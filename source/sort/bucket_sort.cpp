/*
Ͱ����
	���ƣ�����������[min,max]֮����ȷֲ���
	ʱ�临�Ӷȣ�O(n)��
	˵����������������Ԫ�ؿ��̫��(�ռ临�Ӷȸ�)��
	ʵ�֣�
		1.����һά���飬Ͱ���±��ӦԪ�ص�ֵ(�����ڿ��С��Ԫ��Ϊint)��
		2.���ö�ά���飬ÿ��Ͱ�ڱ�������Ԫ�أ�����Ͱ��ȡ��Ԫ�ص�ʱ���ٶ�ÿ��Ͱ�ڵ�Ԫ�ؽ��в�������
*/

constexpr int MIN = 0;
constexpr int MAX = 9;

void bucket_sort(int* seq, int len)
{
	int range = MAX - MIN + 1;
	int* bucket = new int[range] {0};
	//����
	for (int i = 0; i < len; i++)
	{
		buckets[seq[i]]++;
	}
	//��Ͱȡ��Ԫ��
	for (int i = 0, j = 0; i < range; i++)
	{
		//˵����Ͱ�ڻ���Ԫ��
		while (buckets[i] > 0)
		{
			arr[j++] = i;
			bucket[i]--;
		}
	}
}