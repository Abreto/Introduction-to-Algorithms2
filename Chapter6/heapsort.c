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
 * @参数: *A:操作堆, length: 数组长度;
 **/
void init_heap(heap* A, int length)
{
	A->data = (int *)malloc(length * sizeof(int));
	A->length = length;
	A->heap_size = 0;
}

/**
 * 保持最大堆性质
 * 
 * @参数: *A: 操作堆, i:根结点下标
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

/**
 * 建堆
 * 
 * @参数: *A: 操作堆.
 ***/
void build_max_heap(heap* A)
{
	int i = 0;
	
	A->heap_size = A->length;
	for(i = ((A->length)>>1);i > 0;i--)
		max_heapify(A, i-1);
}

/**
 * 堆排序
 * 
 * @参数: *A: 待排序数组, length: 数组长度.
 **/
void heapsort(int* A, int length)
{
	int i = 0;
	heap h;
	init_heap(&h, length);
	 
	for(i = 0;i < length;i++)
		*(h->data+i) = *(A+i);
	build_max_heap(&h);
	
	for(i=length;i>1;i--)
	{
		*(h->data) = (*(h->data)) ^ (*(h->data+i-1));
		*(h->data+i-1) = (*(h->data)) ^ (*(h->data+i-1));
		*(h->data) = (*(h->data)) ^ (*(h->data+i-1));
		
		h->heap_size = h->heap_size - 1;
		max_heapify(&h, 0);
	}
}
