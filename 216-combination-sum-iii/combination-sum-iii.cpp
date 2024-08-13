class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int>& combinations, int k, int target) {
        if(combinations.size() == k && target == 0) {
            ans.push_back(combinations);
            return;
        }

        if(combinations.size() < k) {
            int index = combinations.empty() ? 1 : combinations.back() + 1;
            for(int i = index;i <= 9; i++) {
                if(target - i < 0)
                    break;
                
                combinations.push_back(i);
                func(combinations,k,target-i);
                combinations.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> combinations;
        func(combinations, k, n);
        return ans;
    }
};