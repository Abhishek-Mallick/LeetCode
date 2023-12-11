//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n+2][m+2];
        
        // Initialize all cells in dp to 0
        memset(dp, 0, sizeof(dp));
        
        // Iterate through each column and row
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                // Calculate the maximum amount of gold at the current cell
                dp[j][i] = M[j-1][i-1] + max(dp[j-1][i-1], max(dp[j][i-1], dp[j+1][i-1]));
            }
        }
        
        // Find the maximum amount of gold in the last column
        int ans = INT_MIN;
        for(int i = 0;i <= n;i++)
            ans = max(dp[i][m], ans);
        
        // Return the maximum amount of gold
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends