class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums)
            freq[num]++;
        
        int sum = 0;
        int maxi = 0;
        for(auto it : freq)
            maxi = max(maxi,it.second);
        
        for(auto it : freq)
            if(it.second == maxi)
                sum += it.second;
        
        return sum;
    }
};