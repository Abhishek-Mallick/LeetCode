class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int max_element = INT_MIN;
        for(int it : nums)
            max_element = max(max_element, it);
        vector<int> distanceBucket(max_element+1,0);

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int dist = abs(nums[i] - nums[j]);

                distanceBucket[dist]++;
            }
        }

        for(int dist = 0;dist <= max_element;dist++) {
            k -= distanceBucket[dist];

            if(k <= 0)
                return dist;
        }
        return -1;
    }
};