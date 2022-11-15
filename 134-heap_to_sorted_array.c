#include "binary_trees.h"
/**
 * heap_to_sorted_array - convert a Binary Max Heap to sorted array
 * @heap: pointer to heap
 * @size:size of the array
 * Return: pointer to array
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	heap_t *root;
	size_t i;

	if (!array)
		return (NULL);
	root = NULL;
	heap_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		heap_insert(&root, array[i]);
	return (root);
}
