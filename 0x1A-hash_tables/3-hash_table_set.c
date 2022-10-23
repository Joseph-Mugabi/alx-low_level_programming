#include "hash_tables.h"

/**
 * create_new_node - creates a new hash node
 * @key: key
 * @value: node value
 *
 * Return: new node or NULL if error
 */
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (!new_node)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

/**
 * hash_table_set - function that adds an element to the hash table.
 * @key: key for the node
 * @value: value for the node
 * @ht: hash table
 * Return: 1 or 0 if error
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *cur_node, *tmp;
	char *new_value;

	if (!ht || !ht->array || ht->size == 0 || !key ||
			strlen(key) == 0 || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (!new_value)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}
	cur_node = create_new_node(key, value);
	if (!cur_node)
		return (0);
	cur_node->next = ht->array[index];
	ht->array[index] = cur_node;

	return (1);
}
