class Solution {
    public int maxSubArray(int[] nums) {
        int curr,max;
        curr = nums[0];
        max = nums[0];
        for(int i=1;i<nums.length;i++)
        {
            if(curr<0)
                curr = 0;
            curr = curr + nums[i];
            if(curr>max)
                max = curr;
        }
        return max;
    }
}