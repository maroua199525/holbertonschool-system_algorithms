#include "graphs.h"

/**
 * graph_add_vertex - Adds a new_graph vertex to a graph
 * @graph: Graph
 * @str: new_graph vertes str
 * Return: a vertex pointer on succes or NULL
 */

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_graph = NULL, *ptr = NULL;

	if (!str || !graph)
		return (NULL);
	ptr = graph->vertices;
	while (ptr)
	{
		if (!strcmp(ptr->content, str))
			return (NULL);
		if (!ptr->next)
			break;
		ptr = ptr->next;
	}
	new_graph = malloc(sizeof(*ptr));
	if (!new_graph)
		return (NULL);
	new_graph->content = strdup(str);
	new_graph->index = 0;
	new_graph->edges = NULL;
	new_graph->nb_edges = 0;
	new_graph->next = NULL;
	if (!ptr)
	{
		new_graph->index = 0;
		graph->vertices = new_graph;
	}
	else
	{
		new_graph->index = ptr->index + 1;
		ptr->next = new_graph;
	}
	graph->nb_vertices++;
	return (new_graph);
}
