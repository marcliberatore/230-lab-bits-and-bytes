#ifndef __SET
#define __SET

#define N 100

// A single integer that tallies elements in a bitset of at most 32 elements.
unsigned int I;

// An array of unsigned integers that keeps a tally of what elements are
// contained in the set. The total number of elements it can keep track of
// is N x 32.
unsigned int J[N]; 

char* as_binary(unsigned int n);

int part1_add_element(int v);
int part1_remove_element(int v);
int part1_contains_element(int v);

int part2_add_element(int v);
int part2_remove_element(int v);
int part2_contains_element(int v);

#endif
