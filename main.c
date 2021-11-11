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

/**
 * Initialize a struct int_vla
 */
void  makeIntegerVLA(INT_VLA* vla) {
    
    vla->start = malloc(vla->maxLength);
    vla->end = vla->start;
    vla->isAllocated = true;

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
size_t addIntToVLA(INT_VLA* vla, int num) {
    size_t length = (int) (vla->end - vla->start)/sizeof(int);

    /*If there is no more room for elements add no more elements*/
    if (length == vla->maxLength)
        return -1;

    /*We are safe to add an element*/
    vla->end += sizeof(int);
    vla->end[0] = num;
    
    return length+1; //
}

/*Return the ith element of vla*/
int getFromVLA(INT_VLA* vla, int i) {
    return vla->start[i];
}

int main (void) {

    INT_VLA* v;

    makeIntegerVLA(v);
    return 0;
}
