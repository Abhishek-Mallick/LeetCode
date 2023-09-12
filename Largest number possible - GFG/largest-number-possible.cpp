//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans = "";

        //If the sum of digits is 0 and number of digits is more than 1,
        //return -1 since it is not possible to form a number with only 0 digits.
        if(S == 0 && N > 1)
            return "-1";

        //Iterating over each digit in the number.
        for(int i = 0; i < N; i++){

            //If the sum is greater than or equal to 9,
            //we add '9' to the number and subtract 9 from the sum.
            if(S >= 9){
                ans += '9';
                S -= 9;
            }
            //If the sum is less than 9, we add the corresponding digit
            //to the number and set the sum to 0.
            else{
                ans += char(48 + S);
                S = 0;
            }
        }

        //If there is any remaining sum, it means we were not able to
        //use up the entire sum, so we return -1.
        if(S > 0)
            return "-1";

        //Returning the largest number that can be formed.
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Endso numbers 'N' and 'S' , find the largest number