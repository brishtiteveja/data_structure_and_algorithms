#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INF 100000
#define NIL -1

using namespace std;

string CLR[3] = {"White", "Gray", "Black" }; 
enum Color {White, Gray, Black};

class Vertex {
    int id;
    string name;
    Color c;
    int dist;
    int prev;


public:
    Vertex(int id, string name="") {
        this->id = id;
        if (name != "")
            this->name = name;
    }

    int getId() {
        return this->id;
    }

    string getName() {
        if (this->name != "") {
            return this->name;
        } else {
            char s = (this->id + '0');
            return string(&s);
        }
    }

    Color getColor() {
        return this->c;
    }

    int getDist() {
        return this->dist;
    }

    int getPrev() {
        return this->prev;
    }

    void setColor(Color c) {
        this->c = c;
    }

    void setDist(int dist) {
        this->dist = dist;
    }

    void setPrev(int prev) {
        this->prev = prev;
    }
};

static int e_id = 0;
class Edge {
    int id;
    Vertex* v1;
    Vertex* v2;
    int dir;
    int w;

public:
    Edge(Vertex* v1, Vertex* v2, int dir=0, int w = 0) {
        this->id = ++e_id;
        this->v1 = v1;
        this->v2 = v2;

        if(w) { // no edge weight if w = 0
            this->w = w;
        }

        if (dir == 1) {
            this->dir = dir; // from v1 to v2
        } else if (dir == -1) {
            this->dir = dir; // from v2 to v1
        } else { // dir=0 means bidirectional

        } 
    }

    Vertex* getV1(){
        return this->v1;
    }

    Vertex* getV2(){
        return this->v2;
    }

    int getDir() {
        return this->dir;
    }

    int getWeight() {
        return this->w;
    }
};

class Graph {
    int N_V; //Number of vertices
    int N_E; //Number of edges

    vector<Vertex*> V;
    vector<Edge*> E;

    bool vertexExists(Vertex* v) {
        for (int i=0; i<V.size(); i++) {
            if (V[i] == v) {
                return true;
            }
        }

        return false;
    }
public:
    vector<vector<Edge*> > AdjV; 

public:
    Graph() {
        this->N_V = 0; 
        this->N_E = 0; 
    }

    vector<Vertex* > getV() {
        return V;
    }

    vector<Edge *> getE() {
        return E;
    }

    void addEdge(Edge* e) {
        E.push_back(e);
        this->N_E++;

        Vertex* v1 = e->getV1();
        if (!vertexExists(v1)) { 
            V.push_back(v1);
            this->N_V ++;
        }
        
        Vertex* v2 = e->getV2();
        if (!vertexExists(v2)) { 
            V.push_back(v2);
            this->N_V ++;
        }

    }

    int getN_V() {
        return this->N_V;
    } 

    int getN_E() {
        return this->N_E;
    } 

    void showVertices() {
        for (int i=0; i<V.size(); i++) {
            cout << V[i]->getId() << " " << V[i]->getName() << " " << CLR[V[i]->getColor()] << " " << V[i]->getDist() << " " << V[i]->getPrev() << endl;
        }
        cout << endl;

        return;
    }

    void showEdges() {
        for (int i=0; i<E.size(); i++) {
            Edge* e = E[i];
            Vertex *v1 = e->getV1(); 
            Vertex *v2 = e->getV2(); 
            int dir = e->getDir();
            int w = e->getWeight();
            cout << v1->getName() << " "; 
            
            if (dir == 1) 
                cout << "->";
            else if(dir == -1)
                cout << "<-";
            else
                cout << "<-->";
            cout <<  " " << v2->getName() << " "; 
            cout << " " << w << endl;
        }
        cout << endl;

        return;
    }

    void generateAdjacencyMatrix() {
        AdjV = vector<vector<Edge*> >(this->N_V, vector<Edge*>()); 

        for (int i=0; i<E.size(); i++) {
            Edge* e = E[i];
            Vertex *v1 = e->getV1(); 
            Vertex *v2 = e->getV2(); 

            int v1_id = v1->getId() - 1;
            int v2_id = v1->getId() - 1;
            if (e->getDir() == 1)
                AdjV[v1_id].push_back(e);
            else if (e->getDir() == -1)
                AdjV[v2_id].push_back(e);
            else {
                AdjV[v1_id].push_back(e);
                AdjV[v2_id].push_back(e);
            }
        }
    }

    vector<Vertex*> getAdjacentVerticesOf(Vertex* v) {
        vector<Vertex*> adjVs;
        int v_id = v->getId();
        for(int i=0; i<AdjV[v_id].size(); i++) {
            Edge* e = AdjV[v_id][i];
            Vertex* v1 = e->getV1();
            Vertex* v2 = e->getV2();

            if (v1 == v) {
                adjVs.push_back(v2);
            } else {
                adjVs.push_back(v1);
            }
        }

        return adjVs;
    }

    void showAdjacentVerticesOf(Vertex* v) {
        vector<Vertex*> adjVs = getAdjacentVerticesOf(v);

        for (int i=0; i < adjVs.size(); i++) {
            Vertex* vt = adjVs[i];
            cout << vt->getName() << " "; 
        }
        cout << endl;

        return;
    }

    void showAllAdjacentVertices() {
        for(int i=0; i<V.size(); i++) {
            Vertex* v = V[i];
            cout << "Adjacent Vertices of vertex " << v->getName() << ":" << endl;
            showAdjacentVerticesOf(v);
        }

        return;

    }

};

void BFS(Graph* G, Vertex* s) {
    for(int i=0; i<G->getV().size(); i++) {
        Vertex* v = G->getV()[i];
        if (s == v)
            continue;
        v->setColor(White);
        v->setDist((int)INF);
        v->setPrev(NIL);
    }

    s->setColor(Gray);
    s->setDist(0);
    s->setPrev(NIL);

    queue<Vertex *> Q;
    Q.push(s);

    while (!Q.empty()) {
        Vertex *u = Q.front();
        Q.pop();

        vector<Vertex*> adjVs = G->getAdjacentVerticesOf(u); 
        G->showVertices();
        for (int i=0; i<adjVs.size();i++) {
            Vertex* v = adjVs[i]; 
            if (v->getColor() == White) {
                v->setColor(Gray);
                v->setDist(u->getDist() + 1);
                v->setPrev(u->getId());
                Q.push(v);
            }
        }
        u->setColor(Black);
        G->showVertices();
    }

    G->showVertices();

    return;
}

int main() {

    Graph G;

    Vertex s(1, "s");
    Vertex v1(2, "v1");
    Vertex v2(3, "v2");
    Vertex v3(4, "v3");
    Vertex v4(5, "v4");
    Vertex t(6, "t");

    Edge e1(&s, &v1, 1, 16);  
    Edge e2(&s, &v2, 1, 13);  
    Edge e3(&v1, &v3, 1, 12);  
    Edge e4(&v1, &v2, 1, 10);  
    Edge e5(&v2, &v1, 1, 4);  
    Edge e6(&v2, &v4, 1, 14);  
    Edge e7(&v3, &v2, 1, 9);  
    Edge e8(&v3, &t, 1, 20);  
    Edge e9(&v4, &v3, 1, 7);  
    Edge e10(&v4, &t, 1, 4);  

    G.addEdge(&e1);
    G.addEdge(&e2);
    G.addEdge(&e3);
    G.addEdge(&e4);
    G.addEdge(&e5);
    G.addEdge(&e6);
    G.addEdge(&e7);
    G.addEdge(&e8);
    G.addEdge(&e9);
    G.addEdge(&e10);
    
    cout << G.getN_V() << endl;
    cout << G.getN_E() << endl;
    G.showVertices();
    cout << endl;
    G.showEdges();
    cout << endl;

    G.generateAdjacencyMatrix();
    G.showAllAdjacentVertices();

    BFS(&G, &s);
    
    return 0;
}
