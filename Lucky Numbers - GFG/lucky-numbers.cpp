//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
    bool check(int n,int counter)
{
    if(counter<=n) {
        if(n%counter==0)
            return false;
        //calculate next position of input no 
        n = n-n/counter;
        counter++;
        //make recursive call with updated counter 
        //and position return check(n, counter);
        return check(n, counter);
    }
    else
        return true;
}
public:
    bool isLucky(int n) {
        return check(n, 2);
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends