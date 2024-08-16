class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = 1e5;
        int maxi = -1e5;
        int diff = 0;

        for(int i=0;i<arrays.size();i++) {
            int a1 = arrays[i][0];
            int a2 = arrays[i].back();

            diff = max(diff,max(maxi - a1, a2 - mini));

            maxi = max(maxi,a2);
            mini = min(mini,a1);
        }
        return diff;
    }
};