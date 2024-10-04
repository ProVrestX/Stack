#ifndef CDTOR
#define CDTOR

#include "types.h"

int stack_Ctor(Stack_struct*, size_t, const char*, const char*, int);
void stack_Dtor(Stack_struct*);

#endif