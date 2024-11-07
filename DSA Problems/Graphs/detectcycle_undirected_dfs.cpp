#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
        unordered_map<T, list<int>> adjList;

        void addEdge(T u, T v, int direction) {
            if(direction == 1) {
                adjList[u].push_back(v);
            } else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        bool detectCycleUndirectedDFS(T src, unordered_map<T, bool> &visited, int parent) {
            visited[src] = true;

            for(auto child: adjList[src]) {
                if(!visited[child]) {
                    bool ans = detectCycleUndirectedDFS(child, visited, src);
                    if(ans==true) {
                        return true;
                    }
                }
                else if(visited[child] && child==parent) {
                    continue;
                } else if(visited[child] && child != parent) {
                    return true;
                }
            }
            return false;
        }
};


int main() {
    Graph<int>g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,5,0);
    g.addEdge(2,4,0);
    g.addEdge(4,3,0);
    g.addEdge(3,1,0); 

    unordered_map<int, bool> visited;
    for(int i=0; i<=5; i++) {
        if(!visited[i]) {
            int parent = -1;
            bool ans = g.detectCycleUndirectedDFS(i, visited, parent);
            if(ans==true) {
                cout << "Cycle is present :)" << endl;
            } else {
                cout << "Cycle is not present :(" << endl;
            }
        }
    }

    return 0;
}