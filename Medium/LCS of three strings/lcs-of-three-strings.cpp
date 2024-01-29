//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int memo[101][101][101];
        int solve (string &A, string &B, string &C, int i, int j, int k, int n1, int n2, int n3)
        {
            if (i == n1 || j == n2 || k == n3)
                return 0;
        
            if (memo[i][j][k] != -1) return memo[i][j][k];
            
            // if all the characters are same, we can include them in the longest length
            // and check for the longest length in state (i + 1, j + 1, k + 1)
            if (A[i] == B[j] and A[i] == C[k])
                return memo[i][j][k] = 1 + solve (A, B, C, i + 1, j + 1, k + 1, n1, n2, n3);
        
            // if the characters do not match, we simply call for all the possible recursions
            // and store the maximum we get out of them
            return memo[i][j][k] = max ({solve (A, B, C, i + 1, j, k, n1, n2, n3),
                                         solve (A, B, C, i, j + 1, k, n1, n2, n3),
                                         solve (A, B, C, i, j, k + 1, n1, n2, n3)
                                        });
        }
    
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            for (int i = 0; i < n1; ++i)
            {
                for (int j = 0; j < n2; ++j)
                {
                    for (int k = 0; k < n3; ++k)
                    {
                        memo[i][j][k] = -1;
                    }
                }
            }
            return solve (A, B, C, 0, 0, 0, n1, n2, n3);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends