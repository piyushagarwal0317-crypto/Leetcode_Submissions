class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j){

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == -1 || grid[i][j] == 1)
            return;

        grid[i][j] = -1; // mark vis

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);

    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // bpundary pe koi islands nhi banega 0 se since not surrounded by water

         for (int i = 0; i < n; i++){
            dfs(grid, i, 0);
            dfs(grid, i, m - 1);
        } // marking the zeroes vis

        for (int j = 0; j < m; j++){
            dfs(grid, 0, j);
            dfs(grid, n - 1, j);
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 0){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};