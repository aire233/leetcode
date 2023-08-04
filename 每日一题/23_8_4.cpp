class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x, y, cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cnt += (grid[i][j] == 0);
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
        return dfs(grid, x, y, cnt);     
    }
    int dfs(vector<vector<int>>& grid, int x, int y, int cnt){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) 
            return 0;
        if(grid[x][y] == 2) return cnt == -1;
        grid[x][y] = -1;
        int res = 0;
        for(int i = 0; i < 4; i++){
            int dx = x + dir[i][0], dy = y + dir[i][1];
            res += dfs(grid, dx, dy, cnt - 1);
        }
        grid[x][y] = 0;
        return res;
    }
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
};