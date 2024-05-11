#include <iostream>

using namespace std;

bool isSafe(int v, bool graph[101][101], int color[101], int c, int V)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v, int V)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c, V))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int *color = new int[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;
    if (graphColoringUtil(graph, m, color, 0, n) == false)
    {
        return false;
    }
    return true;
}

int main()
{
    bool graph[101][101] = {{0, 1, 1, 1},
                            {1, 0, 1, 0},
                            {1, 1, 0, 1},
                            {1, 0, 1, 0}};
    int m = 3; // Maximum number of colors
    int n = 4; // Number of vertices
    if (graphColoring(graph, m, n))
        cout << "Graph can be colored with at most " << m << " colors" << endl;
    else
        cout << "Graph cannot be colored with " << m << " colors" << endl;
    return 0;
}
