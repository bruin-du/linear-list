#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
}

void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	ListInsert(phead, x);
}

//void ListPushFront(ListNode* phead, LTDataType x)
//{
//	assert(phead);
//
//	ListNode* first = phead->next;
//	ListNode* newnode = BuyListNode(x);
//
//	// phead newnode first
//	phead->next = newnode;
//	newnode->prev = phead;
//	newnode->next = first;
//	first->prev = newnode;
//}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//phead->next->prev = newnode;

	//phead->next = newnode;
	//newnode->prev = phead;

	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);

	//ListNode* first = phead->next;
	//ListNode* second = first->next;
	//phead->next = second;
	//second->prev = phead;

	//free(first);
	//first = NULL;

	ListErase(phead->next);
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	/*assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;

	prev->next = phead;
	phead->prev = prev;

	free(tail);
	tail = NULL;*/

	ListErase(phead->prev);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// pos位置之前插入x
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

// 删除pos位置的值
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}