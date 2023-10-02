//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        if(n <= 26)
        {
            ans += (char)(64+n);
        }
        else
        {
            int temp = 0;
            while(n>0)
            {
                n--;
                temp = n % 26;
                ans += (char)('A'+temp);
                n = n / 26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends