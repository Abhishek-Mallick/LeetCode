//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        bool flag = false;
        int lastZero = -1;
        int lastOne = -1;
        int lastTwo = -1;
        int ans = INT_MAX;
        
        for(int i=0;i<S.size();i++)
        {
            if(S[i] == '0')
                lastZero = i;
            else if(S[i] == '1')
                lastOne = i;
            else if(S[i] == '2')
                lastTwo = i;
                
            if(lastZero != -1 && lastOne != -1 && lastTwo != -1)
            {
                flag = true;
                ans = min(ans,1 + i - min(lastZero,min(lastOne,lastTwo)));
            }
        }
        if(flag)
            return ans;
        else
            return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends