class Solution {
public:
    vector<vector<int>> ans;
    void func(int i, vector<int>& candidates, vector<int>& combinations, int target) {
        if(target == 0) {
            ans.push_back(combinations);
            return;
        }

        if(target < 0)
            return;
        
        if(i == candidates.size())
            return;

        // not take
        func(i+1,candidates,combinations, target);

        combinations.push_back(candidates[i]);
        // take
        func(i,candidates,combinations,target-candidates[i]);
        combinations.pop_back(); // since same number contributes
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> combinations;
        func(0,candidates,combinations,target);
        return ans;
    }
};