class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;

        map<long long, vector<int>> mp;
        for(int i=0;i<nums.size();i++) {
            vector<int> temp;
            int val = nums[i];
            if(val == 0) {
                mp[mapping[val]].push_back(val);
                continue;
            }
            while(val) {
                temp.push_back(val % 10);
                val /= 10;
            }

            long long num = 0;
            for(int j = temp.size()-1;j >= 0;j--)
                num = (num * 10) + mapping[temp[j]];
            mp[num].push_back(nums[i]);
        }
        for(auto it : mp)
            for(auto a : it.second)
                ans.push_back(a);
        
        return ans;
    }
};