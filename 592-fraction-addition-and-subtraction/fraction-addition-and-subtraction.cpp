class Solution {
public:
    int gcd(int a,int b) {
        if(b == 0)
            return a;
        return gcd(b,a%b);
    }
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 1;
        int i = 0;
        int n = expression.size();

        while(i < n) {
            int currNumerator = 0;
            int currDenominator = 0;

            bool isNeg = (expression[i] == '-');

            if(expression[i] == '+' || expression[i] == '-')
                i++;
            
            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNumerator = (currNumerator * 10) + val;
                i++;
            }

            i++; // skipping divisor sign for denominator

            if(isNeg)
                currNumerator = -currNumerator;

            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDenominator = (currDenominator * 10) + val;
                i++;
            }

            numerator = (numerator * currDenominator) + (currNumerator * denominator);
            denominator = denominator * currDenominator;
        }

        int gc = gcd(abs(numerator),denominator);
        numerator /= gc;
        denominator /= gc;

        return to_string(numerator) + "/" + to_string(denominator);
    }
};