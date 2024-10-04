#ifndef TYPES
#define TYPES

#include <stdlib.h>

#define DEBUG

#ifdef DEBUG
    #define ON_DEBUG(code) code
    #define NO_DEBUG(code) 
#else
    #define ON_DEBUG(code)
    #define NO_DEBUG(code) code
#endif

typedef double Stack_element;

typedef enum Type_protect {
    LEFT_DATA = -2,
    LEFT_STRUCT = -1,
    ALL_RIGHT = 0,
    RIGHT_STRUCT = 1,
    RIGHT_DATA = 2,
    HASH = 3
} Type_protect;

typedef struct Stack_struct {
    int left_protect;
    Stack_element* data;
    size_t size;
    size_t compacity;
    ON_DEBUG(char* name);
    ON_DEBUG(char* file);
    ON_DEBUG(int line);
    u_int64_t hash;
    int right_protect;
} Stack_struct;

typedef struct Test_protect {
    int left[1];
    Stack_struct stack_struct;
    int right[1];
} Test_protect;


#endif