#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "tools.h"
#include "CDtor.h"
#include "Push_Pop.h"
#include "get_file.h"
#include "protect.h"

#define STATE err = 
#define CHECK_STATE(text) if(err) end_programm(&test_protect.stack_struct, (text));

// #define str(s) #s
// #define xstr(s) str(s)

int main(int argc, char* argv[]) {

    Stack_struct stack_struct = {};
    Test_protect test_protect = {0, stack_struct, 0};

    test_protect.stack_struct.left_protect = 0xAAAA;
    test_protect.stack_struct.right_protect = 0xFFFF;
    char* name_file = (char*)malloc(32 * sizeof(char));
    int err = 0;
    int size_min = 2;

    // printf("%d, %s\n", check_arg(argc, argv, &stack_struct), argv[1]);
    STATE check_arg(argc, argv, name_file);
    CHECK_STATE("./stack.exe <name_file>") 

    printf("File: %s\n", name_file);

    STATE STACK_CTOR(&test_protect.stack_struct, size_min);
    CHECK_STATE("Init failed") 


    STATE get_num_from_file(&test_protect.stack_struct, name_file);
    CHECK_STATE("Get numbers from file failed") 

    test_protect.left[2] = 123;
    test_protect.stack_struct.data[5] = -10;
    printf("\nTest protect\n");
    // printf("%p %p %p\n", test_protect.left, &test_protect.left[1], &test_protect.stack_struct);
    // Type_protect type_protect = check_wall(&test_protect.stack_struct);
    printf("%d\n", check_wall(&test_protect.stack_struct));

    Dump(&test_protect.stack_struct);
    stack_Dtor(&test_protect.stack_struct);
    Dump(&test_protect.stack_struct);

    printf("\nFinish\n");
    return 0;
}




