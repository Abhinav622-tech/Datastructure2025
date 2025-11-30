#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

class Graph{
public:
    int V;
    list<pair<int,int>> *l;
    vector< tuple<int,int,int> > edges;   // (weight, u, v)

    Graph(int e){
        V = e;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int w){
        l[u].push_back({v, w});
        l[v].push_back({u, w});

        edges.push_back({w, u, v});   // for Kruskal
    }

    // ------------ DSU FOR KRUSKAL -------------
    int findSet(int x, vector<int> &parent){
        if(parent[x] == x) return x;
        return parent[x] = findSet(parent[x], parent);
    }

    void unionSet(int a, int b, vector<int> &parent, vector<int> &rank){
        a = findSet(a, parent);
        b = findSet(b, parent);

        if(a != b){
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
    }

    // ---------------- KRUSKAL ----------------
    void KruskalMST(){
        sort(edges.begin(), edges.end());

        vector<int> parent(V), rank(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;

        int mst_weight = 0;
        cout << "\nKruskal MST edges:\n";

        for(auto &e : edges){
            int w, u, v;
            tie(w, u, v) = e;

            if(findSet(u, parent) != findSet(v, parent)){
                cout << u << " -- " << v << "  (weight " << w << ")\n";
                mst_weight += w;
                unionSet(u, v, parent, rank);
            }
        }

        cout << "Total MST Weight = " << mst_weight << endl;
    }

    // ---------------- PRIM (Using Min-Heap) ----------------
    void PrimMST(int src){
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        // (key, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        key[src] = 0;
        pq.push({0, src});

        cout << "\nPrim MST edges:\n";

        while(!pq.empty()){
            auto [k, u] = pq.top();
            pq.pop();

            if(inMST[u]) continue;
            inMST[u] = true;

            // Explore neighbors
            for(auto &nbr : l[u]){
                int v = nbr.first;
                int w = nbr.second;

                if(!inMST[v] && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        int mstWeight = 0;
        for(int i = 0; i < V; i++){
            if(parent[i] != -1){
                cout << parent[i] << " -- " << i << "  (weight " << key[i] << ")\n";
                mstWeight += key[i];
            }
        }

        cout << "Total MST Weight = " << mstWeight << endl;
    }

    // ---------------- DIJKSTRA ----------------
    void Dijkstra(int src){
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int u = curr.second;

            if(visited[u]) continue;
            visited[u] = true;

            for(auto p : l[u]){
                int v = p.first;
                int w = p.second;

                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nShortest distances from " << src << ":\n";
        for(int i = 0; i < V; i++){
            cout << "Node " << i << " = " << dist[i] << endl;
        }
    }

};

int main(){
    Graph g(4);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);

    cout << "\nDijkstra:";
    g.Dijkstra(0);

    cout << "\n\nKruskal MST:";
    g.KruskalMST();

    cout << "\n\nPrim MST:";
    g.PrimMST(0);
}
