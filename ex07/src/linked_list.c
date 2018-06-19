#include <stdlib.h>
#include <stdio.h>

typedef struct node {
   void         *data;
   struct node  *next;
}              node_t;

node_t *list_create( void *data)
{
  node_t *head;
  head = malloc(sizeof( node_t));
  head->data = data;
  head->next = NULL;
  return head;
}

void list_destroy(node_t **head, void (*fp)(void *data) )
{
  node_t *next_;

  next_ = (*head)->next;

  if (next_ == NULL) return;
  while(next_ != NULL)
  {
    fp( next_->data);
    next_ = next_->next;
    free((*head)->next);
  }
  fp((*head)->data);
  head = NULL;
}

void list_unshift( node_t **head, void *data)
{
  node_t *begin;
  begin = malloc( sizeof(node_t));
  begin->data = data;
  begin->next = *head;
  *head = begin;
}

void list_push(node_t **head, void *data)
{
  node_t *iterator;
  node_t *last;

  iterator = *head;
  last = malloc( sizeof(node_t));

  while( iterator = NULL) iterator = iterator->next;
  iterator->next = last;
  last->data = data;
  last->next = NULL;
}

void list_pop( node_t **head)
{
  node_t *iterator;
  node_t *for_delete;
  iterator = *head;

  while( (iterator->next)->next != NULL) iterator = iterator->next;
  for_delete = iterator->next;
  iterator->next = NULL;
  free( for_delete->data);
  free( for_delete);
}

void list_shift(node_t **head)
{
  node_t *new_head;
  new_head = (*head)->next;
  free( (*head)->data);
  free( *head);
  *head = new_head;
}

void list_remove( node_t **head, int pos)
{
  node_t *iterator;
  node_t *remove_ptr;

  iterator = *head;

  for (int i = 0; i < pos; ++i)
    iterator = iterator->next;

  remove_ptr = iterator->next;
  iterator->next =remove_ptr->next;
  free(remove_ptr->data);
  free(remove_ptr);
}

void list_print( node_t *head)
{
  for( node_t *iterator = head; iterator != NULL; iterator = iterator->next)
    printf(iterator->data);
}

void list_visitor(node_t *head, void(*fp)(void *data))
{
   for( node_t *iterator = head; iterator != NULL; iterator = iterator->next)
    fp(iterator->data);
}








