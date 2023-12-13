//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        long long dp[n + 1];

        //Initializing the dp array with 0.
        memset(dp, 0, sizeof(dp));

        //Setting the base case, when there is only 1 fence.
        dp[1] = k;

        //Initializing variables to keep count of same and different color fences.
        long long same = 0, diff = k;

        //Iterating over the fences starting from 2.
        for (int i = 2; i <= n; i++)
        {
            //Updating the value of same to the previous value of diff.
            same = diff;

            //Calculating the number of ways for different color fences.
            diff = dp[i-1] * (k-1);
            diff%=1000000007;

            //Calculating the total number of ways.
            dp[i] = (same + diff);
            dp[i]%=1000000007;
        }

        //Returning the number of ways for n fences.
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends