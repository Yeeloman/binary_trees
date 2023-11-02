#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_height - Measures the height of a binary tree.
 * @tree: is a pointer to the root node of the tree.
 * Return: 0 if null
 */
int binary_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		left = tree->left ? 1 + binary_height(tree->left) : 1;
		right = tree->right ? 1 + binary_height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}

/**
 *binary_tree_balance - measures the balance factor of a binary tree
 *@tree : is a pointer to the root node of the tree.
 *Return: 0 if null.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else
		return (binary_height(tree->left) - binary_height(tree->right));
}

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: is a pointer to the root node of the tree.
 * Return: 0 if null
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int a, b;

	if (!tree)
		return (0);
	a = binary_tree_is_full(tree->left);
	b = binary_tree_is_full(tree->right);
	if (a == b)
		return (1);
	else
		return (0);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree.
 * Return: 0 if null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_full(tree) == 1 && binary_tree_balance(tree) == 0)
		return (1);
	else
		return (0);
}
