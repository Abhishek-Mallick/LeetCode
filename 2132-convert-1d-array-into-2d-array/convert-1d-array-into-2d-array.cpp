class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};
        }

        vector<vector<int>> resultArray(m, vector<int>(n));

        int index = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                resultArray[i][j] = original[index];
                index++;
            }
        }

        return resultArray;
    }
};