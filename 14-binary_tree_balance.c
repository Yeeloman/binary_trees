#include "binary_trees.h"
#include <stddef.h>

/**
 *binary_tree_balance - measures the balance factor of a binary tree
 *@tree : is a pointer to the root node of the tree.
 *Return: 0 if null.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int a, b;

	if (!tree)
		return (0);
	a = binary_tree_balance(tree->left);
	b = binary_tree_balance(tree->right);
	if (tree->left && !tree->right)
		return (a - b + 1);
	if (!tree->left && tree->right)
		return (a - b - 1);
	if (tree->left && tree->right)
		return (a - b);
	else
		return (0);
}
