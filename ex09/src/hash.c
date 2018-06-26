#include "linked_list.h"
hashtable_t *hash_create(unsigtned int size)
{
	hashtable_t *HashTable;
	HashTable = malloc( sizeof(hashtable_t));
	HashTable->size = size;
	HashTable->table = malloc( sizeof(node_t);
}

void hash_destroy(hashtable_t *ht, void (*fp)(void *data)
{
	for (int i = 0; i < ht->size; ++i)
	{
		if(ht->table[i] == NULL) 
			return;
		list_destroy(&(ht->table[i], fp);
	}
	free(ht->table);
	free(ht->size);
	free(ht);
}

unsigned int hash_func( char *key)
{
	if (key == NULL) 
		return 0;
	unsigned int hash = 0;
	for (int i = 0; key[i] != '\0'; ++i)
	{
		hash += key[i];
	}
	return hash;
}

void hash_set(hashtable_t *ht, char *key, void *ptr, void(*fp)(void *data))
{
	int i = hash_func(key) % ht->size;
	fp(ptr);
  	if (ht->table[i] == NULL)
  	  	ht->table[i] = list_create(ptr);
  	else
		list_push(ht->table[i], ptr);
}

void *hash_get( hashtable_t *ht, char *key) 
{
	int i = hash_func(key) % ht->size;

	if (ht->table[i] == NULL)
		return NULL;

//	node_t *hash = ht->table[i];
	return ht->table[i]->data;
}
