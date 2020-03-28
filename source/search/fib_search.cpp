/*
斐波那契查找
	限制：有序查找。
	时间复杂度：O(lgn)。
	思想：基于二分查找算法，以fib(k)-1为分割点。
*/
int fib(int k)
{
	if (k < 2)
	{
		return 1;
	}
	int f1 = 1, f2 = 1, result;
	for (size_t i = 2; i <= k; i++)
	{
		result = f1 + f2;
		f1 = f2;
		f2 = result;
	}
	return result;
}

int fib_search(int* seq, int len, int value)
{
	int left = 0;
	int right = len - 1;
	int k = 0;
	while (n > fib(k) - 1)
	{
		k++;
	}
	int* temp = new int[fib(k) - 1];
	memcpy(temp, seq, n * sizeof(int));
	for (int i = len; i < fib(k) - 1; i++)
	{
		temp[i] = seq[len - 1];
	}

	while (left <= right)
	{
		//与二分查找对比 int mid = left + (right-left) * 1/2
		int mid = left + fib(k) - 1;
		if (seq[mid] > value)
		{
			right = mid - 1;
			k -= 1;
		}
		else if (seq[mid] > value)
		{
			left = mid + 1;
			k -= 2;
		}
		else
		{
			return mid < len ? mid : len - 1;
		}
	}
	return -1;
}