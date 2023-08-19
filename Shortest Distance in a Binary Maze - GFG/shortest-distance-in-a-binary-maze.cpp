//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,1,0,-1};
        
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        
        if(source.first == destination.first && source.second == destination.second)
            return 0;
        
        while(!q.empty())
        {
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int new_row = row + del_row[i];
                int new_col = col + del_col[i];
                
                if(new_row >= 0 && new_row < n && new_col >=0 && new_col < m && grid[new_row][new_col] == 1 && dis + 1 < dist[new_row][new_col])
                {
                    dist[new_row][new_col] = 1 + dis;
                    if(new_row == destination.first && new_col == destination.second)
                        return dis + 1;
                    q.push({1+dis,{new_row,new_col}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends