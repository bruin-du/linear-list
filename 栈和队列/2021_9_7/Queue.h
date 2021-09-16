#pragma once
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType x;
}QNode;

typedef struct Queue
{
	QNode* tail;
	QNode* head;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

QDataType QueueTop(Queue* pq);
int QueueSize(Queue* pq);
bool QueueIsEmpty(Queue* pq);