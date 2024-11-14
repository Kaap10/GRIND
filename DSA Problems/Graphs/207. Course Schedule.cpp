class Solution {
public:

    void topSortBFS(int n, vector<int> &topoOrder, unordered_map<int, list<int>> &adjLists) {
        queue<int>q;
        unordered_map<int, int> indegree;

        for(auto i:adjLists) {
            for(auto neighbour : i.second) {
                indegree[neighbour]++;
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
            topoOrder.push_back(frontNode);

            for(auto neighbour : adjLists[frontNode]) {
                indegree[neighbour]--;

                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjLists;
        for(auto vector<int> i :prerequisites) {
            int u = i[0];
            int v = i[1];
            adjLists[v].push_back(v);
        }

        vector<int> topoOrder;
        topSortBFS(numCourses, topoOrder, adjLists);

        if(topoOrder.size() == numCourses) {
            return true;
        } else {
            return false;
        }
    } 
};