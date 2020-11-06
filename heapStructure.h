//
// Created by ritos on 5/12/19.
//
#include <stdlib.h>

#ifndef GC_HEAPSTRUCTURE_H
#define GC_HEAPSTRUCTURE_H

/* Global data structures */
struct heap *heapInst;

//cons cell
struct cons_cell
{
    long long int a;
    long long int b;
};


// Data structure for torus
struct heap
{
    long long int max;	// define max capacity of stack
    long long int curr_elem;
    struct cons_cell *from_space;
    struct cons_cell *to_space;
    struct cons_cell *next, *scan;
};

struct heap* newHeap(long long int capacity);

struct cons_cell* hp_new(long long int a, long long int b);

#endif //GC_HEAPSTRUCTURE_H





