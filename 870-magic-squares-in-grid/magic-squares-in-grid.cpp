class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        int visited[10] = { 0 };

        // check range and visited status
        for(int i=0;i < 3;i++) {
            for(int j=0;j < 3;j++) {
                int num = grid[row+i][col+j];
                if(num < 1 || num > 9)
                    return false;
                if(visited[num])
                    return false;
                visited[num] = 1;
            }
        }
        int diagonal1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diagonal2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];

        if(diagonal1 != diagonal2)
            return false;
        
        int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int row2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int row3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];

        if(!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1))
            return false;

        int col1 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int col2 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int col3 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];

        if(!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal1))
            return false;
        
        return true;
        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int row = 0;row+2<m;row++) {
            for(int col = 0;col+2 < n;col++) {
                if(isMagicSquare(grid,row,col))
                    ans++;
            }
        }
        return ans;
    }
};