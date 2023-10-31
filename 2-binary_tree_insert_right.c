#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *binary_tree_insert_right - inserts a node as the right-child of another node
 *@parent: a pointer to the node to insert the right-child in
 *@value: the value to store in the new node
 *Return: return a pointer to the created node, or NULL on failure or if parent
 *is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	if (!parent)
		return (NULL);

	tmp = malloc(sizeof(struct binary_tree_s));
	if (!tmp)
		return (NULL);
	tmp->right = parent->right;
	parent->right = binary_tree_node(parent, value);
	if (tmp->right)
		parent->right->right = binary_tree_node(parent->right, tmp->right->n);
	free(tmp);
	return (parent);
}
