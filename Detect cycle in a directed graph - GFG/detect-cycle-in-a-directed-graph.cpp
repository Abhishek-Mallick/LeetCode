//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfsCheck(int node,vector<int> adj[],int vis[], int pathvis[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        //traversal for adjacent nodes
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfsCheck(it,adj,vis,pathvis) == true)
                    return true;
            }
            else if(vis[it] == 1 && pathvis[it] == 1)
            {
                // if the node has been visited prviously
                // but has not been visited on the same path
                return true;
            }
        }
        
        pathvis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathvis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfsCheck(i,adj,vis,pathvis) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends