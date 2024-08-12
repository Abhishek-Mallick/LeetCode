class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        int dirX[] = {-1,0,1,0};
        int dirY[] = {0,1,0,-1};
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
            return;
        
        visited[i][j] = true;

        for(int x=0;x<4;x++) {
            int new_i = i + dirX[x];
            int new_j = j + dirY[x];

            dfs(grid,new_i,new_j,visited);
        }
    }
    int numberOfIslands(vector<vector<int>>& grid) {
        int isIsland = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i = 0;i < m; i++) {
            for(int  j = 0;j<n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid,i,j,visited);
                    isIsland++;
                }
            }
        }
        return isIsland;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = numberOfIslands(grid);

        if(islands > 1 || islands == 0) {
            return 0;
        }
        else {
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    if(grid[i][j] == 1) {
                        grid[i][j] = 0;
                        islands = numberOfIslands(grid);
                        grid[i][j] = 1;
                        if(islands > 1 || islands == 0)
                            return 1;
                    }
                }
            }
        }
        return 2;
    }
};