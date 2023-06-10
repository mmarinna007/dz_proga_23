int searcher(int counter, char* str1, char i) {
  int j = 0;
  for (j; j < counter; j++) {
    if (str1[j] == i) {
      return j;
    }
    else {
            // переход на след. в 1ой строки
    }
  }
  return -1;
}