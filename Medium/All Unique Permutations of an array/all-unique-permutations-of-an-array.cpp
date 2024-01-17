//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void generator(vector<int> curr, vector<vector<int>> &result, int i, vector<int> A, map<vector<int>,int> &hash){
        if(curr.size()==A.size())
        {
            // Check if the current permutation has not been generated before
            if(hash.find(curr)==hash.end())
            {
                result.push_back(curr);
                hash[curr]=1;
            }
            return;
        }
        else
        {
            // Generate permutations by swapping elements at position i with elements starting from i
            for(int j=i; j<A.size(); j++)
            {
                curr.push_back(A[j]);
                swap(A[i],A[j]);
                
                // Recursive call to generate permutations with updated current permutation
                generator(curr,result,i+1,A,hash);
                
                curr.pop_back();
                swap(A[i],A[j]); // Swap back elements to restore original array
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<int> curr;
        vector<vector<int>> result;
        map<vector<int>,int> hash;
        
        // Call the permutation generator function
        generator(curr,result,0,arr,hash);
        
        sort(result.begin(),result.end()); // Sort the result array in ascending order
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends