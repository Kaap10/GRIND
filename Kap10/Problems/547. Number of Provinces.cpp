class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, int &srcNode, unordered_map<int, int> &visited, int nodes) {
        visited[srcNode] = true;

        for(int nbrNode = 0; nbrNode < nodes; nbrNode++) {
            if(srcNode!=nbrNode && isConnected[srcNode][nbrNode] == 1) {
                if(!visited[nbrNode]) {
                    dfs(isConnected, nbrNode, visited, nodes);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();
        int count = 0;

        unordered_map<int, int> visited;
        for(int srcNode =0; srcNode < nodes; srcNode++) {
            if(!visited[srcNode]) {
                dfs(isConnected, srcNode, visited, nodes);
                count++;
            }
        }
        return count;
    }
};