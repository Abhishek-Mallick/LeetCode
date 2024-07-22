class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        map<int, string> mp;
        vector<string> res(n);

        for(int i=0;i<n;i++)
            mp[heights[i]] = names[i];
        
        for(auto [ele,name] : mp)
            cout << ele << " : " << name << endl;
        
        for(auto& [ele, name] : mp)
            res[--n] = name;
        
        return res;
    }
};