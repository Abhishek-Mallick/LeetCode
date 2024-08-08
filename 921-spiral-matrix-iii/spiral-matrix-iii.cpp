class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dirs = {
            {0,1}, // EAST
            {1,0}, // SOUTH
            {0,-1}, // WEST
            {-1,0} //NORTH
        };
        vector<vector<int>> res;

        int steps = 0;
        int dir = 0;

        res.push_back({rStart, cStart});

        while(res.size() < rows * cols) {
            if(dir == 0 || dir == 2) // EAST or WEST
                steps++;
            for(int count = 0;count < steps;count++) {
                rStart += dirs[dir][0];
                cStart += dirs[dir][1];

                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    res.push_back({rStart,cStart});
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
};