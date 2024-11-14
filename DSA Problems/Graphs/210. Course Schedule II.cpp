#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

class Solution {
public:

    void topSortBFS(int n, vector<int> &topoOrder, unordered_map<int, list<int>> &adjLists) {
        queue<int> q;
        unordered_map<int, int> indegree;

        // Initialize indegree of all nodes to 0
        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
        }

        // Calculate indegree of each node
        for (auto &i : adjLists) {
            for (auto neighbour : i.second) {
                indegree[neighbour]++;
            }
        }

        // Push nodes with 0 indegree into the queue
        for (int node = 0; node < n; ++node) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        // Perform BFS
        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for (auto neighbour : adjLists[frontNode]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
    }

        for(auto i : prerequisites) {
                }
            }
            adjLists[v].push_back(u);

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjLists;
        for(auto vector<int> i :prerequisites) {
            int u = i[0];
            int v = i[1];
            adjLists[v].push_back(v);
        }

        vector<int> topoOrder;
        topSortBFS(numCourses, topoOrder, adjLists);

        if(topoOrder.size() == numCourses) {
            return topoOrder;
        } else {
            return {};
        }
    }
};
