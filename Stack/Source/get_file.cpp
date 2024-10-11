#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "tools.h"
#include "push_pop.h"

#define STATE err = 
#define CHECK_STATE(text) if(err) end_programm(stack_struct, text);

/*
int get_file(FILE** stack_file, const char* name_file) {
    *stack_file = fopen(name_file, "r");
    // if(stack_file == NULL) printf("err1\n");
    if(stack_file == NULL) return 1;
    return 0;
}
*/

int get_num_from_file(Stack_struct* stack_struct, char* name_file) {
    int err = 0;

    // printf("%s\n", name_file);
    FILE* stack_file = fopen(name_file, "r");
    if(stack_file == NULL) {printf("Can`t open file\n"); return 1;}

    double number = 0;
    while (fscanf(stack_file, "%lf", &number) == 1) {
        if(stack_push(stack_struct, number) == 1) return 1;

        double getNum = 0;
        STATE stack_pop(stack_struct, &getNum, 0);
        CHECK_STATE("Get number failed") 

        printf("%.3lf  ", getNum);
        printf("%ld %ld\n", stack_struct->size, stack_struct->compacity);
    }

    if(stack_struct->size == 0) return 1;
    fclose(stack_file);

    return 0;
}