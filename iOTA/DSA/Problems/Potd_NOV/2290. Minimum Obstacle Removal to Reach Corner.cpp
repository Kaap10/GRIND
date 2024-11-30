class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [currentDist, cell] = pq.top();
            pq.pop();
            int x = cell.first;
            int y = cell.second;

            if (x == m - 1 && y == n - 1) {
                return currentDist;
            }

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = currentDist + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        pq.push({newDist, {nx, ny}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};