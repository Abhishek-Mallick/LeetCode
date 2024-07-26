class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        for(auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i=0;i<n;i++)
            dist[i][i] = 0;

        for(int via = 0;via < n;via++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        
        int mini = INT_MAX;
        int res = -1;
        for(int city = 0;city<n;city++) {
            int cntCity = 0;
            for(int adjCity=0;adjCity<n;adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold)
                    cntCity++;
            }
            if(cntCity <= mini) {
                mini = cntCity;
                res = city;
            }
        }
        return res;
    }
};