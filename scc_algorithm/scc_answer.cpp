// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
#include <memory.h>

#define ROOT 0
using namespace std;
class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // An array of adjacency lists
    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(int v, bool visited[], stack<int> &Stack); // To be implemented
    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    // The main function that finds and prints strongly connected
    // components
    void printSCCs(); // To be implemented
    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    memset(visited, false, V);

    // put into the stack
    int cur_idx = ROOT;
    while (cur_idx < V)
    {
        if (!visited[cur_idx])
            fillOrder(cur_idx, visited, Stack);
        cur_idx++;
    }

    memset(visited, false, V);
    Graph g_tr = getTranspose();
    int i = 1;

    // pop from the stack and DFS for the reversed graph
    while (true)
    {
        int cur_idx = Stack.top();
        if (!visited[cur_idx])
        {
            std::cout << "SCC " << i << " : ";
            g_tr.DFSUtil(cur_idx, visited);
            std::cout << std::endl;
            i++;
        }
        Stack.pop();
        if (Stack.empty())
            break;
    }

    delete[] visited;
    return;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            fillOrder(*i, visited, Stack);

    Stack.push(v);
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    /*
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    */

    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(5, 2);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 5);
    g.addEdge(4, 3);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
    return 0;
}