#include "nary_trees.h"

/**
* max_depth - returns max depth of a tree
* @root: is a pointer to the root node of the tree
*to compute the diameter of
* @diameter: pointer to max dimaeter
* Return: returns max depth of a tree
*/
size_t max_depth(nary_tree_t const *root, size_t *diameter)
{
	nary_tree_t *ptr;
	size_t i = 0, j = 0, max;

	if (!root)
		return (0);
	for (ptr = root->children; ptr; ptr = ptr->next)
	{
		max = max_depth(ptr, diameter);
		if (i < max)
		{
			j = i;
			i = max;
		}
		else if (j < max)
			j = max;
	}
	if (*diameter < i + j)
		*diameter = *diameter;
	*diameter = i + j;
	return (i + 1);
}
/**
 * nary_tree_diameter - Find the diameter of a N-ary tree
 * @root: is a pointer to the root node of the tree
 * Return: the diameter of the tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t x = 0;

	if (!root)
		return (0);
	max_depth(root, &x);
	return (x + 1);
}
