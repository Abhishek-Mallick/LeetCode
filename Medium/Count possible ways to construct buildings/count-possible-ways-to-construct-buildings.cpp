//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    long MOD = 1e9 + 7;
	public:
	int TotalWays(int N)
	{
	    long a = 1,b = 1,c = 0;
	    
	    for(int i=1;i<=N;i++)
	    {
	        c = ((a % MOD) + (b % MOD)) % MOD;
	        a = b % MOD;
	        b = c % MOD;
	    }
	    return (int) ((c * c) % MOD);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends