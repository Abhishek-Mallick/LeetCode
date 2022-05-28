// *Author - Abhishek Mallick*

Using XOR operation - 
        Two consequitive xor operations with the same number will eliminate
        the duplicate number and reveal the original number
            a^b^b = a

class Solution {
    public int missingNumber(int[] nums) {
        int x=0,i=0;
        for(i=0;i<nums.length;i++)
            x=x^i^nums[i];
        return x^i;
    }
}

Using Sum -
        Calculate the sum of first n natural numbers by l*(l+1)/2
        and store it in sum and then iterate over the array and extract each
        element and substract it from the sum the output will be the missing number

class Solution {
    public int missingNumber(int[] nums) {
        int len = nums.length;
        int sum = len*(len+1)/2;
        for(int i=0;i<len;i++)
            sum-=nums[i];
        return sum;
     }
 }
