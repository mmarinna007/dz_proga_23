#include <stdio.h>

void filling(char* str1, int *counter)
{
  char i = getchar();
  int c = 0;
  for (; i != '\n';) {
      str1[c] = i;
      c++;
      i = getchar();
    }
  str1[c] = '\0';

  *counter = c;
}