#include "set.h"
#include <stdio.h>
#include <string.h>

int main() {
  memset(J, 0, sizeof(J)); // set every bit in the array to 0
  for (int i = 0; i < N; i++) {
    printf("%d ", J[i]);
  }
  printf("\n");
  return 0;
}
