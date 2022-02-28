#include "rb_trees.h"

/**
* array_to_rb_tree - builds a Binary Search Tree from an array
*@array: builds a Binary Search Tree from an array
*@size:  the number of elements in the array
*Return: a pointer to the root node of the created R-B tree, or NULL on failure
*/
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t x;
	rb_tree_t *node;

	node = NULL;
	for (x = 0; array && x < size; x++)
		rb_tree_insert(&node, array[x]);
	return (node);
}
