//
// Created by ritos on 14/12/19.
//

#include <stdlib.h>

#include "torusStructure.h"


struct torus* newTorus()
{
    struct torus *pt = (struct torus*)malloc(sizeof(struct torus));

    pt->maxX = 80;
    pt->maxY = 25;


    pt->items = (char**)malloc(sizeof(char*) * pt->maxY);

    for(int i = 0; i < pt->maxY; i++){
        pt->items[i] = (char*)malloc(sizeof(char) * pt->maxX);
    }

    return pt;
}