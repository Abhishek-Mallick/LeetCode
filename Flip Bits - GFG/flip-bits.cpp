//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxSubArray(int a[],int n)
    {
        int max_so_far = a[0];
        int curr_max = a[0];
        
        for(int i=1;i<n;i++)
        {
            curr_max = max(a[i],curr_max+a[i]);
            max_so_far = max(max_so_far,curr_max);
        }
        max_so_far = max(0,max_so_far);
        return max_so_far;
    }
    int maxOnes(int a[], int n)
    {
        int i;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == 0)
                a[i] = 1;
            else
            {
                count++;
                a[i] = -1;
            }
        }
        return (count+maxSubArray(a,n));
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends