#include <stdlib.h>
#include <string.h>
#include "my_string.h"

stream_t *string_init()
{
  stream_t *ptr;
  ptr = malloc(sizeof(stream_t));
  ptr->size = 0;
  ptr->str = NULL;
  ptr->limit = BUF_SIZE;

  return ptr;
}

stream_t *string_create(char *str)
{
  stream_t *ptr;
  int str_size = strlen(str);

  ptr = string_init();
  ptr->size = str_size;
  ptr->str = malloc(str_size + 1);
  strcpy(ptr->str, str);
}

void string_append(stream_t *ptr, char * str)
{
  if (ptr == NULL)
    ptr = string_create(str);
  else
  {
    int str_size = strlen(str);
    ptr->str = realloc(ptr->str, ptr->size + str_size);
    for(int i = 0; i < str_size; ++i)
      ptr->str[ptr->size + i] = str[i];
    ptr->size +=str_size;
    ptr->str[ptr->size] = '\0';
  }
}

void string_destroy(stream_t *str)
{
  free(str->str);
  free(str);
  free(&str);
}