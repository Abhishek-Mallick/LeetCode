class Solution {
public:
int m,n;
    void dfs(vector<vector<int>>& arr,int i,int j) {
        if(i < 0 || j < 0 || i >= m*3 || j >= n*3 || arr[i][j] == 1){
            return;
        }
        arr[i][j] = 1;
        int dirX[] = {-1,0,1,0};
        int dirY[] = {0,1,0,-1};

        for(int x=0;x<4;x++)
            dfs(arr,i+dirX[x],j+dirY[x]);
    }
    int regionsBySlashes(vector<string>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> arr(m*3,vector<int>(n*3,0));
        int res = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '/') {
                    arr[i*3][j*3+2] = 1;
                    arr[i*3+1][j*3+1] = 1;
                    arr[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\') {
                    arr[i*3][j*3] = 1;
                    arr[i*3+1][j*3+1] = 1;
                    arr[i*3+2][j*3+2] = 1;
                }
            }
        }

        for(int i=0;i<m*3;i++) {
            for(int j=0;j<n*3;j++) {
                if(arr[i][j] == 0) {
                    dfs(arr,i,j);
                    res++;
                }     
            }
        }
        return res;
    }
};