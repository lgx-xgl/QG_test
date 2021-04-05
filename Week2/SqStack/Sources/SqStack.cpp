#include "SqStack.h"
Status initStack(SqStack* s, int sizes)//初始化栈
{
	s->size = sizes;
	s->elem = (ElemType *) malloc (s->size);							//初始化顺序栈就是把elem malloc()申请
	s->top = -1;
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//判断栈是否为空	
{
	if (s->top == -1) return SUCCESS;				//栈空 返回1
	return ERROR;
}
Status getTopStack(SqStack* s, ElemType* e) //得到栈顶元素,若返回0 则为空栈
{
	if (isEmptyStack(s)) return ERROR;
	*e = *(s->elem + s->top);
	return SUCCESS;
}
Status clearStack(SqStack* s)//清空栈
{
	memset(s->elem, 0, s->size);
	s->top = -1;
	return SUCCESS;
}
Status destroyStack(SqStack* s)//销毁栈
{
	free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}
Status stackLength(SqStack* s, int* length)//检测栈长度
{
	*length = s->top + 1;
	return SUCCESS;
}
Status pushStack(SqStack* s, ElemType data)//入栈
{
	s->top++;
	*(s->elem + s->top) = data;
	return SUCCESS;
}
Status popStack(SqStack* s, ElemType* data)//出栈
{
	if (isEmptyStack(s)) return ERROR;
	*data = *(s->elem + s->top);
	*(s->elem + s->top) = 0;
	s->top--;
	return SUCCESS;
}