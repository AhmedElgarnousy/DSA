#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> GRAPH;

void print_adjaceny_matrix(GRAPH &graph)
{
    int nodes = graph.size();
    for (int from = 0; from < nodes; ++from)
    {
        for (int to = 0; to < nodes; ++to)
        {
            if (graph[from][to] > 0)
                cout << "From " << from << " To " << to << " the cost is " << graph[from][to] << "\n";
        }
    }
}

void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = cost;
}
void add_undirected_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = cost;
    graph[to][from] = cost;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes, vector<int>(nodes));

    for (int e = 0; e < edges; ++e)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        add_undirected_edge(graph, from, to, cost);
    }
    print_adjaceny_matrix(graph);
    return 0;
}