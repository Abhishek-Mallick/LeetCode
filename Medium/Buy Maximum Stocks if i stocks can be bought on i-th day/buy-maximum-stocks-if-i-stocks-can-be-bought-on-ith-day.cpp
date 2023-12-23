//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> mp;
        int ans = 0;
        
        for(int i=0;i<n;i++)
            mp.push_back(make_pair(price[i],i+1));
            
        sort(mp.begin(),mp.end(),[](const auto& a,const auto& b){
            return a.first < b.first;
        });
        
        for(int i=0;i<n;i++)
        {
            int pick = k / mp[i].first;
            ans += min(mp[i].second,pick);
            k -= mp[i].first * min(mp[i].second,pick);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends