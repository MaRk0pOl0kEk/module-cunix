#include <stdlib.h>
unsigned int strlen(const char *str){
   unsigned int i = 0;
   for (i = 0; str[i] != '\0'; ++i){
 }
 return i;
 }

char *my_strcpy(char *dest, const char *src) {
  unsigned int size = strlen(src);
  dest = malloc(size);
  unsigned int i = 0;
  for ( i = 0; i < size; ++i){
   dest[i] = src[i];
  }
  dest[i] = '\0';

 return dest;
}
