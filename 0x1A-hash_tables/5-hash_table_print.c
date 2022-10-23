#include "hash_tables.h"

/**
 *  hash_table_print - print key/values of hash table in order
 *   
 *  @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *n;
	char *comma = "";

	if (ht == NULL || ht->array == NULL)
		return;

	putchar('{');
	while (index < ht->size)
	{
		n = ((ht->array)[index]);
		while (n)
		{
			printf("%s'%s': '%s'", comma, n->key, n->value);
			comma = ", ";
			n = n->next;
		}
		index++;
	}
	puts("}");
}
