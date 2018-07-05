#include <stddef.h>
#include "alloc_block.h"
#include <unistd.h>
#include <stdio.h>

 alloc_b *head = NULL;

void block_init(alloc_b **block, size_t size)
{
  (*block)->size = size;
  (*block)->next = NULL;
  (*block)->free = 0;
}

alloc_b *create_block( alloc_b *new, alloc_b *last, size_t size)
{
  new = sbrk(0);
  alloc_b *ptr = sbrk(sizeof(alloc_b) + size);
  if (ptr == (void *) - 1)
    return NULL;
  block_init(&new, size);
  if (last != NULL)
    last->next = new;
  return new;
}

alloc_b *reuse_block(alloc_b *last, size_t size)
{
  alloc_b *iterator = head;
  while (iterator != NULL && !(iterator->free && iterator->size >= size))
  {
    last = iterator;
    iterator = iterator->next;
  }
  return iterator;
}

void free(alloc_b *ptr)
{
  if (ptr == NULL)
  {
    return;
  }
  (ptr - 1)->free = 1;
}

void *halloc(size_t size)
{
  if (size == 0)
    return NULL;

  alloc_b *new;
  if (head == NULL)
  {
    head = create_block(head, NULL, size);
    return head + 1;
  }
  else
  {
    alloc_b *last;

    last = head;
    new = reuse_block(last, size);

    if(new == NULL)
    {
      new = create_block(new, last, size);
      if (new == NULL)
        return NULL;
    }
    else
      new->free = 0;
  }
  return new + 1;
}










