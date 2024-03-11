class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> freq;
        for(auto el : s)
            freq[el]++;
        
        string ans = "";
        for(auto el : order) {
            while(freq[el]-- > 0)
                ans.push_back(el);
        }

        for(auto [el,fr] : freq) {
            while(fr-- > 0)
                ans.push_back(el);
        }
        return ans;
    }
};