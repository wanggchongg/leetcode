// Min Stack Total Accepted: 25665 Total Submissions: 149296 My Submissions Question Solution
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.


//定义一个专门存储最小值的栈
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
	int *top;
	int *base;
	int size;

	int *minTop;
	int *minBase;
	int minSize;
}MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
	stack->base = (int *)malloc(sizeof(int)*maxSize);
	stack->top = stack->base;
	stack->size = maxSize;

	stack->minBase = (int *)malloc(sizeof(int)*10);
	stack->minTop = stack->minBase;
	stack->size = 10;
}

void minStackPush(MinStack *stack, int element) {
	if(stack->top-stack->base >= stack->size)
	{
		stack->base = (int *)realloc(stack->base, (stack->size+1000)*sizeof(int));
		stack->top = stack->base + stack->size;
		stack->size += 1000;
	}
	*stack->top = element;
	stack->top++;

	if(stack->minTop == stack->minBase)
	{
		*stack->minTop = element;
		stack->minTop++;
	}

	if(element <= *(stack->minTop-1))
	{
		if(stack->minTop-stack->minBase >= stack->minSize)
		{
			stack->minBase = (int *)realloc(stack->minBase, (stack->minSize+100)*sizeof(int));
			stack->minTop = stack->minBase + stack->minSize;
			stack->minSize += 100;
		}
		*stack->minTop = element;
		stack->minTop++;
	}
}

void minStackPop(MinStack *stack) {
	if(stack->top == stack->base)
		return;

	if(*(stack->top-1) <= *(stack->minTop-1))
	{
		stack->minTop--;
	}
	stack->top--;
}

int minStackTop(MinStack *stack) {
	if(stack->top == stack->base)
		return INT_MAX;
	return *(stack->top-1);
}

int minStackGetMin(MinStack *stack) {
	if(stack->minTop == stack->minBase)
		return INT_MAX;
	return *(stack->minTop-1);
}

void minStackDestroy(MinStack *stack) {
	free(stack->base);
	stack->top = NULL;
	stack->base = NULL;
	stack->size = 0;

	free(stack->minBase);
	stack->minTop = NULL;
	stack->minBase = NULL;
	stack->minSize = 0;
}

int main()
{
	MinStack stack;
	int element = 0;
	minStackCreate(&stack, 10);
	int i;
	for(i=0; i<500; i++)
	{
		minStackPush(&stack, 0-i);
	}
	printf("top = %d\n", minStackTop(&stack));
	minStackPop(&stack);
	printf("top = %d\n", minStackTop(&stack));
	printf("min = %d\n", minStackGetMin(&stack));
	minStackDestroy(&stack);
	return 0;
}

