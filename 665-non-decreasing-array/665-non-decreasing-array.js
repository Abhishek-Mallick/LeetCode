/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    for(let i=1,count=0;i<nums.length;i++)
        if(nums[i]<nums[i-1])
            if(count++ || (i>1 && i<nums.length-1 && nums[i-2]>nums[i] && nums[i+1]<nums[i-1]))
                return false;
    return true;
};