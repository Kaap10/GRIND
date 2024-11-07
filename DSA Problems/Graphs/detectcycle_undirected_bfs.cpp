// detect cycle in an undirected graph using BFS

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, int direction) {
        if (direction == 1) {
            adjList[u].push_back(v);
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    bool checkCycleUndirectedBFS(T src, unordered_map<T, bool> &visited) {
        unordered_map<T, T> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();

            for (auto child : adjList[frontNode]) {
                if (!visited[child]) {
                    q.push(child);
                    visited[child] = true;
                    parent[child] = frontNode;
                } else if (visited[child] && child != parent[frontNode]) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(3, 1, 0);

    unordered_map<int, bool> visited;
    for (int i = 0; i <= 5; i++) {
        if (!visited[i]) {
            bool ans = g.checkCycleUndirectedBFS(i, visited);
            if (ans == true) {
                cout << "Cycle is present" << endl;
                return 0; // Exit after finding the first cycle
            }
        }
    }

    cout << "Cycle is not present" << endl;
    return 0;
}
