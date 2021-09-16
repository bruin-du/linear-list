#include"Stack.h"
#include"Queue.h"

//void test1()
//{
//	Stack stack;
//	StackInit(&stack);
//
//	StackPush(&stack, 1);
//	StackPush(&stack, 2);
//	StackPush(&stack, 3);
//	StackPush(&stack, 4);
//	StackPush(&stack, 5);
//	StackPop(&stack);
//	StackPop(&stack);
//
//
//	while (!StackIsEmpty(&stack))
//	{
//		printf("%d ", StackTop(&stack));
//	}
//
//	StackDestory(&stack);
//}
//
//void test2()
//{
//	Queue queue;
//	QueueInit(&queue);
//	QueuePush(&queue, 1);
//	QueuePush(&queue, 2);
//	QueuePush(&queue, 3);
//	QueuePush(&queue, 4);
//	QueuePush(&queue, 5);
//
//	printf("%d\n", QueueSize(&queue));
//
//	while (!QueueIsEmpty(&queue))
//	{
//		printf("%d ", QueueTop(&queue));
//		QueuePop(&queue);
//	}
//
//
//	QueueDestory(&queue);
//}



/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&queue->s1);
    StackInit(&queue->s2);
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    assert(obj);

    if (StackIsEmpty(&obj->s1))
    {
        StackPush(&obj->s2, x);
    }
    else
    {
        StackPush(&obj->s1, x);
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    assert(obj);

    Stack* emp = &obj->s1;
    Stack* noemp = &obj->s2;

    if (StackIsEmpty(&obj->s2))
    {
        emp = &obj->s2;
        noemp = &obj->s1;
    }
    int x = noemp->a[0];
    if (noemp->top != 1)
    {
        int i = 1;
        while (noemp->a[i] != noemp->a[noemp->top - 1])
        {
            StackPush(emp, noemp->a[i++]);
        }
        StackPush(emp, noemp->a[i++]);
        while (!StackIsEmpty(noemp))
        {
            StackPop(noemp);
        }
        return x;
    }
    StackPop(noemp);
    return x;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    assert(obj);
    if (StackIsEmpty(&obj->s1))
    {
        return StackTop(&obj->s2);
    }
    return StackTop(&obj->s1);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    return StackIsEmpty(&obj->s1) && StackIsEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    assert(obj);

    StackDestory(&obj->s1);
    StackDestory(&obj->s2);
    free(obj);
}

int main(void)
{
    MyQueue* queue = myQueueCreate();
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    myQueuePush(queue, 3);
    myQueuePush(queue, 4);
    printf("%d ", myQueuePop(queue));
    myQueuePush(queue, 5);
    printf("%d ", myQueuePop(queue));
    printf("%d ", myQueuePop(queue));
    printf("%d ", myQueuePop(queue));
    printf("%d ", myQueuePop(queue));
    printf("%d ", myQueueEmpty(queue));

    myQueueFree(queue);

	system("pause");
	return 0;
}