//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        long long count = 0;
         for (int i = 0; i < 31; i++) {
            int x = 1 << i;
            long long y = (N + 1) / (x * 2) * x;
            long long z = (N + 1) % (x * 2) - x;
            count += y + std::max(z, 0LL);
        }
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends