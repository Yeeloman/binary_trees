#include "binary_trees.h"
#include <stdlib.h>

/**
 *findROOT -finds the root of a binary tree
 *@tree: pointer to the tree
 *Return: the root
 */

const binary_tree_t *findROOT(const binary_tree_t *tree)
{
	const binary_tree_t *tmp;

	tmp = malloc(sizeof(struct binary_tree_s));
	if (!tmp)
		return (NULL);

	tmp = tree;
	while (tmp->parent) {
		tmp = tmp->parent;
	}
	return (tmp);
}

/**
 *findLCA - help function
 *@root: root of the tree
 *@fst: first node
 *@snd: second node
 *Return: pointer to the ancestor
 */

const binary_tree_t *findLCA(const binary_tree_t *root,
                             const binary_tree_t *fst,
                             const binary_tree_t *snd)
{
	const binary_tree_t *left_lca, *right_lca;

	left_lca = malloc(sizeof(struct binary_tree_s));
	right_lca = malloc(sizeof(struct binary_tree_s));
	if (!root || !left_lca || !right_lca)
		return (NULL);
	if (root == fst || root == snd)
		return (root);
	left_lca = findLCA(root->left, fst, snd);
	right_lca = findLCA(root->right, fst, snd);
	if (left_lca && right_lca)
		return (root);
	else if (left_lca)
		return (left_lca);
	else
		return (right_lca);
}
/**
 *binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *@first:is a pointer to the first node
 *@second: is a pointer to the second node
 *Return: a pointer to the lowest common ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
	const binary_tree_t *root;
	binary_tree_t *ancestor;

	ancestor = malloc(sizeof(struct binary_tree_s));
	root = malloc(sizeof(struct binary_tree_s));
	if (!ancestor || !root)
		return (NULL);

	if (!first || !second)
		return (NULL);
	root = findROOT(first);
	ancestor = (binary_tree_t *)findLCA(root, first, second);
	return (ancestor);
}
