#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;
        void addEdge(int u, int v, int wt, int direction) {
            if(direction==1) {
                //directed
                adjList[u].push_back({v,wt});
            } else {
                adjList[v].push_back({u,wt});
                adjList[u].push_back({v,wt});
            }
        }

        void printadjList() {
            for(auto i : adjList) {
                cout << i.first << " -> {";

                for(pair<int, int> neighbour : i.second) {
                    cout << "{ " << neighbour.first << ", " << neighbour.second << " }, ";
                }
                cout << " }" << endl;
            }
        }

};

int main() {
    
    Graph g;
    g.addEdge(0, 1, 4, 0);
    g.addEdge(0, 2, 3, 0);
    g.addEdge(1, 2, 1, 0);
    g.addEdge(1, 3, 2, 0);
    g.addEdge(2, 3, 4, 0);

    g.printadjList();

    return 0;
}