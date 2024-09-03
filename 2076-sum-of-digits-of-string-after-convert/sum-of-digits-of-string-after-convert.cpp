class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        int n = s.size();
        string formatted = "";
        
        for(char c : s) {
            int num = c - 'a' + 1;
            formatted += to_string(num);
        }

        for(int i=0;i<k;i++) {
            res = 0;
            for(char c : formatted) {
                res += c - '0';
            }
            formatted = to_string(res);
        }
        return res;
    }
};