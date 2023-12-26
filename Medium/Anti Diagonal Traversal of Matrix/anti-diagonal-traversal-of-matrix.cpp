//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        int n = matrix.size();
        vector<pair<int,int>> v;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
            v.push_back(make_pair(0,i));
        for(int j=1;j<n;j++)
            v.push_back(make_pair(j,n-1));
            
        for(int i=0;i<2*n-1;i++)
        {
            int x = v[i].first;
            int y = v[i].second;
            
            while(x < n && y >= 0)
            {
                ans.push_back(matrix[x][y]);
                x += 1;
                y -= 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends