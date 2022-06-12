class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Map<Integer,Integer> seen = new HashMap<>();
        int l=0,sum=0,ans=0;
        for(int r=0;r<nums.length;r++)
        {
            int x = nums[r];
            if(seen.containsKey(x))
            {
                int index = seen.get(x);
                while(l<=index)
                {
                    seen.remove(nums[l]);
                    sum -= nums[l];
                    l += 1;
                }
            }
            seen.put(x,r);
            sum += x;
            ans = Math.max(ans,sum);
        }
        return ans;
    }
}