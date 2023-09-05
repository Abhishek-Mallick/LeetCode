//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int u, vector<int>adj[], vector<bool>&vis)
	{
	    //marking current vertex as visited.
		vis[u] = true;
		
		//iterating over the adjacent vertices.
		for(auto v: adj[u])
		{
		    //if any vertex is not visited, we call dfs function recursively.
			if(!vis[v])
				dfs(v, adj, vis);
		}
	}
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool>vis(V, false);
		
		//variable to store last finished vertex (or mother vertex).
		int v;
		
		//iterating over all the vertices
		for(int i = 0; i < V; i++)
		{
		    //if current vertex is not visited, we call the dfs 
		    //function and then update the variable v.
			if(!vis[i]){
				dfs(i, adj, vis);
				v = i;
			}
		}
		
		//we reset all the vertices as not visited.
		vis.assign(V, false);
		
		//calling the dfs function to do DFS beginning from v to check
        //if all vertices are reachable from it or not.
		dfs(v, adj, vis);
		
		//iterating on boolean list and returning -1 if
		//any vertex is not visited.
		for(auto i: vis)
			if(!i)
				return -1;
				
		//returning mother vertex.
		return v;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends