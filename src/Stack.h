#ifndef STACK_H_
#define STACK_H_

typedef struct{
	char dummy;
}Stack;

Stack *stackNew(void);
void push(Stack *stack, void *data);
void *pop(Stack *stack);

#endif