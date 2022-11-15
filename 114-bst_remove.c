#include "binary_trees.h"
/**
 * search - checks if a binary tree is bts
 * @tree: pointer to the node
 * @value:number to search
 * Return: pointer to the founded node
 **/
bst_t *search(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	while (tree->left || tree->right)
	{
		if (tree && (tree->n > value))
		{
			if (tree->left)
				tree = tree->left;
			else
				break;
		}
		else if (tree && (tree->n < value))
		{
			if (tree->right)
				tree = tree->right;
			else
				break;
		}
		else if (tree && (tree->n == value))
			return (tree);
	}
	if (tree && (tree->n == value))
		return (tree);
	return (NULL);
}
/**
 * preorder_max_min - pre-order traversal -sets value with amx and min
 * @value: value[0] max value, value[1] min value
 * @tree: pointer to the root
 * Return: no return
 **/
void preorder_max_min(bst_t *tree, int *value)
{
	if (!tree)
		return;
	if (value[0] < tree->n)
		value[0] = tree->n;
	if (value[1] > tree->n)
		value[1] = tree->n;
	if (tree->left)
		preorder_max_min(tree->left, value);
	if (tree->right)
		preorder_max_min(tree->right, value);
}
/**
 * check_branch - sort single branches
 * @node1: node to swap
 * @root: tree root
 * Return: root
 **/
bst_t *check_branch(bst_t *node1, bst_t *root)
{
	if (node1->left && !node1->right)
	{
		if (node1->parent)
		{ node1->left->parent = node1->parent;
		if (node1->parent->right == node1)
			node1->parent->right = node1->left;
		else
			node1->parent->left = node1->left; }
	}
	else if (!node1->left && !node1->right)
	{
		if (node1->parent)
		{
		if (node1->parent->right == node1)
			node1->parent->right = node1->left;
		else
			node1->parent->left = node1->left; }
		else
			root = NULL;
	}
	return (root);
}
/**
 * bst_remove - checks if a binary tree is bts
 * @root: pointer to the root
 * @value:number to delete
 * Return: pointer to the root node
 **/
bst_t *bst_remove(bst_t *root, int value)
{
	int max_min[] = {0, 0};
	bst_t *node1;

	node1 = search(root, value);
	if (!node1)
		return (root);
	if (node1->right && node1->left)
	{ max_min[0] = node1->right->n;
		max_min[1] = node1->right->n;
		preorder_max_min(node1->right, max_min);
		bst_remove(node1->right, max_min[1]);
		node1->n = max_min[1];
		return (root);
	}
	else if (!node1->left && node1->right)
	{
		if (node1->parent)
		{ node1->right->parent = node1->parent;
		if (node1->parent->right == node1)
			node1->parent->right = node1->right;
		else
			node1->parent->left = node1->right; }
	}
	else
		root = check_branch(node1, root);
	free(node1);
	return (root);
}

