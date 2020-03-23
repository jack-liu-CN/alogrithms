/*
	���Σ�
		1.divide:���轫���⻮��ΪһЩ�����⣬���������ʽ��ԭ����һ����ֻ�ǹ�ģ��С��
		2.conquer:����ݹ�����������⡣����������ģ�㹻С����ֹͣ�ݹ顣
		3.combination:���轫������Ľ���ϳ�ԭ����Ľ⡣
*/

#include<limits.h>
/*
1.��������������
	divide��low-mid֮����������������͡�mid-high֮����������������͡��������mid���ڵ��������������͡�
	conquer:�ֱ���������������е����ֵ��
	combination:ȡ�������ֵ��
	ʱ�临�Ӷȣ�O(nlgn)��
*/

/*
	�����mid���ڵ��������������͡�
	ʱ�临�Ӷȣ�O(n)��
*/
int find_max_crossing_subarray(int* seq, int low, int mid, int high)
{
	int left_sum = 0;
	int max_left_sum = INT_MIN;
	int max_left_index;
	for (int i = mid; i >= 0; i--)
	{
		left_sum += seq[i];
		if (left_sum > max_left_sum)
		{
			max_left_sum = left_sum;
			max_left_index = i;
		}
	}
	int right_sum = 0;
	int max_right_sum = INT_MIN;
	int max_right_index;
	for (int i = mid + 1; i <= high; i++)
	{
		right_sum += seq[i];
		if (right_sum > max_right_sum)
		{
			max_right_sum = right_sum;
			max_right_index = i;
		}
	}
	return max_left_sum + max_right_sum;
}

int find_max_subarry(int* seq, int low, int high)
{
	if (low == high)
	{
		return seq[low];
	}
	int mid = (low + high) / 2;
	int max_left_sum = find_max_subarry(seq, low, mid - 1);
	int max_right_sum = find_max_subarry(seq, mid + 1, high);
	int max_crossing_sum = find_max_crossing_subarray(seq, low, mid, high);
	return max_left_sum > max_right_sum 
				? (max_left_sum > max_crossing_sum ? max_left_sum : max_crossing_sum)
				: (max_right_sum > max_crossing_sum ? max_right_sum : max_crossing_sum);
}

