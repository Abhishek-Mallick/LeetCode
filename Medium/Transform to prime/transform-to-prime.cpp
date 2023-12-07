//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    int size;
    bool isPrime[1000005];
    public:
    void sieveOfEratosthenes()
    {
        memset(isPrime,true,sizeof(isPrime));
        isPrime[1] = false;
        for(int i=2;i*i<=size;i++)
        {
            if(isPrime[i])
            {
                for(int j=2*i;j<size;j+=i)
                    isPrime[j] = false;
            }
        }
    }
    
    int findPrime(int n)
    {
        int num = n + 1;
        while(num)
        {
            if(isPrime[num])
                return num;
            num += 1;
        }
        return 0;
    }
    
    int minNumber(int arr[],int N)
    {
        long long sum = 0;
        for(int i=0;i<N;i++)
            sum += arr[i];
            
        size = 1000005;
        sieveOfEratosthenes();
        
        if(isPrime[sum])
            return 0;
        int num = findPrime(sum);
        return num - sum;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends