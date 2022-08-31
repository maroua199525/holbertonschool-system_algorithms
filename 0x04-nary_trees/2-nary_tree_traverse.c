#include "nary_trees.h"

/**
 * nary_tree_traverse - Inserts a new node in a N-ary tree
 * @root: is a pointer to the root node of the tree to traverse
 * @action: is a pointer to a function to execute for
 * each node being traversed.
 * Its arguments are:
 * node is a pointer to the node being traversed
 * depth is the depth of the node being traversed
 * Return: the maximum depth of the tree
 */
size_t nary_tree_traverse(nary_tree_t const *root,
		void (*action)(nary_tree_t const *node, size_t depth))
{
	static size_t depth, max;
	size_t size;

	while (root)
	{
		action(root, depth);
		++depth;
		nary_tree_traverse(root->children, action);
		root = root->next;
	}
	if (max < depth)
		max = depth;
	if (depth == 0)
	{
		size = max;
		max = 0;
	}
	else
		--depth;
	return (size);
}
