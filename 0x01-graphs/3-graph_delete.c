#include "graphs.h"

/**
 * graph_delete - A function that completely deletes a graph.
 * @graph: a pointer to the graph to be deleted.
 * Returns: Nothing (void)
 */

void graph_delete(graph_t *graph)
{
	edge_t *edge, *ptr;
    vertex_t *new_graph, *tmp;

	if (!graph)
		return;

	new_graph = graph->vertices;
	while (new_graph)
	{
		free(new_graph->content);
		edge = new_graph->edges;
		while (edge)
		{
			ptr = edge;
			edge = edge->next;
			free(ptr);
		}

		tmp = new_graph;
		new_graph = new_graph->next;
		free(tmp);
	}

	free(graph);
}
