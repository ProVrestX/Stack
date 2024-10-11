#ifndef CDTOR
#define CDTOR

#include "types.h"

int stack_ctor(Stack_struct*, size_t, const char*, const char*, int);
void stack_dtor(Stack_struct*);

#endif