#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


//typedef char LTDataType;
typedef int LTDataType;

// SList
// DList

// 带头双向循环 -- 最有链表结构，任意位置插入删除数据都是O(1)
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListInit();
void ListDestory(ListNode* phead);
void ListPrint(ListNode* phead);

void ListPushBack(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
// pos位置之前插入x
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的值
void ListErase(ListNode* pos);

bool ListEmpty(ListNode* phead);
int ListSize(ListNode* phead);