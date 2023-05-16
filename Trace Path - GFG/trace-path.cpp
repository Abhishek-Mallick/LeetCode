//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int maxl = 0, maxr = 0, maxu = 0, maxd = 0, c1 = 0, c2 = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == 'L')
                c1--;
            else if(s[i] == 'R')
                c1++;
            else if(s[i] == 'U')
                c2++;
            else
                c2--;
            if(c1 >= 0)
                maxr = max(c1, maxr);
            else
                maxl = min(c1, maxl);
            if(c2 >= 0)
                maxu = max(c2, maxu);
            else
                maxd = min(c2, maxd);
        }
        if(maxr + 1 - maxl <= m && maxu + 1 - maxd <= n)
            return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends