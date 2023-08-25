//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> m;
        int uniq = 0, i = 0, j = 0, res = 0, n = s.length();
    
        while (j < n) {
            // sliding the j-pointer till we have a valid substring
            while (j < n) {
                if (m[s[j]] == 0) uniq++;
                m[s[j]]++;
                // if the number of uniq characters increases k, we stop.
                if (uniq > k) break;
                j++;
            }
    
            // checking if the unique characters are equal to k or k + 1
            if (uniq >= k) res = max(res, j - i);
    
            if (j == n) break;
    
            // sliding the i-pointer till we again get k unique characters in the
            // substring
            while (i < n) {
                if (m[s[i]] == 1) uniq--;
                m[s[i]]--;
    
                if (uniq == k) break;
                i++;
            }
            i++;
            j++;
        }
        if (res == 0) return -1;
            return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends