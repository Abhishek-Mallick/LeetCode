//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    const int MOD = 1e9 + 7;
		int nthPoint(int n){
		    int dp[n+1] = {0};
		    dp[0] = 0;
		    dp[1] = 1;
		    dp[2] = 2;
		    for(int i=3;i<=n;i++)
		        dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD) % MOD;
		    return dp[n];
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends