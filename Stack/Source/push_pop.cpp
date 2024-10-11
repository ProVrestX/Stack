#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "tools.h"
#include "cdtor.h"
#include "push_pop.h"

int stack_push(Stack_struct* stack_struct, double number) {
    if(stack_struct->size < 0 || stack_struct->size >= stack_struct->compacity) return 1;

    *(stack_struct->data + stack_struct->size) = number;
    stack_struct->size++;

    change_compacity(stack_struct);
    get_hash(stack_struct, 1);

    return 0;
}

int stack_pop(Stack_struct* stack_struct, double* number, int pop) {
    if(stack_struct->size <= 0) return 1;

    *number = *(stack_struct->data + stack_struct->size - 1);
    if(pop) stack_struct->size--;

    change_compacity(stack_struct);
    get_hash(stack_struct, 1);        

    return 0;
}

int change_compacity(Stack_struct* stack_struct){
    if(stack_struct->size == 0) 
        {if( STACK_CTOR(stack_struct, 2) ) return 1;}
    
    else if(stack_struct->size >= stack_struct->compacity) 
        {if( STACK_CTOR(stack_struct, stack_struct->compacity * 2) ) return 1;}

    else if(stack_struct->compacity > 2 && stack_struct->compacity / stack_struct->size >= 4) 
        {if( STACK_CTOR(stack_struct, stack_struct->compacity / 2) ) return 1;}

    return 0;
}