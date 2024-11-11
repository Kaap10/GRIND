#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction) {
            if(direction==1)
                adjList[u].push_back(v);

            else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        } 

        void topoSortUsingDFS(int src, unordered_map<int, bool> &visited, stack<int> &st) {
            visited[src] = true;

            for(auto ngbs : adjList) {
                if(!visited[ngbs]) {
                        
                }
            }
        }
}

int main() {
    
    return 0;
}