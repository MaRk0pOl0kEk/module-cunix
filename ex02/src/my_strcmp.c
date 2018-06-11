unsigned int strlen(char *str){
  unsigned int i = 0;
     for (i = 0; str[i] != '\0'; ++i){
  }
  return i;
}

typedef int bool;
#define true 1
#define false 0
int my_strcmp(char *str1, char *str2){
  bool check = false;
  unsigned int size = strlen(str1);
    if (strlen (str2) > strlen(str1) ){
      check = true;
      size = strlen (str2);
    }
  for (int i = 0; i < size; ++i){
    if ( str1[i] > str2[i] ) return 1;
    if ( str1[i] < str2[i] ) return -1;
  }
  if ( strlen(str1) == strlen(str2) ) return 0;
  if ( !check ) return 1;
  return -1;
}
