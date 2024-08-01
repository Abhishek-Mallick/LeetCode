class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string it : details) {
            // int temp = stoi(it.substr(11,2));

            int digit1 = it[11] - '0';
            int digit2 = it[12] - '0';
            int temp = digit1*10 + digit2;

            if(temp > 60)
                res++;
        }
        return res;
    }
};