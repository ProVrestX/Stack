#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "tools.h"
#include "cdtor.h"

int stack_ctor(Stack_struct* stack_struct, size_t size_stack, const char* name_stack, const char* file_stack, int line_stack) {

    NO_DEBUG(printf("\n Init %ld\n", size_stack)); 
    ON_DEBUG(printf("\n Init %ld [Stack: %s (%p), File: %s, Line: %d]\n", size_stack, name_stack, stack_struct, file_stack, line_stack)); 

    ON_DEBUG(stack_struct->name = (char*)name_stack);
    ON_DEBUG(stack_struct->file = (char*)file_stack);
    ON_DEBUG(stack_struct->line = line_stack);

    stack_struct->data = ((double*)realloc(stack_struct->data + ((stack_struct->data)? -1: 0), (size_stack + 2) * sizeof(double)) + 1);
    // stack_struct->data = (double*)realloc(stack_struct->data, (size_stack + 2) * sizeof(double));
    if(stack_struct->data == NULL) return 1;

    stack_struct->compacity = size_stack;

    stack_struct->data[-1] = 0xAAAA;
    stack_struct->data[stack_struct->compacity] = 0xFFFF;
    // printf("%x %x\n", (int)stack_struct->data[-1], (int)stack_struct->data[stack_struct->compacity]);


    return 0;
}

void stack_dtor(Stack_struct* stack_struct) {
    if(stack_struct->data == NULL) return ;
    
    printf(" Dtor\n");

    free(stack_struct->data - 1);
    stack_struct->size = 0;
    stack_struct->compacity = 0;
    stack_struct->hash = 0;

    ON_DEBUG(stack_struct->name = NULL);
    ON_DEBUG(stack_struct->file = NULL);
    ON_DEBUG(stack_struct->line = 0);

    return ;
}