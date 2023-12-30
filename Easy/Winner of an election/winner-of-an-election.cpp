//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> freq;
        vector<string> ans;
        unordered_set<string> res;
        
        
        for(int i=0;i<n;i++)
            freq[arr[i]]++;
        
        int maxi = INT_MIN;
        string temp = "";
        for(auto it=freq.begin();it != freq.end();it++)
        {
            if(it->second > maxi)
            {
                maxi = it->second;
                temp = it->first;
            }
            else if(it->second == maxi && temp.compare(it->first) > 0)
                temp = it->first;
        }
        ans.push_back(temp);
        ans.push_back(to_string(maxi));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends