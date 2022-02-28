#include "rb_trees.h"

/**
 * right_rotate - rotates subtree right
 * @tree: pointer to root node
 * @node: pointer to inserted node.
 */
void right_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *tree_new = node->left;

	if (tree_new == NULL)
		return;
	node->left = tree_new->right;
	if (tree_new->right)
		tree_new->right->parent = node;
	tree_new->right = node;
	tree_new->parent = node->parent;
	if (node->parent == NULL)
		*tree = tree_new;
	else if (node->parent->left == node)
		node->parent->left = tree_new;
	else
		node->parent->right = tree_new;

	node->parent = tree_new;
}

/**
 *left_rotate - rotates subtree left
 * @tree: pointer to root node
 * @node: pointer to inserted node.
 */
void left_rotate(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *tree_new = node->right;

	if (tree_new == NULL)
		return;
	node->right = tree_new->left;
	if (tree_new->left)
		tree_new->left->parent = node;
	tree_new->left = node;
	tree_new->parent = node->parent;
	if (node->parent == NULL)
		*tree = tree_new;
	else if (node->parent->left == node)
		node->parent->left = tree_new;
	else
		node->parent->right = tree_new;

	node->parent = tree_new;
}

/**
 * right_direction -  fixes the right side
 * @tree: double pointer to root node
 * @node: pointer to node where wrong color
 */

void right_direction(rb_tree_t **tree, rb_tree_t *node)
{

	if (node->parent->parent->right && node->parent->parent->right->color == RED)
	{
		node->parent->color = BLACK;
		node->parent->parent->right->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->right)
		{
			node = node->parent;
			left_rotate(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		right_rotate(tree, node->parent->parent);
	}
}
/**
 * fix_insertion - fixes Red Black Tree after insertion
 * @tree: pointer to root node
 * @node: pointer to node inserted node
 * Return: pointer to inserted node
 */
void fix_insertion(rb_tree_t **tree, rb_tree_t *node)
{
	while (node->parent && node->parent->color == RED)
	{
		if (node->parent->parent && node->parent == node->parent->parent->left)
			right_direction(tree, node);
		else
			left_direction(tree, node);

	}
	(*tree)->color = BLACK;
}
/**
 * left_direction -  fixes the left side
 * @tree: double pointer to root node
 * @node: pointer to node where wrong color
 */
void left_direction(rb_tree_t **tree, rb_tree_t *node)
{

	if (node->parent->parent->left && node->parent->parent->left->color == RED)
	{
		node->parent->color = BLACK;
		node->parent->parent->left->color = BLACK;
		node->parent->parent->color = RED;
		node = node->parent->parent;
	}
	else
	{
		if (node == node->parent->left)
		{
			node = node->parent;
			right_rotate(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		left_rotate(tree, node->parent->parent);
	}
}

/**
*rb_tree_insert - inserts a value in a Red-Black Tree
*@tree: a double pointer to the root node of the Red-Black tree
*@value:the value to store in the node to be inserted
*Return: a pointer to the created node, or NULL on failure
*/
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node, *tmp = NULL, *ptr;

	if (!tree)
		return (NULL);

	ptr = *tree;

	while (ptr)
	{
		tmp = ptr;
		if (value < ptr->n)
			ptr = ptr->left;
		else if (value > ptr->n)
			ptr = ptr->right;
		else
			return (NULL);
	}

	node = rb_tree_node(tmp, value, RED);

	if (!node)
		return (NULL);
	if (!tmp)
	{
		node->color = BLACK;
		return (*tree = node);
	}
	if (value < tmp->n)
		tmp->left = node;
	else
		tmp->right = node;
	fix_insertion(tree, node);
	return (node);
}
