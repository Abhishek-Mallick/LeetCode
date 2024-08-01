class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string it : details) {
            int temp = stoi(it.substr(11,2));
            if(temp > 60)
                res++;
        }
        return res;
    }
};