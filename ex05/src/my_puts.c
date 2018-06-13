#include <unistd.h>

int my_strlen(const char *str){
  int i = 0;
  for (i = 0; str[i] != '\0'; ++i);
  return i;
}

int my_puts(const char *s) {
  write(1, s, my_strlen(s));
  char n = '\n';
  write(1, &n, 1);
}