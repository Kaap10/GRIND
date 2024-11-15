class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        return newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && !visited[newX][newY] && grid[newX][newY] != '0';
    }

    void bfs(vector<vector<char>>& grid, int srcX, int srcY, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;

        q.push({srcX, srcY});
        visited[srcX][srcY] = true;

        while (!q.empty()) {
            pair<int, int> frontNodePair = q.front();
            q.pop();

            int tempX = frontNodePair.first;
            int tempY = frontNodePair.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if (isSafe(newX, newY, grid, visited)) {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '0' && !visited[i][j]) {
                    bfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};
