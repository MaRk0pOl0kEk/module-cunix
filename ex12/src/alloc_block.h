typedef struct alloc_block
{
  size_t size;
  void *next;
  int free;
} alloc_b;