/*
	动态规划

*/
#include <algorithm>

/*
1.最大连续子数组和
	限制：数组内必须含正数。(很关键)
	f(i)表示以i结尾的最大连续子数组和。
	状态转移方程：
		f(i) = seq[i],			i=0或f(i-1)<=0
		f(i) = f(i-1) + seq[i], f(i-1)>0且i>0
*/
int find_max_subarray(int* seq, int len)
{
	//当前所有子数组和的最大值
	int result = seq[0];
	//以i结尾的最大连续子数组和。
	int max = seq[0];
	
	for (int i = 1; i < len; i++)
	{
		max = std::max(max + seq[i], seq[i]);
		result = std::max(max, result);
	}
	return result;
}