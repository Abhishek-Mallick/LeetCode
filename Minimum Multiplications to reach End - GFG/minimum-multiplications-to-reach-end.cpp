//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int ans[100001];

        // -1 indicated the state has not been visited
        memset(ans, -1, sizeof(ans));
        const int mod = 100000;

        // queue to store all possible states
        queue<int> q;

        // initially push the start
        q.push(start % mod);

        // to reach start we require 0 steps
        ans[start] = 0;

        // till all states are visited
        while (!q.empty()) {

            // get the topmost element in the queue
            int top = q.front();

            // pop the topmost element
            q.pop();

            // if the topmost element is end
            if (top == end) return ans[end];

            // perform multiplication with all array elements
            for (int i = 0; i < arr.size(); i++) {
                int pushed = top * arr[i];
                pushed = pushed % mod;

                // if not visited, then push it to queue
                if (ans[pushed] == -1) {
                    ans[pushed] = ans[top] + 1;
                    q.push(pushed);
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends