class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> & vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[x][y] = 1;
        for (int a = 0; a < 4; a++)
        {
            int nx = x + dx[a];
            int ny = y + dy[a];
            if (nx >= 0 and ny >= 0 and nx < n and ny < m and !vis[nx][ny] and grid[nx][ny])
            {
                dfs(nx, ny, grid, vis);
            }
        }
    }
    int count_islands(vector<vector<int>> & grid)
    {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and grid[i][j])
                {
                    dfs(i, j, grid, vis);
                    islands ++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int islands = count_islands(grid);
        int n = grid.size();
        int m = grid[0].size();
		// check for 0 ans
        if (islands > 1 or islands == 0)
        {
            return 0;
        }
        else
        {
			// check for 1 ans
            for (int i = 0 ; i < n; i ++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j])
                    {
                        grid[i][j] = 0;
						// remove this block
                        islands = count_islands(grid);
						// add back the block
                        grid[i][j] = 1;
                        if (islands > 1 or islands == 0)
                            return 1;
                    }

                }
            }
        }
		// else
        return 2;
    }
};