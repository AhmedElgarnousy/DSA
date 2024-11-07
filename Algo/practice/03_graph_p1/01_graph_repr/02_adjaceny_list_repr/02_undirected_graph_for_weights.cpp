#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int to;
    int cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
}
void add_undirected_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
}
void print_adjaceny_matrix(GRAPH &graph)
{
    int nodes = graph.size();
    for (int from = 0; from < nodes; ++from)
    {
        cout << "Node " << from << " has neighbors: ";
        for (int edge = 0; edge < (int)graph[from].size(); ++edge)
            cout << "(to " << graph[from][edge].to
                 << " cost " << graph[from][edge].cost << ") ";
        cout << "\n";
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes); // observe: empty lists

    for (int e = 0; e < edges; ++e)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        add_directed_edge(graph, from, to, cost);
    }
    print_adjaceny_matrix(graph);
    return 0;
}

/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10

Output
Node 0 has neighbors: (to 5 cost 45)
Node 1 has neighbors: (to 4 cost 60)
Node 2 has neighbors: (to 1 cost 10) (to 5 cost 20) (to 0 cost 77) (to 3 cost 33)
Node 3 has neighbors:
Node 4 has neighbors:
Node 5 has neighbors: (to 4 cost 10)

 */
