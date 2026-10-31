class Solution {
public:
const int MOD = 1e9 + 7;
// dir = 0 means move to right
// dir = 1 means move to down
    int n, m;
    vector<vector<vector<int>>> dp;

    int dfs(int i, int j, int dir, vector<vector<int>>& grid){

        if(i >= n || j >= m) return 0;

        if(i == n-1 && j == m-1) return 1;

        if(dp[i][j][dir] != -1) return dp[i][j][dir];

        // if mirror at cell i,j
        if(grid[i][j] == 1 && dir == 1){
            dp[i][j][dir] = dfs(i + 1, j, 0, grid);
        }
        else if(grid[i][j] == 1 && dir == 0){
            dp[i][j][dir] = dfs(i, j + 1, 1, grid);
        }

        // if no mirror at i,j -> can move right or down
        else dp[i][j][dir] = (dfs(i + 1, j, 0, grid) + dfs(i, j + 1, 1, grid)) % (MOD);

        return dp[i][j][dir];
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));

        return dfs(0, 0, 0, grid);
    }
};