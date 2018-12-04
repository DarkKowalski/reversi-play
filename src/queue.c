#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode (Item item, QNode *pn);
static void CopyToItem (QNode *pn,Item *pi);

void InitializeQueue(Queue *pq)
{
    pq->front = pq ->rear = NULL;
    pq ->items = 0;
}

bool QueueIsFull(const Queue* pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq -> items == 0;
}

int QueueItemCount(const Queue *pq)
{
    return pq ->items;
}

bool EnQueue(Item item, Queue *pq)
{
    QNode *pnew;

    if(QueueIsFull(pq))
        return false;
    pnew = (QNode *)malloc(sizeof(QNode));
    if(pnew == NULL)
    {
        return false;
    }
    CopyToNode(item,pnew);
    pnew ->next=NULL;
    if(QueueIsEmpty(pq))
        pq->front = pnew;
    else
        pq->rear->next = pnew;
    pq->rear=pnew;
    pq ->items ++;

    return true;
}

bool DeQueue(Item *pitem, Queue *pq)
{
    QNode *pt;

    if(QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front,pitem);
    pt = pq->front;
    pq ->front = pq->front->next;
    free(pt);
    pq->items--;
    if(pq->items == 0)
        pq->rear =NULL;
    return true;    
}

void EmptyTheQueue(Queue *pq)
{
    Item dummy;
    while(!QueueIsEmpty(pq))
        DeQueue(&dummy,pq);
}

static void CopyToNode(Item item, QNode *pn)
{
    pn->item = item;
}

static void CopyToItem(QNode *pn, Item *pi)
{
    *pi = pn->item;
}