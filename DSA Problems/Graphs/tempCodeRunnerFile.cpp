#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    public:
        unordered_map<T, list<pair<T, int>>> adjList;

        void addEdge(T u, T v, int wt, int direction) {
            if(direction == 1) {
                adjList[u].push_back({v,wt});
            } else {
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }

            cout << "Print Adjacent List: " << endl;
            printadjList();
            cout << endl;
        }

        void printadjList() {
            for(auto i : adjList) {
                cout << i.first << " ->";
                for(pair<T, int> neighbour : i.second) {
                    cout << "{ " << neighbour.first << ", " << neighbour.second << " }, ";
                }
                cout << " }" << endl;
            }
        }

};

int main() {
    Graph<int> g;
    g.addEdge(1, 2, 10, 0);
    g.addEdge(1, 3, 15, 0); 
    g.addEdge(2, 4, 5, 1);
    g.addEdge(3, 4, 10, 0);
    g.addEdge(4, 5, 20, 1);


    return 0;
}