//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n1, int m1, string text1, string text2)
    {
        int n = text1.size();
    int m = text2.size();
 
    // initializing 2 vectors of size m
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
 
    for (int idx2 = 0; idx2 < m + 1; idx2++)
        cur[idx2] = 0;
 
    for (int idx1 = 1; idx1 < n + 1; idx1++) {
        for (int idx2 = 1; idx2 < m + 1; idx2++) {
            // if matching
            if (text1[idx1 - 1] == text2[idx2 - 1])
                cur[idx2] = 1 + prev[idx2 - 1];
 
            // not matching
            else
                cur[idx2]
                    = 0 + max(cur[idx2 - 1], prev[idx2]);
        }
        prev = cur;
    }
 
    return cur[m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends