//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        int n = S.length();

        priority_queue<pair<char, int>,
                       vector<pair<char, int> >,
                       greater<pair<char, int> > >
            pq;

        for (int i = 0; i < k; i++) {
            pq.push({ S[i], i });
        }
        string ans = "";

        int maxi = -1;
        for (int i = k; i < n; i++) {

            pq.push({ S[i], i });

            while (pq.top().second <= maxi) {
                pq.pop();
            }

            pair<char, int> cur = pq.top();
            pq.pop();
            maxi = cur.second;
            ans.push_back(cur.first);
        }

        for (int i = 0; i < ans.length(); i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }

        return "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends