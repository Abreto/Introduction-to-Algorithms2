/** 
 * 队列
 * 
 * 本实现未考虑溢出问题, 仅作参考.
 * 
 * 星枵<m@abreto.net>.
 * 2012-10-05.
 **/
#include <stdlib.h>

#define QUEUE_DEFAULT_SIZE 64

/** 队列结构 */
typedef struct
{
	int* data;
	size_t length;
	int head;
	int tail;
}queue, *p_queue;

/**
 * 初始化队列
 * 
 * @参数: p_queue 操作队列.
 **/
void queue_init(p_queue Q)
{
	Q->length = QUEUE_DEFAULT_SIZE;
	Q->data = (int *)malloc( Q->length * sizeof(int) );
	Q->head = Q->tail = 0;
}

/**
 * 入队
 * 
 * @参数: p_queue 操作队列, int 入队元素
 **/
void queue_enqueue(p_queue Q, int x)
{
	/** --这里是上溢出处理 -- **/
	*(Q->data + Q->tail) = x;
	if( Q->tail == Q->length-1 )
		Q->tail = 0;
	else
		Q->tail++;
}

/**
 * 出队
 * 
 * @参数: p_queue 操作队列.
 * @返回: 出队元素
 **/
int queue_dequeue(p_queue Q)
{
	/** --这里是下溢出处理 -- **/
	int x = *(Q->data + Q->head);
	
	if( Q->head == Q->length-1 )
		Q->head = 0;
	else
		Q->head++;
	
	return x;
}
