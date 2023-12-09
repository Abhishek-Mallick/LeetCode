//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,bool> sumMap;
    
    	int sum = 0;
    	//iterating over the array.
    	for (int i = 0 ; i < n ; i++)
    	{
    	    //storing prefix sum.
    		sum += arr[i];
    
    		//if prefix sum is 0 or if it is already present in map then it is
    		//repeated which means there is a subarray whose summation is 0,
    		//so we return true.
    		if (sum == 0 || sumMap[sum] == true)
    			return true;
            
            //storing true in map for every prefix sum obtained.
    		sumMap[sum] = true;
    	}
    	//returning false if we don't get any subarray with 0 sum.
    	return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends