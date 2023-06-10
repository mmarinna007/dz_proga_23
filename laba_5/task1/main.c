#include <stdio.h>
#include "searcher.h"
#include "filling.h"

int main(void)
{

  char str1[100];
  int counter = 0;
  filling(str1, &counter);
  int result = -1;
  char i;
  do {
    i = getchar();

    result = searcher(counter, str1, i);
    if (result == -1) {
      continue;
    }
    else {
      break;
    }
  } while (i != '\n' && i != '\0');
  printf("%i", result);
  
  return 0;
}