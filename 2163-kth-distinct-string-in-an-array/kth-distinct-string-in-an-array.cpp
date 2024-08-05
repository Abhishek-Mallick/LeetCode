class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        int n = arr.size();
        for(string it : arr)
            mp[it]++;

        int x = 0;
        for(string str : arr) {
            if(mp[str] == 1)
                x++;
            if(x == k)
                return str;
        }
        return "";
    }
};