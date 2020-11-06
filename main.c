//
// Created by ritos on 3/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <time.h>

//My head files
#include "stackStructure.h"
#include "torusStructure.h"
#include "heapStructure.h"
#include "virtualMachine.h"


#define new_max(x,y) ((x) >= (y)) ? (x) : (y)



// main function
int main(int argc, char **argv)
{
//    clock_t start = clock();

    // create a stack of capacity 10 and the grid-torus
    stackInst = newStack(1048576); //2^20 = 1048576
    torusInst = newTorus();
    heapInst = newHeap(16777216); //2^24 = 16777216

    // Use current time as seed for random generator
    srand(time(0));

    //insert the input to torus
    FILE *file;
    char c;// = *(char*)malloc(1);


    char buf[255];
    strcpy(buf,argv[1]);
//    strcat(buf,"pp.b");

    for(int y = 0; y < 25; y++){
        for(int x = 0; x < 80; x++)
        {
            torusInst->items[y][x] = ' ';
        }
    }

    int y = 0;
    int x = 0;
    int col = 0;
    int lines = 0;

    file = fopen(buf, "r");

    if (file) {

        while ((fread(&c, 1, sizeof(char), file)) > 0){
//            printf("\nallagi \n");
//            printf("[%d, %d]", i, j);

            if(c != '\n')
            {
                //read in the same line
//                printf("%c", c);
                torusInst->items[y][x] = c;
                x++;
            }else{
                //new line
//                printf("\n");
                col = new_max(col, x);
                y++;
                x = 0;
            }
        }

        fclose(file);
    }else{
        exit(EXIT_FAILURE);
    }

    //last line before eof
    lines=y;


    /* Verifying reading */

//    printf("%d, %d",lines,col);
//
//    for(int y = 0; y < lines ; y++)
//    {
//        printf("\n");
//        for(int x = 0; x < col; x++)
//            printf("%c", torusInst->items[y][x]);
//
//    }
//    printf("\n\n");


    /* call the vm */
    vm(col, lines);

//    clock_t stop = clock();
//    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
//    printf("\nTime elapsed: %.5f\n", elapsed / (double) 60.0);

    return 0;
}
