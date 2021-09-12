//#pragma once
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <assert.h>

//// 增强程序可维护性
//#define  MAX_SIZE  10000
//typedef int SQDataType;
//// 静态顺序表
//// 问题：给少了不够用，给多了用不完浪费，不能灵活控制
//typedef struct SeqList
//{
//	SQDataType a[MAX_SIZE];
//	int size;
//}SL;
//
////typedef struct SeqList SL;
//
//// 增删查改等接口函数
//void SeqListInit(SL* ps);
//
//// 头插 尾插 头删 尾删
//void SeqListPushBack(SL* ps, SQDataType x);
//void SeqListPushFront(SL* ps, SQDataType x);
//void SeqListPopBack(SL* ps);
//void SeqListPopFront(SL* ps);


// 增强程序可维护性
typedef int SQDataType;
// 动态的
typedef struct SeqList
{
	SQDataType* a;
	int size;     // 有效数据的个数
	int capacity; // 容量
}SL;

//typedef struct SeqList SL;

// 增删查改等接口函数
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);

// 头插 尾插 头删 尾删
void SeqListPushBack(SL* ps, SQDataType x);
void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
void SeqListInsert(SL* ps, int pos, SQDataType x);
void SeqListErase(SL* ps, int pos);

int SeqListFind(SL* ps, SQDataType x);
void SeqListModity(SL* ps, int pos, SQDataType x);


#endif




