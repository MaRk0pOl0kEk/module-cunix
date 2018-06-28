#include "my_string.h"
#include <string.h>
#include <stdlib.h>

int find_size(char array_elem_size[32], char *buf, int pos)
{
  int i;

  for (i = 0; buf[pos] != '\n'; i++)
  {
    array_elem_size[i] = buf[pos];
    pos++;
  }
  array_elem_size[i] = '\0';
  return i;
}

pos_t         parse_size(char *answer)
{
  int         i, size;
  char        *left, *right;
  pos_t       pos;

  size = strlen(answer);
  left = malloc(size);
  right = malloc(size);

  memset(left, '\0', size);
  memset(right, '\0', size);

  for(i = 0; i < size && answer[i] != ' '; i++);

  left = strncpy(left, answer, i);
  right = strcpy(right, answer + i + 1);
  pos.x = atoi(left);
  pos.y = atoi(right);

  free(left);
  free(right);

  return pos;
}

void parse_elem(int *iterator, char *all, req_t *req)
{
  int dimension_size;
  char *mne_pohui;
  pos_t pos;

  mne_pohui = malloc(32 * sizeof(char));
  dimension_size = find_size(mne_pohui, all, *iterator);
  *iterator += dimension_size;
  pos = parse_size(mne_pohui);
  req->map.h = pos.x;
  req->map.w = pos.y;
  strncpy(*(req->map.array),all + (*iterator), pos.x * (pos.y + 1));
  iterator += pos.x * (pos.y + 1);
  free(mne_pohui);
}

req_t *parse_all(char *all)
{
  int iterator;
  req_t *req;

  create_req(req);
  req->symbol = all[0];
  iterator = 2;
  parse_elem(&iterator, all, req);
  parse_elem(&iterator, all, req);
  return req;
}





