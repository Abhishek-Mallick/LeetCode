//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution
{
  public:
    // Returns adjacency list representation of graph from
    // given set of pairs.
    vector<vector<int> > make_graph(int numTasks,
                 vector<vector<int>>& prerequisites)
    {
        vector<vector<int> > graph(numTasks);
        for (auto pre : prerequisites)
            graph[pre[1]].push_back(pre[0]);
        return graph;
    }

    // Computes in-degree of every vertex
    vector<int> compute_indegree(vector<vector<int> >& graph)
    {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        // Create an adjacency list
        vector<vector<int>> graph =
                make_graph(n, prerequisites);

        // Find vertices of zero degree
        vector<int> degrees = compute_indegree(graph);
        queue<int> zeros;
        for (int i = 0; i < n; i++)
            if (!degrees[i])
                zeros.push(i);

        // Find vertices in topological order
        // starting with vertices of 0 degree
        // and reducing degrees of adjacent.
        vector<int> toposort;
        for (int i = 0; i < n; i++) {
            if (zeros.empty())
                return {};
            int zero = zeros.front();
            zeros.pop();
            toposort.push_back(zero);
            for (int neigh : graph[zero]) {
                if (!--degrees[neigh])
                    zeros.push(neigh);
            }
        }
        return toposort;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends