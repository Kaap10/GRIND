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
        }

        void bfs(T src) {
            unordered_map<T, bool> visited;
            queue<T> q;
            q.push(src);
            visited[src] = true;

            while(!q.empty()) {
                T frontNode = q.front();
                cout << frontNode << " ";
                q.pop();

                for(auto nbrs: adjList[frontNode]) {
                    T child = nbrs.first;

                    if(!visited[child]) {
                        q.push(child);
                        visited[child] = true;
                    }
                }
            }
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

        void dfs(T src, unordered_map<T, bool> &visited) {
            visited[src] = true;
            cout << src << " ";

            for(auto nbrs : adjList[src]) {
                T child = nbrs.first;

                if(!visited[child]) {
                    dfs(child, visited);
                }
            }
        }
};

int main() {
    Graph<char> g;
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 7, 0); 
    g.addEdge('b', 'd', 6, 0);
    g.addEdge('c', 'e', 8, 0);
    g.addEdge('c', 'f', 81, 0);

    unordered_map<char, bool> visited;
    for(char node = 'a'; node <= 'f'; node++) {
        if(!visited[node]) {
            g.dfs(node, visited);
        }
    }
    // g.dfs('a');

    return 0;
}