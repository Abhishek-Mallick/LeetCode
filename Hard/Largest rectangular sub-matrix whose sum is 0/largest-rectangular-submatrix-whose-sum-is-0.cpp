//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  const int MAX = 100;
     
    // This function basically finds largest 0
    // sum subarray in temp[0..n-1]. If 0 sum
    // does't exist, then it returns false. Else
    // it returns true and sets starting and
    // ending indexes as starti and endj.
    bool sumZero(int temp[], int* starti,
                int* endj, int n)
    {
        // Map to store the previous sums
        map<int, int> presum;
        int sum = 0; // Initialize sum of elements
     
        // Initialize length of sub-array with sum 0
        int max_length = 0;
     
        // Traverse through the given array
        for (int i = 0; i < n; i++)
        {
            // Add current element to sum
            sum += temp[i];
     
            if (temp[i] == 0 && max_length == 0)
            {
                *starti = i;
                *endj = i;
                max_length = 1;
            }
            if (sum == 0)
            {
                if (max_length < i + 1)
                {
                    *starti = 0;
                    *endj = i;
                }
                max_length = i + 1;
            }
     
            // Look for this sum in Hash table
            if (presum.find(sum) != presum.end())
            {
                // store previous max_length so
                // that we can check max_length
                // is updated or not
                int old = max_length;
     
                // If this sum is seen before,
                // then update max_len
                max_length = max(max_length, i - presum[sum]);
     
                if (old < max_length)
                {
                    // If max_length is updated then
                    // enter and update start and end
                    // point of array
                    *endj = i;
                    *starti = presum[sum] + 1;
                }
            }
            else
     
                // Else insert this sum with
                // index in hash table
                presum[sum] = i;
        }
     
        // Return true if max_length is non-zero
        return (max_length != 0);
    }
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      int row = a.size();
        int col = a[0].size();
        int temp[row];
        
        // Variables to store the final output
        int fup = 0, fdown = 0, fleft = 0, fright = 0;
        int sum;
        int up, down;
        int maxl = INT_MIN;
     
        // Set the left column
        for (int left = 0; left < col; left++)
        {
            // Initialize all elements of temp as 0
            memset(temp, 0, sizeof(temp));
     
            // Set the right column for the left column
            // set by outer loop
            for (int right = left; right < col; right++)
            {
                // Calculate sum between current left
                // and right for every row 'i'
                for (int i = 0; i < row; i++)
                    temp[i] += a[i][right];
     
                // Find largest subarray with 0 sum in
                // temp[]. The sumZero() function also
                // sets values of start and finish. So
                // 'sum' is sum of rectangle between (start,
                // left) and (finish, right) which is
                // boundary columns strictly as left and right.
                bool sum = sumZero(temp, &up, &down, row);
                int ele = (down - up + 1) * (right - left + 1);
     
                // Compare no. of elements with previous
                // no. of elements in sub-Matrix.
                // If new sub-matrix has more elements
                // then update maxl and final boundaries
                // like fup, fdown, fleft, fright
                if (sum && ele > maxl)
                {
                    fup = up;
                    fdown = down;
                    fleft = left;
                    fright = right;
                    maxl = ele;
                }
            }
        }
        vector<vector<int>> ans;
        // If there is no change in boundaries
        // than check if a[0][0] is 0
        // If it not zero then print
        // that no such zero-sum sub-matrix exists
        if (fup == 0 && fdown == 0 && fleft == 0 &&
                fright == 0 && a[0][0] != 0) {
            // cout << "No zero-sum sub-matrix exists";
            return ans;
        }
        
        for (int j = fup; j <= fdown; j++)
        {
            vector<int> cnt;
            for (int i = fleft; i <= fright; i++){
                cnt.push_back(a[j][i]);
            }
            ans.push_back(cnt);
        }
        return ans;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends