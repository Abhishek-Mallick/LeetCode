class Solution {
public:
    int minimumTurns(int start, int end, string& s, vector<vector<int>>& memo) {
        if (start > end) {
            return 0;
        }

        if (memo[start][end] != -1) {
            return memo[start][end];
        }

        int minTurns = 1 + minimumTurns(start + 1, end, s, memo);

        for (int k = start + 1; k <= end; k++) {
            if (s[k] == s[start]) {
                int turnsWithMatch = minimumTurns(start, k - 1, s, memo) +
                                     minimumTurns(k + 1, end, s, memo);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }

        return memo[start][end] = minTurns;
    }

    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while (i < s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
    }
    int strangePrinter(string s) {
        s = removeDuplicates(s);
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return minimumTurns(0, n - 1, s, memo);
    }
};