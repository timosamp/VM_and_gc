//
// Created by ritos on 14/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>

#include "heapStructure.h"
#include "stackStructure.h"


// Utility function to initialize torus
struct heap* newHeap(long long int capacity)
{
    struct heap *hp = (struct heap*)malloc(sizeof(struct heap));

    hp->max = capacity/2;

    hp->curr_elem =  -1;

    hp->from_space = (struct cons_cell*)malloc(sizeof(struct cons_cell) * (capacity/2));
    hp->to_space = (struct cons_cell*)malloc(sizeof(struct cons_cell) * (capacity/2));

    return hp;

}



struct cons_cell* forward(struct cons_cell *p)
{
    /* Check if the address that is saved in roots belongs in the from-space */
    if(((long long int)p >= (long long int)heapInst->from_space) && ((long long int)p <= (long long int)(heapInst->from_space + heapInst->curr_elem)))
    {

        /* Check if p->a is an address points in the to-space */
        if((p->a >= (long long int)heapInst->to_space) && (p->a < (long long int)(heapInst->next)))
        {
            /* Then the object has already been copied */
            return (struct cons_cell*)p->a;
        }else{
            /* Otherwise has not been copied and so copy it in the to-space*/


            heapInst->next->a = p->a;
            heapInst->next->b = p->b;

            /* Make p->a points in the new address in heap */
            p->a = (long long int)heapInst->next;

            heapInst->next += 1;

            /* Return new address in heap*/
            return (struct cons_cell*)p->a;
        }
    }else{
//        printf("simple integer\n");

        /*if it's not an address in heap, means that it's a simple integer */
        return p;
    }
}



void forward_roots(){

    for(long long int i = stackInst->top; i >= 0; i--)

        if((stackInst->items[i] >= (long long int)heapInst->from_space) && \
                    (stackInst->items[i] <= (long long int)(heapInst->from_space + heapInst->curr_elem))){
            (void)forward((struct cons_cell *)(stackInst->items[i]));
        }

}


void correct_stack(){
    for(long long int i = stackInst->top; i >= 0; i--)

        if((stackInst->items[i] >= (long long int)heapInst->from_space) && \
                    (stackInst->items[i] <= (long long int)(heapInst->from_space + heapInst->curr_elem))){
            stackInst->items[i] = ((struct cons_cell *)(stackInst->items[i]))->a;
        }

}


void gc_func()
{

    /*Init next and scan in the beginning of the to_space*/
    heapInst->next = heapInst->scan = heapInst->to_space;


    forward_roots();

    /* Recursively forward their children */
    while(heapInst->scan < heapInst->next){

        heapInst->scan->a = (long long int)forward((struct cons_cell*)heapInst->scan->a);
        heapInst->scan->b = (long long int)forward((struct cons_cell*)heapInst->scan->b);

        heapInst->scan += 1;

    }

    /* Init curr_elem to the last one of the new heap */
    heapInst->curr_elem = ((long long int)heapInst->next - 1 - (long long int)heapInst->to_space) / (long long int)sizeof(struct cons_cell);

    /* Correct Stack with the new values */
    correct_stack();

    /* swap from_space and to_space */
    struct cons_cell *temp;
    temp = heapInst->from_space;
    heapInst->from_space =  heapInst->to_space;
    heapInst->to_space = temp;

}

// Utility function to add an element x in the stack
inline struct cons_cell* hp_new(long long int a, long long int b)
{
    struct cons_cell temp;

    /* check if heap is already full.*/
    if (heapInst->curr_elem == heapInst->max)
    {
        /* garbage collection time */
//        printf("\nGarbage collector starts\n");
//        clock_t start = clock();
        gc_func();
//        printf("\nGarbage collector stops\n");
//        clock_t stop = clock();
//        double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
//        printf("\nGC in: %.5f sec\n", elapsed);
    }

    /*If arg1 arg2 are pointer in roots then take their values for pointing in heap*/
    temp.a = a;
    temp.b = b;
    heapInst->from_space[++heapInst->curr_elem] = temp;

    /* Return the address of roots that holds the real allocated address in heap */
    return heapInst->from_space + heapInst->curr_elem;
}

