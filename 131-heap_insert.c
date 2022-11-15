#include "binary_trees.h"
#include "17-binary_tree_sibling.c"
#include "1-binary_tree_insert_left.c"
#include "2-binary_tree_insert_right.c"
#include "16-binary_tree_is_perfect.c"
#include "4-binary_tree_is_leaf.c"
/**
 * swaps - swaps number to be a heap
 * @node: pointer to the node input
 * Return: pointer to node output
 **/
heap_t *swaps(heap_t *node)
{
	int aux;

	while (node->parent && node->parent->n < node->n)
	{
		aux = node->n;
		node->n = node->parent->n;
		node->parent->n = aux;
		node = node->parent;
	}
	return (node);
}
/**
 * preorder - goes through a binary tree using pre-order traversal
 * @last_node: double pointer to find the last node
 * @tree: pointer to the root
 * @level: level to print
 * @ref: reference to start
 * @flag: only work for first match
 * Return: no return
 **/
void preorder(heap_t *tree, int level, int ref, heap_t **last_node, int *flag)
{
	if (!tree)
		return;
	if (level == ref)
	{
		last_node[0] = tree;
	}
	if (level - 1 == ref && binary_tree_is_leaf(tree) == 1 && *flag == 0)
	{
		last_node[1] = tree;
		*flag = 1;
	}
	if (tree->left)
		preorder(tree->left, level, ref + 1, last_node, flag);
	if (tree->right)
		preorder(tree->right, level, ref + 1, last_node, flag);
}
/**
 * levelorder - traverses in zig-zag
 * @tree: pointer to the root
 * @last_node: last node in the tree
 * Return: no return
 **/
void levelorder(heap_t *tree, heap_t **last_node)
{
	int h, i, flag = 0;

	if (!tree)
		return;
	h = height(tree);
	for (i = 0; i <= h; i++)
	{
		preorder(tree, i, 0, last_node, &flag);
	}
}
/**
 * heap_insert - inserts node in a heap
 * @root: pointer to the root
 * @value: number to insert
 * Return: pointer to the new node
 **/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *first_row_node, **last_node, *insert_node, *aux;

	if (!root)
		return (NULL);
	tree = *root;
	if (!tree)
	{
		*root = binary_tree_node(tree, value);
		return (*root);
	}
	aux = *root;
	first_row_node = *root;
	last_node = malloc(sizeof(heap_t *) * 2);
	last_node[0] = *root;
	last_node[1] = *root;
	levelorder(tree, last_node);
	while (first_row_node->left)
		first_row_node = first_row_node->left;
	if (first_row_node == *last_node && first_row_node->parent == NULL)
	{
		insert_node = binary_tree_insert_left(first_row_node, value);
		insert_node = swaps(insert_node);
		free(last_node);
		*root = aux;
		return (insert_node);
	}
	*root = aux;
	if (binary_tree_sibling(*last_node))
	{
		if (!binary_tree_is_perfect(*root))
			insert_node = binary_tree_insert_left(last_node[1], value);
		else
			insert_node = binary_tree_insert_left(first_row_node, value);
	}
	else
		insert_node = binary_tree_insert_right(last_node[0]->parent, value);
	insert_node = swaps(insert_node);
	free(last_node);
	*root = aux;
	return (insert_node);
}
