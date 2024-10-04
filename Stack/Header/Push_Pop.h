#ifndef PUSH_POP
#define PUSH_POP

#include "types.h"

int stack_Push(Stack_struct*, double);
int stack_Pop(Stack_struct*, double*, int);
int change_compacity(Stack_struct*);

#endif