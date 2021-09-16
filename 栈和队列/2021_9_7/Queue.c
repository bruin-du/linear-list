#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);

	while (pq->head)
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->x = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->tail = pq->head = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	if (pq->head == pq->tail)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
		return;
	}
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

}

QDataType QueueTop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->tail->x;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	int x = 0;
	while (cur)
	{
		x++;
		cur = cur->next;
	}
	return x;
}
bool QueueIsEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

