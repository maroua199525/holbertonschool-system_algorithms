#include "rb_trees.h"

/**
 * is_valid - recursively valildates RB tree
 * @tree: pointer to root of tree to validate
 * Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
 */
int is_valid(const rb_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);

	if (!tree->color)
		return (0);

	if (tree->color == RED)
	{
		if (tree->parent->color == tree->color)
			return (0);
		if (tree->color == tree->left->color || tree->color == tree->right->color)
			return (0);
	}

	if (!tree->left || !tree->right)
		return (0);

	return (is_valid(tree->right) && is_valid(tree->left));


}


/**
* rb_tree_is_valid - check if a binary tree is a valid Red-Black Tree
*@tree:  a pointer to the root node of the tree to check
* Return: 1 if tree is a valid Red-Black Tree, and 0 otherwise
*/
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->color != BLACK)
		return (0);

	return (is_valid(tree->right) && is_valid(tree->left));
}
