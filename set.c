#include <stdlib.h>
#include <string.h>
#include "set.h"

// Convert an unsigned integer to its human-readbable binary representation.
// In a "real" program you'd need to free the memory allocated for the string,
// or you'd need to pass in a pointer to a buffer you'd already allocated.
// But here, you can just leak the memory.
char* as_binary(unsigned int n) {
    char* s = malloc(33);
    s[32] = '\0';
    for (int i = 0; i < 32; i++) {
        s[31-i] = (n & (1 << i)) ? '1' : '0';
    }
    return s;
}

// Add an element with index v to the set I.
// Returns -1 if v is negative or beyond the maximum capacity of the set.
// Returns 0 if v is already in the set.
// Returns 1 if v is successfully added.
int part1_add_element(int v) {
    return 0;
}

// Remove an element with index v from the set I.
// Returns -1 if v is negative or beyond the maximum capacity of the set.
// Returns 0 if v is already not in the set.
// Returns 1 if v is successfully removed.
int part1_remove_element(int v) {
    return 0;
}

// Checks if an element with index v is contained in the set I.
// Returns -1 if v is negative or beyond the maximum capacity of the set.
// Returns 0 if v is not in the set.
// Returns 1 if v is in the set.
int part1_contains_element(int v) {
    return 0;
}

// Add an element with index v to the set J.
// Returns -1 if v is negative or beyond the maximum capacity of the set.
// Returns 0 if v is already in the set.
// Returns 1 if v is successfully added.
int part2_add_element(int v) {
    return 0;
}

// Remove an element with index v from the set J.
// Returns -1 if v is negative or beyond the maximum capacity of the set.
// Returns 0 if v is already not in the set.
// Returns 1 if v is successfully removed.
int part2_remove_element(int v) {
    return 0;
}

// Checks if an element with index v is contained in the set J.
// Returns -1 if v is negative or beyond the maximum capacity of the set.
// Returns 0 if v is not in the set.
// Returns 1 if v is in the set.
int part2_contains_element(int v) {
    return 0;
}

