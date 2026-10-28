class Solution {
public:
    int xorr = INT_MAX;
    int m, n;

    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int xorr, vector<vector<int>>& grid) {

        if (i >= m || j >= n)
            return 1e8;
        xorr ^= grid[i][j];
        if (dp[i][j][xorr] != -1)
            return dp[i][j][xorr];
        if (i == m - 1 && j == n - 1) {
            return xorr;
        }

        int rt = solve(i, j + 1, xorr, grid);
        int dwn = solve(i + 1, j, xorr, grid);

        return dp[i][j][xorr] = min(rt, dwn);
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m + 1, vector<vector<int>>(n + 1, vector<int>(1024, -1)));

        return solve(0, 0, 0, grid);
    }
};