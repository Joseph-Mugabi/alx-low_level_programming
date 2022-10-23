#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table.
 *
 * @size: size
 * Return: pointer to table, NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	hash_node_t **array;
	unsigned long int j = 0;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);
	array = malloc(sizeof(*array) * size);
	if (array == NULL)
	{
		free(ht);
		return (NULL);
	}
	while (j < size)
	{
		array[j] = NULL;
		j++;
	}
	ht->size = size;
	ht->array = array;

	return (ht);
}
