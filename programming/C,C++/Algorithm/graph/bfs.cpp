#include <iostream>
#include <vector>
#include <list>

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
    
    void bfs(int s);
    void printPath(vector<int>& path);
};

void Graph::printPath(vector<int>& path) {
    for(int i=0; i<path.size(); i++) {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

void Graph::bfs(int s) {
    vector<bool> visited(V, false); 
    vector<int> path;
    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while(queue.empty() == false) {
        int c = queue.front();
        path.push_back(c);
        queue.pop_front();

        for(int i=0; i<adj[c].size(); i++) {
           int n = adj[c][i]; 
           if (visited[n] == false) {
               visited[n] = true;
               queue.push_back(n);
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

    g.bfs(0);

    return 0;
}
