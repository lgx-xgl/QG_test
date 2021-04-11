#include "LQueue.h"

void InitLQueue(LQueue* Q)							//��ʼ������
{
	Q->front = new node;
	Q->rear = Q->front;
	Q->length = 0;
	return;
}

void DestoryLQueue(LQueue* Q)						//���ٶ���
{
	Node* p = Q->front->next;
	while (Q->front != Q->rear) {
		delete(Q->front);
		Q->front = p;
		p = Q->front->next;
	}
	Q->front = NULL;
	delete(Q->rear);
	Q->rear = Q->front;
}

Status IsEmptyLQueue(const LQueue* Q)				//�鿴�����Ƿ��
{
	if (Q->length==0) return TRUE;
	return FALSE;
}

Status GetHeadLQueue(LQueue* Q, void** e)		//�õ�ͷԪ��
{
	if (IsEmptyLQueue(Q)) return FALSE;
	*e = Q->front;
	return TRUE;
}

int LengthLQueue(LQueue* Q)						//�õ����г���
{
	return Q->length;
}

Status EnLQueue(LQueue* Q, void* data, char type)			//����Ԫ��
{
	Node* p=new Node;
	p->next = NULL;
	p->data = data;
	p->type = type;
	Q->rear->next = p;
	Q->rear = p;
	++Q->length;
	if (Q->length == 1) {
		Q->front = Q->rear;
	}
	return TRUE;
}

Status DeLQueue(LQueue* Q)									//����ͷԪ��
{
	if (IsEmptyLQueue(Q)) return FALSE;
	Node* p=Q->front;
	Q->front = Q->front->next;
	delete(p);
	--Q->length;
	if (Q->front == NULL) { Q->front = new Node; Q->rear = Q->front; }
	return TRUE;
}

void ClearLQueue(LQueue* Q)									//��ն���
{
	while (!IsEmptyLQueue(Q)) {
		DeLQueue(Q);
	}
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))	//��������
{
	if (IsEmptyLQueue(Q)) return FALSE;
	Node* step = Q->front;
	while (step !=NULL ) {
		foo(step);
		step = step->next;
	}
	return TRUE;
}

void LPrint(void* q)
{
	switch (((Node*)q)->type)
	{
	case 1:
		cout << *((int*)((Node*)q)->data)<<"  ";
		break;
	case 2:
		cout << *((string*)((Node*)q)->data)<<"  ";
		break;
	case 3:
		cout << *((double*)((Node*)q)->data)<<"  ";
		break;
	default:
		break;
	}
}