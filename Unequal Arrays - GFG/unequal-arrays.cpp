//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        long long sum = 0;
        vector<int> AP[2], BP[2];
        for(int i = 0; i < N; i++) {
           sum += A[i] - B[i];
           AP[abs(A[i]) % 2].push_back(A[i]);
           BP[abs(B[i]) % 2].push_back(B[i]);
        }
        if(sum != 0 || (int)AP[0].size() != (int)BP[0].size())
        return -1;
        
        long long ans = 0;
        for(int i = 0; i < 2; i++) {
           sort(AP[i].begin(), AP[i].end());
           sort(BP[i].begin(), BP[i].end());
        
           for(int j = 0; j < (int)AP[i].size(); j++) {
               ans += abs(AP[i][j] - BP[i][j]) / 2;
           }
        }
        return ans / 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends