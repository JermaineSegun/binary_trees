#include "binary_trees.h"
/**
 * array_to_heap - builds a heap tree from an array
 * @array: pointer to the array
 * @size:size of the array
 * Return: pointer to root tree
 **/
heap_t *array_to_heap(int *array, size_t size)
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
