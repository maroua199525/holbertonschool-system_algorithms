#include "nary_trees.h"

/**
 * nary_tree_delete - deallocates an entire N-ary tree
 * @tree: Pointer to the node to be deleted
 * Return: void
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *ptr;

	if (!tree)
		return;
	while (tree->children)
	{
		ptr = tree->children;
		tree->children = tree->children->next;
		nary_tree_delete(ptr);
	}
	free(tree->content);
	free(tree);
}
