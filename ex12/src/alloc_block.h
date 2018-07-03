struct alloc_block
{
  size_t size;
  struct alloc_block *next;
};