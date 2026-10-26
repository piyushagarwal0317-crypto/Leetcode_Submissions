class Solution {
public:
    int n, m;
    
    long long dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> & dir){

        long long sum = grid[i][j];
        grid[i][j] = 0; // marked vis

        for (auto &it : dir){

            int x = i + it[0];
            int y = j + it[1];

            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                sum += 1LL * dfs(x, y, grid, dir);
            }
        }
        return sum;
    }


    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();

        vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && dfs(i, j, grid, dir) % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};