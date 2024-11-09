#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> GRAPH;
// Adjacency list
void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}
void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

void print_adjaceny_list(GRAPH &graph)
{
    for (int row = 0; row < graph.size(); row++)
    {
        cout << "Node " << row << " has neighbors: ";
        for (int col = 0; col < graph[row].size(); col++)
        {
            cout << graph[row][col] << " ";
        }
        cout << "\n";
    }
}

void dfs(GRAPH &graph, int node, vector<bool> &visited)
{
    visited[node] = true;
    vector<int> neighbors = graph[node];
    for (int neighbor : neighbors)
    {
        if (!visited[neighbor])
        {
            cout << "\twe can reach " << neighbor << "\n";
            dfs(graph, neighbor, visited);
        }
    }
}

void reachability(GRAPH &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        vector<bool> visited(graph[i].size());
        cout << "Reachable set of node " << i << "\n";
        dfs(graph, i, visited);
    }
}

int main()
{
    // create the graph
    int nodes, edges;
    cout << "Enter the nodes, edges: ";
    cin >> nodes >> edges;

    GRAPH graph(nodes);

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cout << "Enter src and destination for edges: ";
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }

    // print_adjaceny_list(graph); // show the graph
    reachability(graph);

    return 0;
}

/*
7 9 // nodes edges

relationships
2 0
0 1
0 3
1 0
1 4
3 1
4 3
5 6
6 6
*/