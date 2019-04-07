// C-implementation of stack
#include "stack.h"

// function to create a stack of given capacity.
Stack* createStack(unsigned capacity){
	Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    //TODO: Your choice here:
	stack->items = (Bracket*) malloc(stack->capacity * sizeof(Bracket));
	// StackNode* head;
    return stack;
}

// Stack is full when top index is equal to capacity-1
int isFull(Stack* stack){
	//TODO
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1 (or head of the list is NULL)
int isEmpty(Stack* stack){
	//TODO
    return stack->top == -1;
}

// Function to add an item to stack.
void push(Stack* stack, Bracket item){
	if (isFull(stack)){
        return;
    }
    //TODO
    stack->items[stack->top + 1] = item;
    stack->top++;
    return;
}

// Function to remove an item from stack and return it.
Bracket pop(Stack* stack){
	//TODO
	Bracket top = stack->items[stack->top];
    stack->top--;
	return top;
}
