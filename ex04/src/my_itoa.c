void reverse(char s[], int begin, int end)
 {
     int i, j;
     char c;
     for (i = begin, j = end; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
typedef int bool;
#define true 1
#define false 0

char *my_itoa(int nmb){
  char *out;
  bool check = false;
  int i = 1;
  if (nmb < 0){ nmb = -nmb; check = true; out[0] = '-'; }
  for ( i; nmb != 0; ++i){
    out[i] = nmb % 10;
    nmb /= 10;
  }
  if (check) reverse(out, 1, i);
  else reverse(out, 0, i - 1);
  return out;
}
