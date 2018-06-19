#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

node_t *allocnode()
{
  node_t *root;
  root = malloc( sizeof(node_t));

  root->key   = NULL;
  root->data  = NULL;
  root->left  = NULL;
  root->right = NULL;

  return root;
}

node_t *insert(node_t *root, char *key, void *data)
{
  node_t *insert_node;
  node_t *iterator;
  int is_insert;

  insert_node = allocnode();
  insert_node->key = key;
  insert_node->data = data;

  if(root == NULL)
  {
    root = insert_node;
    return root;
  }

  iterator = root;
  is_insert = 0;

  while (!is_insert)
  {
  if(iterator->left == NULL)
  {
    iterator->left = insert_node;
    is_insert = 1;
  }
  else if(iterator->right == NULL)
  {
    iterator->right = insert_node;
    is_insert = 1;
  }
  else
    iterator = iterator->left;
  }
  return insert_node;
}

void print_node(node_t *node)
{
  if (node == NULL)
    return;

  printf("%s\n", node->key);
  printf(node->data);
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
  if (node == NULL)
    return;

  fp(node);
  visit_tree(node->left, fp);
  visit_tree(node->right, fp);
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
  if (node == NULL)
    return;
  destroy_tree(node->left, fdestroy);
  destroy_tree(node->right, fdestroy);
  fdestroy(node);
  free(node);
}
/*  */
/* void remove_static(node_t *node) */
/* { */
/*   free(node->key); */
/*   free(node->data); */
/* } */
/*  */
/*  */
/* int main() */
/* { */
/*   node_t * root; */
/*   root = insert(NULL, "hello", "world"); */
/*   destroy_tree(root, remove_static); */
/*   print_node(root); */
/*   //insert(root, "world", "hello"); */
/*   //visit_tree(root, print_node); */
/* } */
/*  */