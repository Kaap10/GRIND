#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, int direction) {
            if(direction == 1) {
                adjList[u].push_back(v);
            } else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
};

int main() {
    Graph g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);

    for(auto node : g.adjList) {
    cout << node.first << " -> ";
    for(auto neighbor : node.second) {
        cout << neighbor << ", ";
    }
    cout << endl;
}
    return 0;
}