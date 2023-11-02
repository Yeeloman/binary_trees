#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *binary_tree_sibling - finds the sibling of a node
 *@node: a pointer to the node to find the sibling
 *Return: return a pointer to the sibling node or null
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node->parent || !node)
		return (NULL);
	if (!node->parent->left && !node->parent->right)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}

/**
 *binary_tree_uncle - finds the uncle of a node
 *@node: a pointer to the node to find the uncle
 *Return: uncle node or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	uncle = malloc(sizeof(struct binary_tree_s));
	if (!uncle)
		return (NULL);
	if (!node)
		return (NULL);
	uncle = binary_tree_sibling(node->parent);
	return (uncle);
}
