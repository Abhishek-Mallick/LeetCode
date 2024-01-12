//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        queue<int> qq;
    
        // we pop first k elements from queue and push it in the stack.
        while (k-- > 0) {
            int a = q.front();
            q.pop();
            s.push(a);
        }
    
        // while stack is not empty, we push the elements into the new queue.
        while (!s.empty()) {
            int a = s.top();
            s.pop();
            qq.push(a);
        }
    
        // then we add rest of the elements of original queue to the new queue.
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            qq.push(a);
        }
    
        // returning the new queue.
        return qq;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends