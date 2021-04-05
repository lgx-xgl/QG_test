#include "LinkStack.h"
Status initLStack(LinkStack* s)//��ʼ��ջ
{
	s->top = new StackNode;
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}
Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->top->next == NULL) return SUCCESS;
	else return ERROR;
}
Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	if (isEmptyLStack(s)) return ERROR;
	*e = s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack* s)//���ջ
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
Status destroyLStack(LinkStack* s)//����ջ
{
	if (s == NULL) return ERROR;
	clearLStack(s);
	s->top = NULL;
	return SUCCESS;
}
Status LStackLength(LinkStack* s, int* length)//���ջ����
{
	if (s == NULL) return ERROR;
	*length = s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	if (s == NULL) return ERROR;
	LinkStackPtr p= new StackNode;
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}
Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	if (s == NULL||s->count==0) return ERROR;
	*data = s->top->data;
	s->top = s->top->next;
	s->count--;
	return SUCCESS;
}