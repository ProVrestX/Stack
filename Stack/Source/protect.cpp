#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "tools.h"

Type_protect check_wall(Stack_struct* stack_struct) {
    u_int64_t hash_check = get_hash(stack_struct, 0);
    printf("%x %x %x %x %lx\n", \
        (int)stack_struct->data[-1], stack_struct->left_protect,\
        stack_struct->right_protect, (int)stack_struct->data[stack_struct->compacity],\
        hash_check);

    if(hash_check != stack_struct->hash) return HASH;

    if(stack_struct->left_protect != 0xAAAA) return LEFT_STRUCT;
    if(stack_struct->right_protect != 0xFFFF) return RIGHT_STRUCT;

    if(stack_struct->data[-1] != 0xAAAA) return LEFT_DATA;
    if(stack_struct->data[stack_struct->compacity] != 0xFFFF) return RIGHT_DATA;

    return ALL_RIGHT;
}