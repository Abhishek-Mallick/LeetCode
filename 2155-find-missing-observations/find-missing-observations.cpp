class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res(n);
        int sum = 0;

        for(int i=0;i<rolls.size();i++)
            sum += rolls[i];

        int remain = mean * (n + rolls.size()) - sum;

        if(remain > 6 * n || remain < n)
            return {};

        int divided = remain / n;
        int modded = remain % n;

        for(int i=0;i<n;i++)
            res[i] = divided;
        
        for(int i=0;i<modded;i++)
            res[i]++;
        
        return res;
    }
};