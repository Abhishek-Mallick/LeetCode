//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool check(int mid, int array[], int n, int K)
    {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
     
            // If individual element is greater
            // maximum possible sum
            if (array[i] > mid)
                return false;
     
            // Increase sum of current sub - array
            sum += array[i];
     
            // If the sum is greater than
            // mid increase count
            if (sum > mid) {
                count++;
                sum = array[i];
            }
        }
        count++;
     
        // Check condition
        if (count <= K)
            return true;
        return false;
    }

    int splitArray(int arr[] ,int N, int K) {
        int* max = max_element(arr, arr + N);
        int start = *max;
        int end = 0;
     
        for (int i = 0; i < N; i++)
            end += arr[i];
     
        // Answer stores possible
        // maximum sub array sum
        int answer = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
     
            // If mid is possible solution
            // Put answer = mid;
            if (check(mid, arr, N, K)) {
                answer = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
     
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends