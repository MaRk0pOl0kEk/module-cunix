#include <stdlib.h>
int my_strlen(char *str){
   int i = 0;
   for (i = 0; str[i] != '\0'; ++i){
 }
 return i;
 }

char *my_strcpy(char *dest, char *src) {
  int size = my_strlen(src);
  dest = malloc(size + 1);
  int i = 0;
  for ( i = 0; i < size; ++i){
   dest[i] = src[i];
  }
  dest[i] = '\0';

 return dest;
}
