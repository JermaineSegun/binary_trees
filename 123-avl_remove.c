#include "binary_trees.h"
/**
 * avl_remove - Remove a node from tree
 * @root: pointer to the root of tree
 * @value: value to remove
 * Return: pointer to new root of tree
 **/
avl_t *avl_remove(avl_t *root, int value);
{
	avl_t *tmp, *new;
	int flag;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	tmp = *tree;
	flag = 0;
	while (flag == 0)
	{
		if (value > tmp->n)
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				flag = 1;
				new = binary_tree_node(tmp, value);
				tmp->right = new;
				return (new);
			}
		else
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				flag = 1;
				new = binary_tree_node(tmp, value);
				tmp->left = new;
				return (new);
			}
	}
	return (NULL);
}
