#include "SqStack.h"
Status initStack(SqStack* s, int sizes)//��ʼ��ջ
{
	s->size = sizes;
	s->elem = (ElemType *) malloc (s->size);							//��ʼ��˳��ջ���ǰ�elem malloc()����
	s->top = -1;
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//�ж�ջ�Ƿ�Ϊ��	
{
	if (s->top == -1) return SUCCESS;				//ջ�� ����1
	return ERROR;
}
Status getTopStack(SqStack* s, ElemType* e) //�õ�ջ��Ԫ��,������0 ��Ϊ��ջ
{
	if (isEmptyStack(s)) return ERROR;
	*e = *(s->elem + s->top);
	return SUCCESS;
}
Status clearStack(SqStack* s)//���ջ
{
	memset(s->elem, 0, s->size);
	s->top = -1;
	return SUCCESS;
}
Status destroyStack(SqStack* s)//����ջ
{
	free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}
Status stackLength(SqStack* s, int* length)//���ջ����
{
	*length = s->top + 1;
	return SUCCESS;
}
Status pushStack(SqStack* s, ElemType data)//��ջ
{
	s->top++;
	*(s->elem + s->top) = data;
	return SUCCESS;
}
Status popStack(SqStack* s, ElemType* data)//��ջ
{
	if (isEmptyStack(s)) return ERROR;
	*data = *(s->elem + s->top);
	*(s->elem + s->top) = 0;
	s->top--;
	return SUCCESS;
}