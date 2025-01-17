#include <stdio.h>
#include <stdbool.h>

bool addFile(char *filename, int *sum) {
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  *sum = 0;

  // open a file whose name is filename for reading
  FILE *file = fopen(filename, "r");

  if (file == NULL) { // if fopen fails, return false. Do NOT fclose
    return false;
  }
  // if fopen succeeds, read integers using fscan (do not use fgetc)

  // * sum stores the result of adding all numbers from the file
  // if fopen succeeds, read every character from the file
  int val;
  int read_ok;
  do {
    read_ok = fscanf(file, "%d", &val);
    if (read_ok != EOF) {
      *sum += val;
    }
  } while (read_ok != EOF);

  // When no more numbers can be read, fclose, return true
  fclose(file);
  return true;
}

bool writeSum(char *filename, int sum) {
  // open a file whose name is filename for writing
  FILE *file = fopen(filename, "w");

  if (file == NULL) { // if fopen fails, return false. Do NOT fclose
    return false;
  }

  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  fprintf(file, "%d\n", sum);

  // fclose, return true
  fclose(file);
  return true;
}