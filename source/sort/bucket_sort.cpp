/*
桶排序
	限制：输入数据在[min,max]之间均匀分布。
	时间复杂度：O(n)。
	说明：不适用于数组元素跨度太大(空间复杂度高)。
	实现：
		1.利用一维数组，桶的下标对应元素的值(适用于跨度小且元素为int)。
		2.利用二维数组，每个桶内保存数组元素，最后从桶中取出元素的时候再对每个桶内的元素进行插入排序。
*/

constexpr int MIN = 0;
constexpr int MAX = 9;

void bucket_sort(int* seq, int len)
{
	int range = MAX - MIN + 1;
	int* bucket = new int[range] {0};
	//计数
	for (int i = 0; i < len; i++)
	{
		buckets[seq[i]]++;
	}
	//按桶取出元素
	for (int i = 0, j = 0; i < range; i++)
	{
		//说明该桶内还有元素
		while (buckets[i] > 0)
		{
			arr[j++] = i;
			bucket[i]--;
		}
	}
}