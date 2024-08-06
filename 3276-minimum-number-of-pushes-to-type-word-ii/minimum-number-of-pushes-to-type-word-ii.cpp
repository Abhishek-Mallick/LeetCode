class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        int res = 0;

        for(char& c : word)
            freq[c- 'a']++;
        
        sort(freq.rbegin(),freq.rend());

        for(int i=0;i<26;i++) {
            if(freq[i] == 0)
                break;
            res += (i / 8 + 1) * freq[i];
        }
        return res;
    }
};