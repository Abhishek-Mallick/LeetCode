//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        for(int i=1;i<=n;i++)
            parent[i] = i;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[1] = 0;
        pq.push({0,1});
        while(!pq.empty())
        {
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;
                if(dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dis+edgeWt,adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9)
            return {-1};
        int node = n;
        while(parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends