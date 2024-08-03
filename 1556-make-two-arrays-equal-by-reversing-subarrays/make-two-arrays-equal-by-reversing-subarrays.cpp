class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // int n = target.size();
        // sort(target.begin(),target.end());
        // sort(arr.begin(),arr.end());

        // for(int i=0;i<n;i++)
        //     if(target[i] != arr[i])
        //         return false;
        
        // return true;

        unordered_map<int, int> mp;
        for(int num : arr)
            mp[num]++;
        
        for(int num : target) {
            if(mp.find(num) == mp.end())
                return false;
            
            mp[num]--;
            if(mp[num] == 0)
                mp.erase(num);
        }
        return mp.size() == 0;
    }
};