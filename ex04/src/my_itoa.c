typedef int bool;
#define true 1
#define false 0
#include <stdlib.h>
#include <string.h>
#include "stdio.h"
void reverse(char *s, int beg, int en);

char *my_itoa( int nmb ){
  char *out = malloc(12 * sizeof(char *));
  if ( nmb == 0 )
  {
    *(out) = '0';
    out[1] = '\0';
    return out;
  }
  bool negative = false;
  int i = 0;
  if (nmb < 0)
    {
      nmb = -nmb;
      negative = true;
    }
  for (; nmb != 0; ++i){
    out[i] = (char)(nmb % 10 + (int)'0');
    nmb /= 10;
    //printf("%s\n", out);
  }


  if (negative)
  {
    out[i++] = '-';
   }
    reverse(out, 0, i - 1);
    out[i + 1] = '\0';
    return out;
}

void reverse(char *s, int beg, int en)
{
   char *begin, *end, temp;

   begin  = s + beg;
   end    = s + en;

   for (; begin <= end ; begin++, end--)
   {
      temp   = *end;
      *end   = *begin;
      *begin = temp;
   }
}
