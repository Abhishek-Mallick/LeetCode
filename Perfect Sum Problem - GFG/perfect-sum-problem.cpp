//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = (int)(1e9 + 7); // Initialize mod value for calculations
    vector<vector<int>> dp; // 2D vector to store dynamic programming values
    int N; // Size of the array

    int fun(int pos, int sum, int arr[]) {
        if (pos >= N)
            return sum == 0; // Check if sum is zero when array position reaches end

        int &ans = dp[pos][sum]; // Reference to store calculated value in dp vector
        if (ans != -1)
            return ans; // Return the already calculated value from dp vector

        ans = 0; // Initialize answer with zero

        ans += fun(pos + 1, sum, arr); // Recursively call function for next position with sum unchanged
        ans %= mod; // Take modulo of the answer to avoid overflow
        if (arr[pos] <= sum)
            ans += fun(pos + 1, sum - arr[pos], arr), ans %= mod; // Recursively call function for next position with reduced sum

        return ans; // Return the calculated answer
           
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        dp.assign(n + 1, vector<int> (sum + 2, -1)); // Initialize dp vector with -1
        N = n; // Assign n to N variable
        
        return fun(0, sum, arr);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends