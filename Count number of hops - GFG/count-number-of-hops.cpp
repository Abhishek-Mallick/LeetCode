//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long mod=1e9+7;
        
        //base cases
    	if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        
        //initializng base values.
        long long int a = 1, b = 2, c = 4, temp;
        
        for (int i = 4; i <= n; i++)
        {
            temp = (a + b + c)%mod;
            //updating a as b and b as c and c as temp (sum of a, b and c).
            a = b;
            b = c;
            c = temp;
        }
        //returning the result.
        return c;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends