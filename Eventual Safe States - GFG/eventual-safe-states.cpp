//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfscheck(int node,int vis[],int dfsvis[],int safecheck[],vector<int> adj[])
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        
        //traversal of ajd
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfscheck(it,vis,dfsvis,safecheck,adj) == true)
                    return true;
            }
            else if(dfsvis[it] == 1)
                return true;
        }
        safecheck[node] = 1;
        dfsvis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int dfsVis[V] = {0};
        int safecheck[V] = {0};
        
        vector<int> safeNodes;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfscheck(i,vis,dfsVis,safecheck,adj);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(safecheck[i] == 1)
                safeNodes.push_back(i);
        }
        return safeNodes;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends