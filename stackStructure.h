//
// Created by ritos on 5/12/19.
//

#ifndef GC_STACKSTRUCTURE_H
#define GC_STACKSTRUCTURE_H

/* Global data structures */
struct stack *stackInst;


// Data structure for stack
struct stack
{
    long long int maxsize;	// define max capacity of stack
    long long int top;
    long long int *items;
};

// Utility function to initialize stack
struct stack* newStack(long long int capacity);

void push(long long int x);
long long int pop();
long long int peek();

#endif //GC_STACKSTRUCTURE_H
