class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveBills = 0;
        int tenBills = 0;

        for(int it : bills) {
            if(it == 5) {
                fiveBills++;
            } else if(it == 10) {
                if(fiveBills > 0) {
                    tenBills++;
                    fiveBills--;
                } else {
                    return false;
                }
            } else {
                if(tenBills > 0 && fiveBills > 0) {
                    fiveBills--;
                    tenBills--;
                } else if(fiveBills >= 3) {
                    fiveBills -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};