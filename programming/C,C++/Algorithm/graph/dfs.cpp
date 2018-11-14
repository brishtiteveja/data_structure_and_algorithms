#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);

        return;
    }
    
    void dfs(int s);
    void dfsWithStack(int s);
    void dfsUtil(int s, vector<bool>& visited, vector<int>& path);
    void printPath(vector<int>& path);
};

void Graph::dfsUtil(int s, vector<bool>& visited, vector<int>& path) {
    visited[s] = true;
    path.push_back(s);

    for(int i=0; i<adj[s].size(); i++) {
        int n = adj[s][i];
        if (visited[n] == false)
            dfsUtil(n, visited, path);
    }

    return;
}

void Graph::printPath(vector<int>& path) {
    for(int i=0; i<path.size(); i++) {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

void Graph::dfs(int s) {
    vector<bool> visited(V, false); 
    vector<int> path;

    dfsUtil(s, visited, path);

    printPath(path);

    return;
}

void Graph::dfsWithStack(int s) {
    vector<bool> visited(V, false); 
    vector<int> path;
    vector<int> stack;

    visited[s] = true;
    stack.push_back(s);

    while(stack.empty() == false) {
        int c = stack.back();
        path.push_back(c);
        stack.pop_back();

        for(int i=adj[c].size()-1; i>= 0; i--) {
           int n = adj[c][i]; 
           if (visited[n] == false) {
               visited[n] = true;
               stack.push_back(n);
           }
        }
    }

    printPath(path);

    return;
}

int main() {

    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(2, 4);
    g.addEdge(4, 3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    g.dfs(0);
    g.dfsWithStack(0);

    return 0;
}
