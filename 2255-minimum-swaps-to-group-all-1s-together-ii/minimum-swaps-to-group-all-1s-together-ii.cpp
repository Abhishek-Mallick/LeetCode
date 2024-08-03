class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int windowSize = 0;

        for(int num : nums)
            windowSize += num;
        
        int curr_Zero = 0;
        for(int i=0;i<windowSize;i++) {
            if(nums[i] == 0)
                curr_Zero++;
        }

        int minZero = curr_Zero;
        int start = 0;
        int end = windowSize - 1;

        while(start < n) {
            if(nums[start] == 0)
                curr_Zero--;
            
            start++;
            end++;

            if(nums[end % n] == 0)
                curr_Zero++;
            
            minZero = min(minZero,curr_Zero);
        }
        return minZero;
    }
};