#include "binary_trees.h"
#include "111-bst_insert.c"
/**
 * complete_rotate - rotates a tree
 * @tree: pointer to the root
 * @granpa: pivot to rotate
 * @dir: 0 right 1 left
 * Return: new pivot
 **/
avl_t *complete_rotate(avl_t *granpa, avl_t **tree, int dir)
{
	binary_tree_t *grangranpa, *sub_root;

	grangranpa = granpa->parent;
	if (dir == 0) /* 0 right roation */
		sub_root = binary_tree_rotate_right(granpa);
	else
		sub_root = binary_tree_rotate_left(granpa);
	if (grangranpa)
	{
		if (grangranpa->n > sub_root->n)
			grangranpa->left = sub_root;
		else
			grangranpa->right = sub_root;
	}
	else
		*tree = sub_root;
	sub_root->parent = grangranpa;

	return (sub_root);

}
/**
 * avl_insert - Insert a value in an AVL tree
 * @tree: pointer to the root
 * @value: value to insert
 * Return: pointer to new node created
 **/
avl_t *avl_insert(avl_t **tree, int value)
{
	binary_tree_t *node, *new_node, *sub_root, *granpa;
	int balance1 = 0, balance2;
	/* common bst insertion */
	new_node = bst_insert(tree, value);
	/* messure balance */
	node = new_node;
	while (node->parent)
	{
		balance2 = balance1;
		balance1 = binary_tree_balance(node->parent);
		granpa = node->parent;
		if (balance1 > 1)
		{
			if (balance2 > 0)
				sub_root = complete_rotate(granpa, tree, 0);
			if (balance2 < 0)
			{
				sub_root = complete_rotate(node, tree, 1);
				sub_root = complete_rotate(sub_root->parent, tree, 0);
			}
			node = sub_root;
		}
		else if (balance1 < -1)
		{
			if (balance2 < 0)
				sub_root = complete_rotate(granpa, tree, 1);
			if (balance2 > 0)
			{
				sub_root = complete_rotate(node, tree, 0);
				sub_root = complete_rotate(sub_root->parent, tree, 1);
			}
			node = sub_root;
		}
		else
			node = node->parent;
	}
	return (new_node);
}
