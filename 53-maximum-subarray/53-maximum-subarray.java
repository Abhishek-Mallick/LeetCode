class Solution {
    public int maxSubArray(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        int msf = nums[0];
        int meh = 0;
        int sum = 0;
        for(int i=0;i<nums.length;i++)
        {
            meh = meh + nums[i];
            if(meh > msf)
            {
                arr.clear();
                msf = meh;
                arr.add(sum);
                arr.add(i);
            }
            if(meh<0)
            {
                meh = 0;
                sum = i+1;
            }
        }
        return msf;
    }
}