class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0)
            return 0;
        if(n == 1 && k == 1)
            return 1;
        if(k >= n)
            return n;
        
        unordered_map<int,int> freq;
        int len = 0;
        int i = 0,j = 0;
        while(j < n)
        {
            freq[nums[j]]++;
            if(freq[nums[j]] > k)
            {
               while(i < j && freq[nums[j]] > k)
               {
                   if(freq[nums[i]] == 1)
                       freq.erase(nums[i]);
                   else if(freq[nums[i]] > 1)
                       freq[nums[i]]--;
                   i++;
               }
            }
            len = max(len,j-i+1);
            // cout << "i -> " << i << endl;
            // cout << "j -> " << j << endl;
            j++;
        }
        return len;
    }
};