//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        int result = 0;
        
        // Xor of alternating numbers from index 0
        for(int i = 0; i < N; i++)
        {
            // If index is even, perform xor operation
            if(i % 2 == 0)
                result = result ^ A[i];
        }
        
        // If N is even, ans will always be 0, else return xor of alternating elements.
        if(N % 2 == 0)
            return 0;
        else
            return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends