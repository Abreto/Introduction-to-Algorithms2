/** Heapsort.c 第六章堆排序
 * 
 * Abreto<m@abreto.net>
 * 2012.07.30
 **/
#include <stdlib.h>


/** 结点i的父结点下标 */
#define	parent(i)	( i>>1 )

/** 结点i的左子结点下标 */
#define left(i)		( 2*i )

/** 结点i的右子结点下标 */
#define right(i)	( 2*i+1 )

/** 堆结构 */
typedef struct _heap
{
	int* data;
	int length;
	int heap_size;
}heap;


/**
 * 初始化堆结构
 * @输入: A:操作堆, length: 数组长度, heap_size:堆长度;
 **/
void init_heap(heap* A, int length, int heap_size)
{
	A->data = (int *)malloc(length * sizeof(int));
	A->length = length;
	A->heap_size = heap_size;
}

/**
 * 保持最大堆性质函数
 * 
 * @输入: A: 操作堆, i:根结点下标
 **/
void max_heapify(heap* A, int i)
{
	int l = left(i);
	int r = right(i);
	int largest = 0;
	
	if( (l <= (A->heap_size)) && ((*(A->data+l))>(*(A->data+i))) )
		largest = l;
	else
		largest = i;
	if( (r <= (A->heap_size)) && ((*(A->data+r))>(*(A->data+largest))) )
		largest = r;
	if( largest != i )
	{
		int tmd = *(A->data+i);
		*(A->data+i) = *(A->data+largest);
		*(A->data+largest) = tmd;
		max_heapify(A, largest);
	}
	
}

