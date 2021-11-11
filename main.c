#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct int_vla {
    int* start;
    int* end;
    size_t length;
    size_t lastAddedIndex; 
    bool isAllocated; 
} INT_VLA;


/*Should I do it this way? or should I create the struct when I create the VLA?
 * Make it work first.*/

/**
 * Initialize a struct int_vla
 */
void  makeIntegerVLA(INT_VLA* vla, size_t length) {
    vla->start = (int*) calloc(length, sizeof(int));
    vla->end = vla->start + 1;
    vla->isAllocated = true;
    vla->length = 1;
    vla->lastAddedIndex = -1;/*This way. when adding first index we get 1*/
}

/**
 * Deallocate a vla
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

    if (vla->lastAddedIndex+1 > vla->length) {
        /*Must grow the array yepee!! */
        vla->start = (int*) realloc(vla->start, vla->length+1*sizeof(int));
    }

    vla->start[vla->lastAddedIndex+1] = num;
    vla->lastAddedIndex += 1;
    
    return vla->lastAddedIndex;
}

/*Return the ith element of vla*/
int getFromVLA(INT_VLA* vla, int i) {
    return vla->start[i];
}

int main (void) {

	int len = 4;

    INT_VLA v;

    makeIntegerVLA(&v, 1);

	/*Test adding numbers*/
	for (int i = 0; i < len; i++)
	{
		addIntToVLA(&v, i%4);
        printf("Added %dth 4 to vla\n", i);
	}

	/*Test getting Numbers*/
    for (int i = 0; i < len; i++) {
  	    printf("%d: %d\n", i, v.start[i]);
  	}

    deallocateVLA(&v);

    return 0;
}
