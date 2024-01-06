//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    vector<int>spf(b+1,-1);
	    if(b==1)
	        return 0;
	    if(a==1)
	        a++;
	    for(int i=2;i<=b;i++)
	    {
	        if(spf[i]==-1)
	        {
	            for(int j=i;j<=b;j+=i)
    	            spf[j]=i;
	        }
	    }
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        int x=i;
	        while(x!=1)
	        {
	            x/=spf[x];
	            ans++;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends