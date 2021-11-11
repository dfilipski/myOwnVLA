#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct int_vla {
    int* start;
    int* end;
    size_t maxLength;
    size_t length;
    bool isAllocated; 
} INT_VLA;

int vla[1024];

/**
 * Initialize a struct int_vla
 */
void  makeIntegerVLA(INT_VLA* vla) {
    
    vla->start = malloc(vla->maxLength);
    vla->end = vla->start;
    vla->isAllocated = true;
    vla->length=0;

    return ;
}

/**
 * Deallcoate a vla
 * @vla A pointer to a struct int_vla
 * @return true if the memory is deallocated.
 */
bool deallocateVLA(INT_VLA* vla) {

    /*Do nothing if the vla is not allocated*/
    if (vla->isAllocated == false)
        return false;

    free(vla->start);
    vla->isAllocated = false;

    /*We allocated the vla. Return true*/
    return true;
}

/**
 * Add item to array. Return index if successful. Return -1 otherwise.
 */
size_t addIntToVLA(INT_VLA* vla) {

}

int main (void) {

    INT_VLA v;

    makeIntegerVLA(&v);
    return 0;
}
