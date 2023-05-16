//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    long long int num(int y)
    {
        if(y==0){return 1;}
        long long int x=2;
        for(int i=1;i<y;i++)
        {
            x=x<<1;
        }
        return x;
    }
    bool check(long long int n)
    {
        if(n==0){return false;}
        if(n==1){return true;}
        if(n%5!=0){return false;}
        else{return check(n/5);}
    }
    int cuts(string s){
        int l=s.length();
        int dp[l+1];
        dp[0]=0;
        for(int i=1;i<=l;i++)
        {
            int index=i-1;
            if(s[index]=='0'){dp[i]=-1;}
            else
            {
                dp[i]=-1;
                int t=1000;
                long long int count=0;
                for(int j=0;j<i;j++)
                {
                    if(s[index-j]=='1')
                    {
                        count+=num(j);
                        if(check(count)&dp[index-j]!=-1)
                        {
                            int w=1+dp[index-j];
                            t=(w<t)?w:t;
                        }
                    }
                }
                if(t!=1000){dp[i]=t;}
            }
        }
        
        return dp[l];
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends