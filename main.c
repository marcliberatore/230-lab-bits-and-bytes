#include "set.h"
#include <stdio.h>
#include <string.h>

int main() {
  memset(J, 0, sizeof(J)); // set every bit in the array to 0

  // Write your tests here. For example:
  //part1_add_element(1);
  //part1_add_element(24);
  //part1_add_element(51);
  //part2_add_element(66);
  //part2_add_element(-21);
  //etc.

  // an example use of as_binary(); feel free to comment out or change
  // this to help you in your work!
  for (int i = 0; i < N; i++) {
    printf("%d: %s %d\n", i, as_binary(J[i]), J[i]);
  }
  return 0;
}