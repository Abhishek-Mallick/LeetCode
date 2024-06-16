#define ll long long
#define mod 24
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, long long> freq;
        ll ans = 0;

        for(int i=0;i<hours.size();i++) {
            int req = (24 - hours[i] % mod) % mod;
            ans += freq[req];
            freq[hours[i] % mod]++;
        }
        return ans;
    }
};