#include "binary_trees.h"
/**
 * depth - measures the depth of a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: height of the tree
 **/
int depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->parent)
		return (depth(tree->parent) + 1);
	return (0);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to common ancestor
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	int dfirst, dsecond, dif, i;

	if (!first || !second)
		return (NULL);
	dfirst = depth(first);
	dsecond = depth(second);

	dif = dfirst - dsecond;
	if (dif > 0)
	{
		for (i = 0; i < dif; i++)
			first = first->parent;
	}
	if (dif < 0)
	{
		for (i = 0; i < -dif; i++)
			second = second->parent;
	}
	if (first == second)
		return ((binary_tree_t *)first);
	while (first->parent != second->parent)
	{
		second = second->parent;
		first = first->parent;
	}
	return (first->parent);
}
