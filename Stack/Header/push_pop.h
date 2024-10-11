#ifndef PUSH_POP
#define PUSH_POP

#include "types.h"

int stack_push(Stack_struct*, double);
int stack_pop(Stack_struct*, double*, int);
int change_compacity(Stack_struct*);

#endif