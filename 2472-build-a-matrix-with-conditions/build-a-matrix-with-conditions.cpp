class Solution {
public:
    vector<vector<int>> buildGraph(int k, vector<vector<int>> graph) {
        vector<vector<int>> adj(k+1);
        for(auto it : graph)
            adj[it[0]].push_back(it[1]);
        return adj;
    }
    vector<int> topoSort(int k, vector<vector<int>> adj) {
        vector<int> topo;
        vector<int> indegree(k+1,0);

        for(int node = 1;node <=k;node++) {
            for(int ne : adj[node])
                indegree[ne]++;
        }

        queue<int> q;
        for(int node = 1;node<=k;node++) {
            if(indegree[node] == 0)
                q.push(node);
        }

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();
                q.pop();

                topo.push_back(node);

                for(auto ne : adj[node]) {
                    indegree[ne]--;
                    if(indegree[ne] == 0)
                        q.push(ne);
                }
            }
        }

        for(int i=1;i<=k;i++){
            if(indegree[i] != 0)
                return {};
        }
        
        return topo;
    }
    void fillTopo(int k, vector<int>& arr) {
        unordered_map<int,bool> visited;

        for(int it : arr)
            visited[it] = true;
        
        for(int i=0;i<k;i++) {
            if(!visited[i])
                arr.push_back(i);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGr = buildGraph(k,rowConditions);
        vector<vector<int>> colGr = buildGraph(k,colConditions);

        vector<int> rowTopo = topoSort(k,rowGr);
        vector<int> colTopo = topoSort(k,colGr);

        vector<vector<int>> res(k,vector<int>(k,0));

        if(rowTopo.empty() || colTopo.empty())
            return {};
        
        fillTopo(k, rowTopo);
        fillTopo(k, colTopo);

        unordered_map<int,int> colInd;
        // {ele, index}
        for(int i=0;i<k;i++)
            colInd[colTopo[i]] = i;
        
        for(int i=0;i<k;i++)
            res[i][colInd[rowTopo[i]]] = rowTopo[i];

        return res;
    }
};