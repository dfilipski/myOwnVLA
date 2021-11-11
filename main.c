#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct int_vla {
    int* start;
    int* end;
    size_t maxLength;
    bool isAllocated; 
} INT_VLA;

int vla[1024];

/**
 * Initialize a struct int_vla
 */
void  makeIntegerVLA(INT_VLA* vla) {
    
    vla.start = malloc(maxLength);
    vla.end = start + sizeof(int);

    /*return the struct*/
    return ;
}

/**
 * Deallcoate a vla
 */

int main (void) {

    return 0;
}
