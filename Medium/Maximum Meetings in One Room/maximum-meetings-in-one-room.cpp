//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<int> ans;
        vector<vector<int>> meet(N,vector<int>(3));
        
        int count = 1;
        for(int i=0;i<N;i++)
        {
            meet[i][0] = S[i];
            meet[i][1] = F[i];
            meet[i][2] = count++;
        }
        
        sort(meet.begin(),meet.end(),[](const auto& a,const auto& b){
            if(a[1] == b[1])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });
        
        ans.push_back(meet[0][2]);
        for(int i=1;i<N;i++)
        {
            if(F[ans.back()-1] < meet[i][0]){
                ans.push_back(meet[i][2]);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends