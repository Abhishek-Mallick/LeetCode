//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int mxp;
    vector<int> prime;
    Solution()
    {
      mxp=9999;
      prime=vector<int>(10001,1);
      prime[1]=0;
      //Seive Of Eratosthenes
      for(int i=2;i<=mxp;i++)
      {
        if(prime[i])
        {
          for(int j=2;j*i<=mxp;j++)
            prime[j*i]=0;
        }
      }
    } 

    int bfs(int source,int &destination)
    {
      vector<int> dp(10001,-1); //stores the shotest distance from source to destination
      vector<int> vis(10001); 
      queue<int> q;
      q.push(source);
      dp[source]=0;
      vis[source]=0;
      while(!q.empty())
      {
        int current=q.front();
        q.pop();
        if(vis[current])
          continue;
        vis[current]=1;
        string s=to_string(current);
        for(int i=0;i<4;i++)
        {
          for(char ch='0';ch<='9';ch++)
          {
            if(ch==s[i]||(ch=='0'&&i==0))
              continue;
            string nxt=s;
            nxt[i]=ch;
            int nxtN=stoi(nxt);
            if(prime[nxtN]&&dp[nxtN]==-1)
            {
              dp[nxtN]=1+dp[current];
              q.push(nxtN);
            }
          }
        }
      }
      return dp[destination];
    }
    
    int solve(int Num1,int Num2)
    {   
      return bfs(Num1,Num2);
    }
};



//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends