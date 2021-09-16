#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->a = (StackDataType*)malloc(sizeof(StackDataType) * 4);
	if (ps->a)
	{
		ps->capacity = 4;
		ps->top = 0;
	}
	else
	{
		printf("malloc fail\n");
		exit(-1);
	}
}

void StackDestory(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackPush(Stack* ps, StackDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		StackDataType* newstack = (StackDataType*)realloc(ps->a, sizeof(StackDataType) * 2 * ps->capacity);
		if (newstack)
		{
			ps->capacity *= 2;
			ps->a = newstack;
		}
		else
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top);
	--ps->top;
}

StackDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->a[ps->top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}
bool StackIsEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}