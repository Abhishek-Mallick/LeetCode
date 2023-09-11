//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        long long sum = 1;
        
        // Find all divisors and add them 
        for(int i=2 ; i<=sqrt(N) ; i++)
        {
            if(N%i==0)
            {
                if(i==N/i)
                    sum+=i;
                else
                {
                    sum+=i;
                    sum+=N/i;
                }
            }
        }
        
        // If sum of divisors is equal to 
        // N, then N is a perfect number 
        if(sum==N && N!=1)
            return 1;
        else
            return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends