#include <stdio.h>
#include <stdbool.h>

bool countChar(char *filename, int *counts, int size) {
  // open a file whose name is filename for reading
  FILE *file = fopen(filename, "r");

  if (file == NULL) { // if fopen fails, return false. Do NOT fclose
    return false;
  }

  // if fopen succeeds, read every character from the file
  int onechar; // store as int to handle characters > 127
  do {
    onechar = getc(file);
    // if a character (call it onechar) is between
    // 0 and size - 1 (inclusive), increase
    // counts[onechar] by one
    // You should *NOT* assume that size is 256
    if (0 <= onechar && onechar < size) {
      counts[onechar] += 1;
    }
  } while (onechar != EOF);

  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file

  fclose(file); // remember to call fclose
  return true;
}

void printCounts(int *counts, int size) { // ind is between 0 and size - 1 (inclusive)
  for (int count_idx = 0; count_idx < size; count_idx++) {
    if (counts[count_idx] > 0) { // if counts[ind] is zero, do not print

      // onechar is printed if ind is between 'a' and 'z' or
      // 'A' and 'Z'. Otherwise, print space
      char onechar = ('a' <= count_idx && count_idx <= 'z') || ('A' <= count_idx && count_idx <= 'Z') ? count_idx : ' ';

      // print the values in counts in the following format
      // each line has three items:
      // ind, onechar, counts[ind]
      printf("%d, %c, %d\n", count_idx, onechar, counts[count_idx]);
    }
  }
}
