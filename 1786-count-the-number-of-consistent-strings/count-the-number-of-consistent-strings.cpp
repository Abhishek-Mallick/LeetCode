class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int consistentCount = 0;

        for (string& word : words) {
            bool isWordConsistent = true;
            
            for (int i = 0; i < word.length(); i++) {
                char currentChar = word[i];
                bool isCharAllowed = false;

                for (int j = 0; j < allowed.length(); j++) {
                    if (allowed[j] == currentChar) {
                        isCharAllowed = true;
                        break;
                    }
                }

                if (!isCharAllowed) {
                    isWordConsistent = false;
                    break;
                }
            }

            if (isWordConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};