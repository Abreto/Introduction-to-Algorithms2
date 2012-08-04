/**
 * 计数排序
 * 
 * 星枵<m@abreto.net>.
 * 2012-08-04.
 **/

/**
 * 计数排序
 * 
 * @参数: *A: 输入数组, *B: 存放结果数组, n: 数组长度, k: 待排序数最大值.
 **/
void counting_sort(int* A, int *B, int n, int k)
{
	int i = 0, j = 0;
	int C[k+1] = {0};
	
	for(j = 0;j < n;j++)
		C[*(A+j)]++;
		
	for(i = 1;i < k+1;i++)
		C[i] += C[i-1];
		
	for(j = n;j > 0;j--)
	{
		*(B+C[*(A+j-1)]) = *(A+j-1);
		C[*(A+j-1)] = C[*A(+j-1)] - 1;
	}
}
