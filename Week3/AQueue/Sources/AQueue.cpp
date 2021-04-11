#include "AQueue.h"

void InitAQueue(AQueue* Q)			//初始化队列
{
    for (int i = 0; i < Q->length; ++i) {
        Q->data[i] = (void*) malloc(MAXQUEUE);
        Q->front = 0;
        Q->rear = 0;
    }
}

void DestoryAQueue(AQueue* Q)       //销毁队列
{
    for (int i=1;i<Q->length;++i)
    free(Q->data[i]);
    Q->data[0] = NULL;
    return ;
}

Status IsFullAQueue(const AQueue* Q)        //检查队列是否已满
{
    if ((Q->rear+1)%Q->length == Q->front) {          //尾在后
        return TRUE;
    }
    else return FALSE;
}

Status IsEmptyAQueue(const AQueue* Q)       //检查队列是否为空
{
    if ((Q->front) % Q->length == Q->rear ) {
        return TRUE;
    }
    else return FALSE;
}

Status GetHeadAQueue(AQueue* Q, void** e)    //查看队头元素
{
    if (IsEmptyAQueue(Q)) return FALSE;
    *e = Q->data[Q->front];
    return TRUE;
}

int LengthAQueue(AQueue* Q)                 //查看队列长度
{
    if (Q->front < Q->rear) return (Q->rear - Q->front );
    return (Q->rear - Q->front + Q->length);
}

Status EnAQueue(AQueue* Q, void* data)      //入队操作
{
    if (IsFullAQueue(Q)) return FALSE;
    Q->data[Q->rear] = data;
    Q->rear++;
    if (Q->rear == Q->length) Q->rear = 0;
    if (Q->rear == Q->front) {
        cout << "此队列已满，请停止插入" << endl;
        Q->rear--;
    }
    return TRUE;
}

Status DeAQueue(AQueue* Q)                  //出队操作
{
    if (IsEmptyAQueue(Q)) return FALSE;
    Q->front++;
    if (Q->front == Q->length) Q->front = 0;
    return TRUE;
}

void ClearAQueue(AQueue* Q)                 //清空队列
{
    while (!IsEmptyAQueue(Q))                
    {
        DeAQueue(Q);
    }
}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int step))    //遍历函数操作
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

