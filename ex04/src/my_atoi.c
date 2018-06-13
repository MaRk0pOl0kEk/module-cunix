#include <stdio.h>
#include <ctype.h>

int my_strlen(const char *str){
    int i = 0;
    for (i = 0; str[i] != '\0'; ++i){
    }
    return i;
 }

int my_atoi(const char *nptr){

  if(!my_strlen(nptr))
    return 0;

  int res = 0;
  short int negative = 0;

  if (nptr[0] == '-')
    negative = 1;

  for (int i = negative; i < my_strlen(nptr); i++){
    if (isdigit(nptr[i]))
        res = res * 10 + (int)nptr[i] - (int)'0';
    else
      break;
  }

  if (negative == 1)
    res = (-1) * res;
  return res;
  return 0;
  }

