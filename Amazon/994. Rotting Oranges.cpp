class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0;

        int time = 0;
        vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int sz = q.size();
            bool changed = false;
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOranges--;
                        changed = true;
                    }
                }
            }
            if (changed) time++;
        }

        return freshOranges == 0 ? time : -1;
    }
};
