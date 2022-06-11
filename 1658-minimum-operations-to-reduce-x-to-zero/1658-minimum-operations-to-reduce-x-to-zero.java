class Solution {
    public int minOperations(int[] nums, int x) {
        int sum = 0;
        for(int num : nums)
            sum+=num;
        int target = sum-x;
        
        Map<Integer,Integer> map = new HashMap<>();
        map.put(0,-1);
        int len = -1;
        int prefixSum = 0;
        for(int i=0;i<nums.length;i++)
        {
            prefixSum+=nums[i];
            map.put(prefixSum,i);
            if(map.containsKey(prefixSum-target))
            {
                int currlen = i-map.get(prefixSum - target);
                len = Math.max(len,currlen);
            }
        }
        if(len == -1)
            return len;
        else
            return nums.length-len;
    }
}