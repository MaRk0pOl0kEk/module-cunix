#include <stddef.h>
#include "alloc_block.h"
typedef struct alloc_block alloc_b;

void *halloc(size_t size)
{
  alloc_b *alloc_ptr;
  alloc_ptr = (alloc_b *)sbrk(0);

}
