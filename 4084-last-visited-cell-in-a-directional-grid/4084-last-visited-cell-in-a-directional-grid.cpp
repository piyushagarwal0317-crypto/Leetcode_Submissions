
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        auto isSafe = [&](int r, int c) {
            return r >= 0 && r < n && c >= 0 && c < m;
        };

        int x = 0, y = 0;
        //grid[x][y] = 'X';

        while(1){
            int nx = x, ny = y;
            char dir = grid[x][y];
            grid[x][y] = 'X';

            if (dir == 'L') ny--;
            else if (dir == 'R') ny++;
            else if (dir == 'U') nx--;
            else if (dir == 'D') nx++;

            if (!isSafe(nx, ny) || grid[nx][ny] == 'X') {
                return {x, y};
            }

            x = nx;
            y = ny;
        }

        return {x, y};
    }
};
