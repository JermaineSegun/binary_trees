#include "binary_trees.h"
/**
 * array_to_avl - builds a heap tree from an array
 * @array: pointer to the array
 * @size:size of the array
 * Return: pointer to root tree
 **/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t i;

	if (!array)
		return (NULL);
	root = NULL;
	avl_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
