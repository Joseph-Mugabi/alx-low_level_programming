#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int j;

	sht = malloc(sizeof(shash_table_t));
	if (!sht)
		return (NULL);

	sht->size = size;
	sht->shead = NULL;
	sht->stail = NULL;
	sht->array = malloc(sizeof(shash_node_t) * size);
	if (!sht->array)
	{
		free(sht);
		return (NULL);
	}
	for (j = 0; j < size; j++)
		sht->array[j] = NULL;
	return (sht);
}
/**
 * create_shash_node - creates a new hash node
 * @key: key
 * @value: node value
 *
 * Return: new node or NULL if error
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *snew_node;

	snew_node = malloc(sizeof(shash_node_t));
	if (!snew_node)
		return (NULL);
	snew_node->key = strdup(key);
	if (!snew_node->key)
	{
		free(snew_node);
		return (NULL);
	}
	snew_node->value = strdup(value);
	if (!snew_node)
	{
		free(snew_node->key);
		free(snew_node);
		return (NULL);
	}
	snew_node->next = snew_node->snext = snew_node->sprev = NULL;
	return (snew_node);
}
/**
 *  add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 *  @table: the sorted hash table
 *  @node: the node to add
 *
 *  Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *tmp;

	if (!table->shead && !table->stail)
	{
		table->shead = table->stail = node;
		return;
	}
	tmp = table->shead;
	while (tmp != NULL)
	{
		if (strcmp(node->key, tmp->key) < 0)
		{
			node->snext = tmp;
			node->sprev = tmp->sprev;
			tmp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		tmp = tmp->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}
/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *new_val;
	shash_node_t *shnode, *tmp;

	if (!ht || !ht->array || ht->size == 0 || !key ||
			strlen(key) == 0 || !value)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_val = strdup(value);
			if (!new_val)
				return (0);
			free(tmp->value);
			tmp->value = new_val;
			return (1);
		}
		tmp = tmp->next;
	}
	shnode = create_shash_node(key, value);
	if (!shnode)
		return (0);
	shnode->next = ht->array[idx];
	ht->array[idx] = shnode;
	add_to_sorted_list(ht, shnode);
	return (1);
}
/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 *
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *tmp;

	if (!ht || !ht->array || ht->size == 0 || !key ||
			strlen(key) == 0)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (!ht || !ht->array)
		return;
	printf("{");
	tmp = ht->shead;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (!ht || !ht->array)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next;

	if (!ht || !ht->array || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
