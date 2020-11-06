//
// Created by ritos on 14/12/19.
//

#include <stdio.h>
#include <stdlib.h>


#include "stackStructure.h"


struct stack* newStack(long long int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (long long int*)malloc(sizeof(long long int) * capacity);

    return pt;
}


// Utility function to add an element x in the stack
inline void push(long long int x)
{
    // check if stack is already full. Then inserting an element would
    // lead to stack overflow
    if (stackInst->top == stackInst->maxsize - 1)
    {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

//    printf("Inserting_int %d\n", x);
//    printf("Inserting_char %c\n", x);

    // add an element and increments the top index
    stackInst->items[++stackInst->top] = x;
}

// Utility function to return top element in a stack
inline long long int peek()
{
    // check for empty stack
    if (stackInst->top != -1)
        return stackInst->items[stackInst->top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to pop top element from the stack
inline long long int pop()
{
    // check for stack underflow
    if (stackInst->top == -1)
    {
        printf("UnderFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

//    printf("Removing_int %d\n", peek(pt));
//    printf("Removing_char %c\n", peek(pt));

    // decrement stack size by 1 and (optionally) return the popped element
    return stackInst->items[stackInst->top--];
}

// Utility function to check if the stack is empty or not
//int isEmpty()
//{
//    return stackInst->top == -1;	// or return size(pt) == 0;
//}

// Utility function to check if the stack is full or not
//int isFull()
//{
//    return stackInst->top == stackInst->maxsize - 1;	// or return size(pt) == pt->maxsize;
//}