//
// Created by ritos on 14/12/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>

#include "virtualMachine.h"
#include "stackStructure.h"
#include "heapStructure.h"
#include "torusStructure.h"


//Implementation of vm
void vm(int col, int lines){
    char **pc;
    struct stack *sp;

    //current position
    int pos_x = 0;
    int pos_y = 0;

    //rightwise : >
    int incrY = 0;
    int incrX = 1;

    //arguments and the opcode
    long long int arg1;
    long long int arg2;
    long long int temp;

    char opcode;

    //pointers to grid and stack
    pc = torusInst->items;


    /*Table with opcode and labels*/

    commands['0'] = &&zero;
    commands['1'] = &&one;
    commands['2'] = &&two;
    commands['3'] = &&three;
    commands['4'] = &&four;
    commands['5'] = &&five;
    commands['6'] = &&six;
    commands['7'] = &&seven;
    commands['8'] = &&eight;
    commands['9'] = &&nine;
    commands['+'] = &&add;
    commands['-'] = &&minus;
    commands['/'] = &&div;
    commands['*'] = &&mul;
    commands['%'] = &&mod;
    commands['!'] = &&neg;
    commands['.'] = &&print_int;
    commands[','] = &&print_ascii;
    commands['>'] = &&right;
    commands['<'] = &&left;
    commands['^'] = &&up;
    commands['v'] = &&down;
    commands['?'] = &&random;
    commands['"'] = &&string_mode;
    commands['_'] = &&if_or;
    commands['|'] = &&if_ver;
    commands[':'] = &&duplicate;
    commands['#'] = &&skip;
    commands['$'] = &&pop;
    commands['&'] = &&read_int;
    commands['~'] = &&read_char;
    commands['`'] = &&comparison;
    commands['\\'] = &&swap;
    commands[' '] = &&gap;
    commands['g'] = &&get;
    commands['p'] = &&put;
    commands['c'] = &&con;
    commands['h'] = &&head;
    commands['t'] = &&tail;
    commands['@'] = &&end;


    while(1){

        NEXT_INSTRUCTION;

        switch(opcode) {
            case '0' :
            zero:
                push(0);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '1' :
            one:
                push(1);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '2' :
            two:
                push(2);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '3' :
            three:
                push(3);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '4' :
            four:
                push(4);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '5' :
            five:
                push(5);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '6' :
            six:
                push(6);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '7' :
            seven:
                push(7);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '8' :
            eight:
                push(8);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '9' :
            nine:
                push(9);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '+' :
            add:
                //addition
//                printf("%d\n", opcode);
                arg1 = pop();
                arg2 = pop();
                push(arg1 + arg2);
//                printf("add: %d\n", peek(sp));

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '-' :
            minus:
                //reduction
//                printf("%c\n", opcode);
                arg1 = pop();
                arg2 = pop();
                push(arg2 - arg1);
//                printf("reduction: %d\n", peek(sp));

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '/' :
            div:
                //Integer division
                arg1 = pop();
                arg2 = pop();
                push(arg2 / arg1);
//                printf("div: %d\n", peek(sp));
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '*' :
            mul:
                //multiplication
                arg1 = pop();
                arg2 = pop();
                push(arg1 * arg2);
//                printf("mult: %d\n", peek(sp));
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '%' :
            mod:
                //modulo
//                printf("%c\n", opcode);
                arg1 = pop();
                arg2 = pop();
                push(arg2 % arg1);
//                printf("modulo: %d\n", peek(sp));
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '!' :
            neg:
                //<0 if value non-zero, 1 otherwise>
//                printf("%c\n", opcode);
                temp = pop();
                push(((int)temp == 0));
//                printf("negative: %d\n", peek(sp));
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '.' :
            print_int:
                //print the top of stack as integer
//                printf("%c\n", opcode);
                temp = pop();
                printf("%lld", temp);
//                printf("print int: %d\n", temp);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case ',' :
            print_ascii:
                //print the top of stack in ASCII
//                printf("%c\n", opcode);
//                printf("peek before pop:%c\n", peek(sp));
                temp = pop();
                printf("%c", (char)temp);
//                printf("print char: %c\n", temp);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '>' :
            right:
                //change orientation
//                printf("%c\n", opcode);
                incrY = 0;
                incrX = 1;
                NEXT_CELL;
                NEXT_INSTRUCTION;

                break;
            case '<' :
            left:
                //change orientation
//                printf("%c\n", opcode);
                incrY = 0;
                incrX = -1;

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '^' :
            up:
                //change orientation
//                printf("%c\n", opcode);
                incrY = -1;
                incrX = 0;
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case 'v' :
            down:
                //change orientation
//                printf("%c\n", opcode);
                incrY = 1;
                incrX = 0;
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '?' :
            random:
                //change orientation randomly
//                printf("%c\n", opcode);

                temp = rand() % 4;

                switch(temp) {
                    case 0 :
//                        printf(">\n");
                        incrY = 0;
                        incrX = 1;
                        break;
                    case 1 :
//                        printf("<\n");
                        incrY = 0;
                        incrX = -1;
                        break;
                    case 2 :
//                        printf("^\n");
                        incrY = -1;
                        incrX = 0;
                        break;
                    case 3 :
//                        printf("v\n");
                        incrY = 1;
                        incrX = 0;
                        break;
                }

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '"' :
            string_mode:
                //string mode
//                printf("String start\n");

                //next element
                pos_y += incrY;
                pos_x += incrX;

                //normalize values
                pos_y = (pos_y  + lines) % lines;
                pos_x = (pos_x + col) % col;

                //while current element is not equal to '"'
                //push it into the stack
                while(pc[pos_y][pos_x] != '"'){
//                    printf("to be pushed: %c\n",pc[pos_y][pos_x]);
                    temp = pc[pos_y][pos_x];
                    push(temp);
//                    printf("peek: %c\n",peek(sp));

                    //next element
                    pos_y += incrY;
                    pos_x += incrX;

                    //normalize values
                    pos_y = (pos_y  + lines) % lines;
                    pos_x = (pos_x + col) % col;
                }
//                printf("String stop\n");

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '_' :
            if_or:
//                printf("%c\n", opcode);
//                printf("comp_bef %d\n", (int)peek(sp));
                temp = pop();
//                printf("comp_ %d\n", (int)temp != 0);
                if((int)temp != 0){
//                    printf("continue <\n");
                    incrY = 0;
                    incrX = -1;
                }else{
//                    printf("continue >\n");
                    incrY = 0;
                    incrX = 1;
                }
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '|' :
            if_ver:
//                printf("comp| bef %d\n", (int)peek(sp));
                temp = pop();
//                printf("comp| %d\n", (int)temp != 0);

                if((int)temp != 0){
//                    printf("continue ^\n");
                    incrY = -1;
                    incrX = 0;
                }else{
//                    printf("continue v\n");
                    incrY = 1;
                    incrX = 0;
                }
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case ':' :
            duplicate:
                //duplicate the top element of the stack
//                printf("dup: %lld\n", peek(sp));
                temp = peek(sp);
                push(temp);
//                printf("dup_after: %d\n", peek(sp));

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '#' :
            skip:
                //skip the next command
//                printf("skip\n");
                NEXT_CELL;
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '$' :
            pop:
                //pop a value of the stack
//                printf("pop: %d\n", peek(sp));
                temp = pop();
//                printf("pop: %d\n", temp);

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '&' :
            read_int:
                //input as integer
//                printf("%c\n", opcode);
                scanf(" %lld", &temp);
                push(temp);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '~' :
            read_char:
                //input as ASCII
//                printf("%c\n", opcode);
                scanf(" %c", &temp);
                push(temp);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '`' :
            comparison:
                // print "1" if arg2 is greater than arg2 else "0"
//                printf("%c\n", opcode);
                arg1 = pop();
                arg2 = pop();
                push((arg1 < arg2));
//                printf("compare: %d", peek(sp));
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '\\' :
            swap:
                //swap the two top elements in the stack
//                printf("%c\n", opcode);
//                printf("swap bef: %d\n", peek(sp));
                arg1 = pop();
                arg2 = pop();
                push(arg1);
                push(arg2);
//                printf("swap after: %d\n", peek(sp));
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case ' ' :
            gap:
                //do nothing
//                printf("Gap\n");
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case 'g' :
            get:
                //save to stack the ascii code of the command in the (x,y) point of grid
//                printf("%c\n", opcode);
                arg1 = pop(); //-- y
                arg2 = pop(); //-- x
                temp = pc[arg1][arg2];
                push(temp);
//                printf("p: %c", temp);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case 'p' :
            put:
                //alter the (x,y) point
//                printf("%c\n", opcode);
                arg1 = pop(); //-- y
                arg2 = pop(); //-- x
                temp = pop();
                pc[arg1][arg2] = (char)temp; // in case is an int
//                printf("put: (%lld, %lld) = %c\n",arg1, arg2, temp);
                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case 'c' :
            con:
                //Ending command
//                printf("construct: %c\n", opcode);
                arg2 = pop();
                arg1 = pop();
                temp = (long long int)hp_new(arg1, arg2);
//                printf("construct_ptr: %lld, heap: %lld\n", temp, (long long int)(*(struct cons_cell **)temp));
                push(temp);
//                printf("peek : %lld\n",peek());

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case 'h' :
            head:
                //Ending command
//                printf("Head: %c\n", opcode);
                temp = pop();
//                printf("temp: %lld,\n", temp);

                push(((struct cons_cell*)temp)->a);
//                printf("peek : %lld\n",peek());

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case 't' :
            tail:
                //Ending command
//                printf("Tail: %c\n", opcode);
                temp = pop();
//                printf("temp: %lld\n", temp, (long long int)heapInst->curr_elem);

                push(((struct cons_cell*)temp)->b);
//                printf("peek : %lld\n",peek());

                NEXT_CELL;
                NEXT_INSTRUCTION;
                break;
            case '@' :
            end:
                //Ending command
//                printf("End of program: %c\n", opcode);
                return;
            default:
                printf("Wrong command");
                exit(EXIT_FAILURE);
        }

        //increase the x,y


    }


}
