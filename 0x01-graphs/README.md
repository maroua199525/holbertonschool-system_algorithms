#### Learning Objectives
##### What is a graph
- A graph is a set of nodes (called vertices), and connections (called edges) connecting the different vertices. Graphs are used to represent networks.
In a tree (binary or N-ary), a node can only be connected to its parent and children. In a graph, each vertex can be connected to every other vertex of the graph.

##### What are vertices and edges:
- A vertex (or node) of a graph is one of the objects that are connected together. The connections between the vertices are called edges or links.
![](https://mathinsight.org/media/image/image/small_undirected_network_labeled.png)



##### What are the different types of graphs (directed, weighted, …)What are the different types of graphs (directed, weighted, …)
- **Undirected graph**
A graph is called undirected when all edges are bidirectional, meaning that if a vertex A is connected to a vertex B, then B is connected to A.

- The following image shows the graphical representation of an undirected graph:![](https://s3.amazonaws.com/intranet-projects-files/concepts/86/Undirected_graph.png)


###### Example of usecase
- A social network like **Facebook** can be represented using an undirected graph:

- Each vertex represents a person
- On Facebook, if a person A is a friend of a person B, then they are both connected, we can represent these connections with bidirectional edges.

**Directed graph**
- On the other hand, a graph is called directed when at least one edge is unidirectional, meaning that if a vertex A is connected to a vertex B, then B is not neccesarily connected to A (But it can be, through another edge).

- The following image shows the graphical representation of a directed graph:![](https://s3.amazonaws.com/intranet-projects-files/concepts/86/Directed_graph.png)

######  Example of usecase
- Other social networks like **Twitter**, or I**nstagram**, can be represented using directed graphs:

 - Each vertex represents a person
 - A person A can follow a person B, but it does not necessarily mean that B follows A back. Such a connection between A and B can be represented using a unidirectional edge.


**Weighted graphs**
- Another possible property of a graph is that its edges can be given a weight.![](https://s3.amazonaws.com/intranet-projects-files/concepts/86/Weighted_graph.png)
###### - Examples of usecase
- We can easily understand the purpose of weighted graphs with a graph representing the time to travel between **cities**:

- Each vertex represents a city
- The distance divided by the average speed limit between two cities gives us the time it takes to travel between two cities. If we use time as the weight of the edge between two vertices, we can build a graph that can be used to determine the fastest way to go from a city A to a city X!