#include "binary_trees.h"
#include "110-binary_tree_is_bst.c"
#include "14-binary_tree_balance.c"
/**
 * preorder_balance - goes through a binary tree using pre-order traversal
 * @f: pointer to function that chacks balance
 * @t: pointer to the root tree
 * Return: balanced 1 , unbalanced 0
 **/
int preorder_balance(const binary_tree_t *t, int (*f)(const binary_tree_t *))
{
	int balance_r, balance_l;

	if (!t || (t->left == NULL && t->right == NULL))
		return (1);
	if (f(t) > 1 || f(t) < -1)
		return (0);
	if (t->left)
		balance_r = preorder_balance(t->left, f);
	if (t->right)
		balance_l = preorder_balance(t->right, f);
	return (balance_r & balance_l);
}
/**
 * binary_tree_is_avl - Determine if tree is AVL
 * @tree: pointer to the root
 * Return: 1 if tree is AVL / 0 otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (!binary_tree_is_bst(tree))
		return (0);

	balance = preorder_balance(tree, &binary_tree_balance);
	return (balance);
}
