//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    const ll MOD = 1e9 + 7;
	    ll a[n], b[n];
	    a[0] = b[0] = 1;
	    //loop to calculate the number of strings.
	    for (int i = 1; i < n; i++) {
	        //calculating a[i] and b[i] based on previous values.
	        a[i] = (a[i - 1] % MOD + b[i - 1] % MOD) % MOD;
	        b[i] = a[i - 1] % MOD;
	    }
	    //returning the sum of a[n-1] and b[n-1] modulo MOD.
	    return (a[n - 1] % MOD + b[n - 1] % MOD) % MOD;

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends