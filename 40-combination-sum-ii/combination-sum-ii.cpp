class Solution {
public:
    vector<vector<int>> ans;
    void func(int index, vector<int>& combination, vector<int>& candidates, int target) {
        if(target == 0) {
            ans.push_back(combination);
            return;
        }

        for(int i = index;i < candidates.size() && target >= candidates[i];i++) {
            if(i == index || candidates[i] != candidates[i-1]) {
                combination.push_back(candidates[i]);
                func(i+1,combination,candidates,target-candidates[i]);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        func(0,combination,candidates,target);
        return ans;
    }
};