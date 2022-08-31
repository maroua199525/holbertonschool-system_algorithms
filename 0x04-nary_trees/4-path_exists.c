#include "nary_trees.h"

/**
 * path_exists - Checks if a path exists between two nodes
 * @root: is a pointer to the root node of the tree
 * @path: Pointer to the path
 * Return: return 1 if all the elements of path are present in the tree
 * and if for an element of path at the index i
 * is present in one of the nodes at the depth i
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	size_t i;

	if (!root || !path || !*path)
		return (0);
	for (i = 0; path[i]; ++i, root = root->children)
	{
		while (root && strcmp(root->content, path[i]) != 0)
			root = root->next;
		if (!root)
			return (0);
	}
	return (1);
}
