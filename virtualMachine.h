//
// Created by ritos on 5/12/19.
//

#ifndef GC_VIRTUALMACHINE_H
#define GC_VIRTUALMACHINE_H




#define NEXT_INSTRUCTION \
    opcode = pc[pos_y][pos_x]; \
    goto *(void *)(commands[opcode]);

#define NEXT_CELL  \
    pos_y += incrY; \
    pos_x += incrX; \
    pos_y = (pos_y  + lines) % lines; \
    pos_x = (pos_x + col) % col;


static void *commands[255];

void vm(int col, int lines);

#endif //GC_VIRTUALMACHINE_H

