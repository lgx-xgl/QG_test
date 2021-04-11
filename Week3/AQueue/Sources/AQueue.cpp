#include "AQueue.h"

void InitAQueue(AQueue* Q)			//��ʼ������
{
    for (int i = 0; i < Q->length; ++i) {
        Q->data[i] = (void*) malloc(MAXQUEUE);
        Q->front = 0;
        Q->rear = 0;
    }
}

void DestoryAQueue(AQueue* Q)       //���ٶ���
{
    for (int i=1;i<Q->length;++i)
    free(Q->data[i]);
    Q->data[0] = NULL;
    return ;
}

Status IsFullAQueue(const AQueue* Q)        //�������Ƿ�����
{
    if ((Q->rear+1)%Q->length == Q->front) {          //β�ں�
        return TRUE;
    }
    else return FALSE;
}

Status IsEmptyAQueue(const AQueue* Q)       //�������Ƿ�Ϊ��
{
    if ((Q->front) % Q->length == Q->rear ) {
        return TRUE;
    }
    else return FALSE;
}

Status GetHeadAQueue(AQueue* Q, void** e)    //�鿴��ͷԪ��
{
    if (IsEmptyAQueue(Q)) return FALSE;
    *e = Q->data[Q->front];
    return TRUE;
}

int LengthAQueue(AQueue* Q)                 //�鿴���г���
{
    if (Q->front < Q->rear) return (Q->rear - Q->front );
    return (Q->rear - Q->front + Q->length);
}

Status EnAQueue(AQueue* Q, void* data)      //��Ӳ���
{
    if (IsFullAQueue(Q)) return FALSE;
    Q->data[Q->rear] = data;
    Q->rear++;
    if (Q->rear == Q->length) Q->rear = 0;
    if (Q->rear == Q->front) {
        cout << "�˶�����������ֹͣ����" << endl;
        Q->rear--;
    }
    return TRUE;
}

Status DeAQueue(AQueue* Q)                  //���Ӳ���
{
    if (IsEmptyAQueue(Q)) return FALSE;
    Q->front++;
    if (Q->front == Q->length) Q->front = 0;
    return TRUE;
}

void ClearAQueue(AQueue* Q)                 //��ն���
{
    while (!IsEmptyAQueue(Q))                
    {
        DeAQueue(Q);
    }
}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int step))    //������������
{
    if (IsEmptyAQueue(Q)) return FALSE;
    int step = Q->front;
    while (step != Q->rear) {
        foo(Q->data[step],step);
        ++step;
        if (step == Q->length) step = 0;
    }
    return TRUE;
}

