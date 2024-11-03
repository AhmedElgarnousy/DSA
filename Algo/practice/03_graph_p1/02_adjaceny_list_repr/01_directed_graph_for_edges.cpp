#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}
void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void print_adjaceny_matrix(GRAPH &graph)
{
    int nodes = graph.size();
    for (int from = 0; from < nodes; from++)
    {
        cout << "Node " << from << " has neighbors: ";
        for (int to = 0; to < (int)graph[from].size(); ++to)
        {
            cout << graph[from][to] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes); // observe: empty list

    for (int e = 0; e < edges; e++)
    {
        int from, to;
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }
    print_adjaceny_matrix(graph);
    return 0;
}
/*
6 7
2 1
2 5
2 0
2 3
0 5
1 4
5 4

Output
Node 0 has neighbors: 5
Node 1 has neighbors: 4
Node 2 has neighbors: 1 5 0 3
Node 3 has neighbors:
Node 4 has neighbors:
Node 5 has neighbors: 4
*/