#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph {
public:
    int V;
    list<int>* l;

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS() {
        queue<int> q;
        q.push(0);
        vector<bool> visited(V, false);
        visited[0] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : l[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool>& visited) {
        cout << u << " ";
        visited[u] = true;

        for (int v : l[u]) {
            if (!visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

    void DFS() {
        vector<bool> visited(V, false);
        dfsHelper(0, visited);
        cout << endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "BFS: ";
    g.BFS();

    cout << "DFS: ";
    g.DFS();

    return 0;
}
