#include "LinkStack.h"
Status initLStack(LinkStack* s)//初始化栈
{
	s->top = new StackNode;
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}
Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	if (s->top->next == NULL) return SUCCESS;
	else return ERROR;
}
Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
{
	if (isEmptyLStack(s)) return ERROR;
	*e = s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack* s)//清空栈
{
	LinkStackPtr p;
	if (s->top == NULL) return ERROR;
	while (s->top->next != NULL) {
		p = s->top->next;
		delete(s->top);
		s->top = p;
	}
	return SUCCESS;
}
Status destroyLStack(LinkStack* s)//销毁栈
{
	if (s == NULL) return ERROR;
	clearLStack(s);
	s->top = NULL;
	return SUCCESS;
}
Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	if (s == NULL) return ERROR;
	*length = s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	if (s == NULL) return ERROR;
	LinkStackPtr p= new StackNode;
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}
Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	if (s == NULL||s->count==0) return ERROR;
	*data = s->top->data;
	s->top = s->top->next;
	s->count--;
	return SUCCESS;
}