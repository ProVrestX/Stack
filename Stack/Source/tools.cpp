#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "tools.h"
#include "push_pop.h"
#include "cdtor.h"

int end_programm(Stack_struct* stack_struct, const char* exit_text) {
    printf("%s\n", exit_text);
    stack_dtor(stack_struct);
    exit(1);
}

int check_arg(int argc, char** argv, char* name_file) {
    if(argc == 1) return 1;

    memcpy(name_file, *(argv + 1), 32);
    // name_file = *(argv + 1);
    return 0;
}

int dump(Stack_struct* stack_struct) {
    NO_DEBUG(printf("No DEBUG\n"));

    ON_DEBUG(
        printf("\n Dump\nName: %s (%p)\nFile: %s\nLine: %d\n", stack_struct->name,stack_struct, stack_struct->file, stack_struct->line);
        printf("Size: %ld\nCompacity: %ld\n", stack_struct->size, stack_struct->compacity);
        printf("Hash: %lx\n", stack_struct->hash);
        printf(" Data: \n");

        int size = stack_struct->size;
        double num = 0;
        for(int pos = 0; pos < size; pos++){
            printf("*[%d]: %lf\n", pos, stack_struct->data[pos]);
        }
    );

    return 0;
}

u_int64_t get_hash(Stack_struct* stack_struct, int write) {
    u_int64_t hash = 5381;

    for(int data_pos = 0; data_pos < stack_struct->size; data_pos++) {
        hash = ((hash << 5) + hash) + stack_struct->data[data_pos];
    }
    if(write) stack_struct->hash = hash;

    return hash;
}