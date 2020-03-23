/*
	分治：
		1.divide:步骤将问题划分为一些子问题，子问题的形式与原问题一样，只是规模更小。
		2.conquer:步骤递归地求解出子问题。如果子问题规模足够小，则停止递归。
		3.combination:步骤将子问题的解组合成原问题的解。
*/

#include<limits.h>
/*
1.最大连续子数组和
	divide：low-mid之间的最大连续子数组和、mid-high之间的最大连续子数组和、必须包含mid在内的最大连续子数组和。
	conquer:分别求出这三个子序列的最大值。
	combination:取三者最大值。
	时间复杂度：O(nlgn)。
*/

/*
	求包含mid在内的最大连续子数组和。
	时间复杂度：O(n)。
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

