#include "nary_trees.h"

/**
 * nary_tree_insert -  a function that inserts a node in a N-ary tree
 * @parent: Pointer to the parent node
 * @str: is the string to be stored in the created node
 * Return: a pointer to the created node, or NULL on failure.
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->content = strdup(str);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->parent = parent;
	new->children = NULL;
	new->nb_children = 0;
	if (parent)
	{
	++parent->nb_children;
	new->next = parent->children;
	parent->children = new;
	}
	else
		new->next = NULL;
	return (new);
}
