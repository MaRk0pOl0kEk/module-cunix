#include <stdio.h>
#include <ctype.h>

unsigned int my_strlen(const char *str){
    unsigned int i = 0;
    for (i = 0; str[i] != '\0'; ++i){
    }
    return i;
 }

int my_atoi (const char *nptr){
  if(!my_strlen(nptr))
    return 0;

  unsigned int res = 0;
  short int negative = 0;

  if (nptr[0] == '-')
    negative = 1;

  for (unsigned int i = my_strlen(nptr) - 1; i > 0; --i){
    if (isdigit(nptr[i]))
      res = res * 10 + nptr[i];
    else
      return 0;
  }

  if (negative == 1)
    res = -res;

  return res;
  }
