/** 
 * 栈
 * 
 * 本实现未考虑溢出问题, 仅作参考.
 * 
 * 星枵<m@abreto.net>.
 * 2012-08-05.
 **/
#include <stdlib.h>


/** 栈结构 */
typedef struct _stack
{
	int *data;	// 数据数组
	int top;	// 栈顶指针
}stack, *p_stack;


/**
 * 初始化栈结构
 * 
 * @参数: p_stack 操作栈.
 **/
void stack_init(p_stack S)
{
	S->data = (int *)malloc(100 * sizeof(int));
	S->top = -1;
}

/**
 * 栈是否为空
 * 
 * @参数: stack 判断栈.
 * @返回: 空:1, 不空:0;
 **/
int stack_empty(stack S)
{
	if( S.top == -1 ) return 1;
	return 0;
}

/**
 * 压栈
 * 
 * @参数: p_stack 操作栈, int 压入元素.
 **/
void stack_push(p_stack S, int x)
{
	/*****************
	 * ------------- *
	 * 这里是栈上溢处理 *
	 * ------------- *
	 *****************/
	 
	*(S->data+(++(S->top))) = x;
}

/**
 * 退栈
 * 
 * @参数: p_stack 操作栈.
 * @返回: 栈顶元素值;
 **/
int stack_pop(p_stack S)
{
	/*****************
	 * ------------- *
	 * 这里是栈下溢处理 *
	 * ------------- *
	 *****************/
	 
	 return ( *(S->data + (--(S->top))) );
}
