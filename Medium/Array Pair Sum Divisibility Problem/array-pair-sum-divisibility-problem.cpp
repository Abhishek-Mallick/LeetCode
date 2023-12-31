//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        // An odd length array cannot be divided into pairs
        if (n & 1) return false;

        // Create a frequency array to count occurrences
        // of all remainders when divided by k.
        map<int, int> freq;

        // Count occurrences of all remainders
        for (int i = 0; i < n; i++) freq[nums[i] % k]++;

        // Traverse input array and use freq[] to decide
        // if given array can be divided in pairs
        for (int i = 0; i < n; i++) {
            // Remainder of current element
            int rem = nums[i] % k;

            // If remainder with current element divides
            // k into two halves.
            if (2 * rem == k) {
                // Then there must be even occurrences of
                // such remainder
                if (freq[rem] % 2 != 0) return false;
            }

            // If remainder is 0, then there must be two
            // elements with 0 remainder
            else if (rem == 0) {
                if (freq[rem] & 1) return false;
            }

            // Else number of occurrences of remainder
            // must be equal to number of occurrences of
            // k - remainder
            else if (freq[rem] != freq[k - rem])
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends