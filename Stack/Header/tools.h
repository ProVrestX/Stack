#ifndef TOOLS
#define TOOLS

#include "types.h"

#define STACK_CTOR(stack_struct, size) \
    stack_ctor((stack_struct), (size), #stack_struct, __FILE__, __LINE__)

int end_programm(Stack_struct*, const char*);
int check_arg(int, char**, char*);
int dump(Stack_struct*);
u_int64_t get_hash(Stack_struct*, int);



#endif