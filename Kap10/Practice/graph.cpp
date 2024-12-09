#include<bits/stdc++.h>
using namespace std;

//unweighted graph
class Graph{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, int direction) {
        if(direction == 1) {
            adjList[u].push_back(v);
        } else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
};

//weighted graph
class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, int direction) {
        if(direction==1) {
            adjList[u].push_back({v,wt});
        } else {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }
};

//for weighted graph

void printAdjList() {
    for(auto i: adjList) {
        cout << i.first << "-> ";
        for(pair<int, int> ngbr : i.second) {
            cout << "{" << ngbr.first << " , " << ngbr.second << " }, ";
        }
        cout << " } " << endl;
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

        for(auto ngbrs : adjList[frontNode]) {
            T child = ngbrs.first;

            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

//DFS Traversal
void dfs(T src, unordered_map<T, bool> &visited) {
    visited[src] = true;
    cout << src << " ";

    for(auto ngbr : adjList[src]) {
        T child = ngbr.first;

        if(!visited[child]) {
            dfs(child, visited);
        }
    }
}

//check for cycle in undirected 
bool checkCycle(T src, unordered_map<T, bool> &visited) {
    unordered_map<T, T> parent;

    queue<T>q;

    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()) {
        T frontNode = q.front();
        q.pop();

        for(auto child: adjList[frontNode]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                parent[child] =  frontNode;
            }

            else if(visited[child] && child != parent[frontNode]) {
                return true;
            }
        }
    }
    return false;
}


//detecting cycle using DFS
bool checkCycleDFS(T src, unordered_map<T,bool> &visited, int parent) {
    visited[src] = true;

    for(auto child : adjList[src]) {
        if(!visited[child]) {
            bool ans = checkCycleDFS(child, visited, src);
            if(ans==true) {
                return true;
            }
        }

        else if(visited[child] && parent==child) {
            continue;
        }

        else if(visited[child] && parent!=child) {
            return true;
        }
    }

    return false;
}

//detect cycle in durecte graph
bool checkCycleDFS(int src, &visited, &DFSTrack, adjList[]) {
    visited[src] = true;
    DFSTrack[src] = true;

    for(auto child : adjList[src]) {
        if(!visited[child]) {
            bool ans = checkCycleDFS(src, visisted, DFSTrack, adjList);
            if(ans==true) {
                return true;
            }
        }

        if(visited[child] == 1 && DFSTrack[child] == 1) {
            return true;
        }
    }

    DFSTrack[src] = false;
    return false;   
}

// detect cycle in BFS (directed)
// -> same as TOPOLOGICAL sorting using BFS

//topological sorting using DFS
void topoSortDFS(int src, &visited, stack<int>&st, adjList[]) {
    visited[src] = true;

    for(auto child : adjList[src]) {
        if(!visited[child]) {
            topoSortDFS(src, visited, st, adjList);
        }
    }

    st.push(src);
}

//topological sort using BFS
void topoSortBFS(int n) {
    queue<int> q;
    unordered_map<int, int> indegree;

    for(auto i: adjList) {
        for(auto child : i.second) {
            indegree[child]++;
        }
    }

    for(int node=0; node<n; node++) {
        if(indegree[node] == 0) {
            q.push(node);
        }
    }

    while(!q.empty()) {
        auto frontNode = q.front();
        q.pop();
        cout << frontNode;

        for(auto child : frontNode) {
            indegree[child]--;

            if(indegree[child]==0) {
                q.push(child);
            }
        }
    }
}

//shortest path in undirected graph using BFS
void shortestPath(int src, int dist) {
    queue<int> q;
    unordered_map<int, int> visited;
    unordered_map<int, int> parent;

    q.push(src);
    visited[src] = true;
    parent[src]  = -1;

    while(!q.empty()) {
        auto frontNode = q.front();
        q.pop();

        for(auto child : adjList[frontNode]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                parent[child] = frontNode;
            }
        }
    }

    vector<int> shortestPath;
    while(dist!=-1) {
        shortestPath.push_back(dist);
        dist = parent[dist];
    }

    reverse(shortestPath.begin(), shortestPath.end());

    for(auto i : shortestPath) {
        cout << i << " ";
    }
}