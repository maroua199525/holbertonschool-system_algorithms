#include "graphs.h"
#include "pathfinding.h"
#include "queues.h"

/**
 * graph_helper - backtracking graph to find a path, helper function
 * @queue: queue of path so far
 * @visited: visited cities on the current path
 * @cur: current city (vertex)
 * @target: target city (vertex)
 * Return: queue of full path, NULL if failed
 */
int graph_helper(queue_t **queue, int *visited, vertex_t const *cur,
			   vertex_t const *target)
{
	edge_t *edge;
	int ret;

	if (!target || !cur || !visited || visited[cur->index])
	{
		return (0);
	}
	printf("Checking %s\n", cur->content);
	if (!strcmp(cur->content, target->content))
	{
		queue_push_front(*queue, strdup(cur->content));
		return (1);
	}
	visited[cur->index] = 1;
	edge = cur->edges;
	while (edge)
	{
		ret = graph_helper(queue, visited, edge->dest, target);
		if (ret)
		{
			queue_push_front(*queue, strdup(cur->content));
			return (1);
		}
		edge = edge->next;
	}
	visited[cur->index] = 0;
	return (0);
}

/**
 * backtracking_graph - backtracking graph to find a path
 * between two vertices
 * @graph: graph of cities
 * @start: starting city (vertex)
 * @target: target city
 * Return: a queue with path or NULL if failed
*/
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
			    vertex_t const *target)
{
	int *visited = NULL;
	queue_t *q = NULL;
	int s;

	if (!graph || !start || !target)
		return (NULL);
	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (NULL);
	q = queue_create();
	if (!q)
		return (NULL);
	s = graph_helper(&q, visited, start, target);
	free(visited);
	if (!s)
	{
		queue_delete(q);
		return (NULL);
	}
	return (q);
}
