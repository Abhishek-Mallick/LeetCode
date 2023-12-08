//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  bool isprime(int num){
      if(num==1){
          return false;
      }
      for(int i=2;i<=sqrt(num);i++){
          if(num%i==0){
              return false;
          }
      }
      
      return true;
  }
    int smithNum(int n) {
        if(isprime(n)){
            return false;
        }
        int temp=n;
        int sum=0;
        while(temp!=0){
            sum+=temp%10;
            temp/=10;
        }
        int sum2=0;
        int temp2=n;
        for (int i = 2; i <=n; i++) {
        while (temp2 % i == 0 && temp2 != 0) {
            int factorDigitSum = 0;
            int factor = i;
            while (factor != 0) {
                factorDigitSum += factor % 10;
                factor /= 10;
            }

            sum2 += factorDigitSum;
            temp2 /= i;
        }
    }

    if (sum == sum2 && temp2 == 1) {
        return 1;
    } else {
        return 0;
    }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends