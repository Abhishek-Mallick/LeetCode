//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    // DFS Traversal to find the count of
    // island surrounded by water
    void dfs(vector<vector<int> >& matrix,
             vector<vector<bool> >& visited, int x, int y,
             int n, int m, bool &hasCornerCell)
    {
        // If the land is already visited
        // or there is no land or the
        // coordinates gone out of matrix
        // break function as there
        // will be no islands
        if (x < 0 || y < 0 || x >= n || y >= m
            || visited[x][y] == true || matrix[x][y] == 0)
            return;
     
          // Check for the corner cell
        if(x == 0 || y == 0 || x == n-1 || y == m-1)
        {
          if(matrix[x][y] == 1)
            hasCornerCell = true;
        }
       
        // Mark land as visited
        visited[x][y] = true;
     
        // Traverse to all adjacent elements
        dfs(matrix, visited, x + 1, y, n, m, hasCornerCell);
        dfs(matrix, visited, x, y + 1, n, m, hasCornerCell);
        dfs(matrix, visited, x - 1, y, n, m, hasCornerCell);
        dfs(matrix, visited, x, y - 1, n, m, hasCornerCell);
    }
    
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Create boolean 2D visited matrix
        // to keep track of visited cell
     
        // Initially all elements are
        // unvisited.
        vector<vector<bool>> visited(n,vector<bool>(m, false));
     
        // Store the count of islands
        int result = 0; 
       
        // Call DFS on the cells which
        // are not on corners with value '1'
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
     
                if ((i != 0 && j != 0 && i != n - 1 && j != m - 1)
                    and matrix[i][j] == 1
                    and visited[i][j] == false)
                {
                   
                    // Determine if the island is closed
                      bool hasCornerCell = false;
                       
                    /* hasCornerCell will be
                     updated to true while DFS traversal
                    if there is a cell with value
                     '1' on the corner */
                    dfs(matrix, visited, i, j, n,
                                  m, hasCornerCell);
                     
                    /* If the island is closed*/
                      if(!hasCornerCell)
                      result = result + 1;
                }
            }
        }
     
        // Return the final count
        return result;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends