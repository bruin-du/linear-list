#pragma once
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdbool.h>

typedef int StackDataType;

typedef struct Stack
{
	StackDataType* a;
	int top;
	int capacity;
}Stack;

typedef struct {
	Stack s1;
	Stack s2;
} MyQueue;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps,StackDataType x);
void StackPop(Stack* ps);

StackDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackIsEmpty(Stack* ps);