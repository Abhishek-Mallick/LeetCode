class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += chalk[i];
            if(k < sum)
                break;
        }

        k = k % sum;
        for(int i=0;i<chalk.size();i++) {
            if(k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};