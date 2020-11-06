//
// Created by ritos on 5/12/19.
//

#ifndef GC_TORUSSTUCTURE_H
#define GC_TORUSSTUCTURE_H

/* Global data structures */
struct torus *torusInst;

// Data structure for torus
struct torus
{
    int maxX;	// define max capacity of stack
    int maxY;
    char **items;
};

// Utility function to initialize torus
struct torus* newTorus();

#endif //GC_TORUSSTUCTURE_H
