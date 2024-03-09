// This is the only file that you may modify for PC Lab.

// There are two function defined in this file.  You, as a C S 429H
// student, must write C code to initialize the array "mem" so the
// program in "mem-chase.c" runs both as fast as possible and as
// slow as possible.

#include <stdio.h>
#include <stdlib.h>


void init_data_fast(unsigned long int mem[], unsigned long int size) {
  // Simple, in-order accesses
  printf("Fast\n");
  unsigned long int i;

  for (i = 0; i < size; i++) mem[i] = i+1;
  mem[size-1] = 0;

}

void init_data_slow(unsigned long int mem[], unsigned long int size) {
  printf("Slow, size = %lu\n", size);
  unsigned long int div = 64;
  for (unsigned long int k = 0; k < div; k += 16) {
    for (unsigned long int i = k; i < size - div; i+= div) {
      for (unsigned long int j = 0; j < 16; j++) {
        mem[i + j] = (i + j + div);
        // printf("%lu\n", mem[i+j]);
      }
    }
  }
  for (unsigned long int i = size-div; i < size-16; i++) {
    mem[i] = (i - (size - div) + 16);
    // printf("%lu\n", mem[i]);
  }
  for (unsigned long int i = size-16; i < size; i++) {
    mem[i] = (i - (size - 16) + 1) % 16;
    // printf("%lu\n", mem[i]);
  }
}
