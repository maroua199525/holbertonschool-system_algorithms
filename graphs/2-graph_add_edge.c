#include "graphs.h"
#include <string.h>
#include <stdlib.h>

/**
 * find_vertex - Finds the vertex in the given graph from the given string.
 * @graph: Pointer to the graph.
 * @str: String to find.
 *
 * Return: Pointer to the found vertex, or NULL if not found.
 */
vertex_t *find_vertex(graph_t *graph, const char *str)
{
    vertex_t *temp;

    if (!graph || !str)
        return (NULL);

    temp = graph->vertices;
    while (temp)
    {
        if (strcmp(temp->content, str) == 0) /* Fix: Check if strings match */
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}

/**
 * edge_exists - Checks if an edge already exists between two vertices.
 * @v_src: Source vertex.
 * @v_dest: Destination vertex.
 *
 * Return: 1 if the edge exists, 0 otherwise.
 */
int edge_exists(vertex_t *v_src, vertex_t *v_dest)
{
    edge_t *edge = v_src->edges;

    while (edge)
    {
        if (edge->dest == v_dest)
            return (1);
        edge = edge->next;
    }
    return (0);
}

/**
 * create_and_place_edge - Creates a new edge and places it correctly.
 * @v_src: Source vertex.
 * @v_dest: Destination vertex.
 *
 * Return: 1 on success, 0 on failure.
 */
int create_and_place_edge(vertex_t *v_src, vertex_t *v_dest)
{
    edge_t *temp = v_src->edges, *new_edge = NULL;

    /* Traverse to the end of the edge list */
    while (temp && temp->next)
        temp = temp->next;

    /* Allocate memory for the new edge */
    new_edge = malloc(sizeof(edge_t));
    if (!new_edge)
        return (0);

    new_edge->dest = v_dest;
    new_edge->next = NULL;

    if (!temp) /* Add as the first edge if no edges exist */
        v_src->edges = new_edge;
    else
        temp->next = new_edge;

    return (1);
}

/**
 * graph_add_edge - Adds a new edge to the graph.
 * @graph: Pointer to the graph.
 * @src: Source vertex string.
 * @dest: Destination vertex string.
 * @type: Type of edge (UNIDIRECTIONAL or BIDIRECTIONAL).
 *
 * Return: 1 on success, 0 on failure.
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
    vertex_t *v_src, *v_dest;

    if (!graph || !src || !dest)
        return (0);

    /* Find the source and destination vertices */
    v_src = find_vertex(graph, src);
    v_dest = find_vertex(graph, dest);

    if (!v_src || !v_dest) /* Ensure both vertices exist */
        return (0);

    /* Create the main edge */
    if (!edge_exists(v_src, v_dest))
    {
        if (!create_and_place_edge(v_src, v_dest))
            return (0);
        v_src->nb_edges++;
    }

    /* Handle BIDIRECTIONAL edge */
    if (type == BIDIRECTIONAL && !edge_exists(v_dest, v_src))
    {
        if (!create_and_place_edge(v_dest, v_src))
        {
            /* Revert changes if adding the second edge fails */
            edge_t *temp = v_src->edges, *prev = NULL;

            /* Remove the previously added edge from v_src to v_dest */
            while (temp)
            {
                if (temp->dest == v_dest)
                {
                    if (prev)
                        prev->next = temp->next;
                    else
                        v_src->edges = temp->next;
                    free(temp);
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            v_src->nb_edges--; /* Decrement the edge count */
            return (0);
        }
        v_dest->nb_edges++;
    }

    return (1);
}
