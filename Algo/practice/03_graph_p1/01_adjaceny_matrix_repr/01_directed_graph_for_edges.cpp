#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from][to] += 1;
}
void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from][to] += 1;
    graph[to][from] += 1;
}

void print_adjaceny_matrix(GRAPH &graph)
{
    int nodes = graph.size();
    for (int from = 0; from < nodes; from++)
    {
        for (int to = 0; to < nodes; to++)
        {
            if (graph[from][to] > 0)
                cout << "From " << from << " To " << to << " there are " << graph[from][to] << " edges\n";
        }
    }
}

int main()
{
    // build and create the graph
    int nodes, edges;
    cout << "Enter # of nodes and edges: ";
    cin >> nodes >> edges;

    GRAPH graph(nodes, vector<int>(nodes));

    cout << "Enter the existing edges from to (idx): ";
    for (int e = 0; e < edges; e++)
    {
        int from, to;
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }

    print_adjaceny_matrix(graph);

    return 0;
}