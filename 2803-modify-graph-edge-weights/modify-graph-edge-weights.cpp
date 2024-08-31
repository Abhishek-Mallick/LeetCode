#define ll long long
class Solution {
    const int MAX_VAL = 2e9;
public:
    long long Dijkstra(vector<vector<int>>& edges, int n, int source, int destination) {
        unordered_map<ll,vector<pair<ll,ll>>> adj; // u , {v,wt}

        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }

        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;

        vector<long long> res(n, INT_MAX); // shortest dist btw source to i
        vector<bool> visited(n, false);

        res[source] = 0; // source to i(source)
        pq.push({0, source});

        while(!pq.empty()) {
            long long currDist = pq.top().first;
            long long currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true)
                continue;
            
            visited[currNode] = true;

            for(auto&[neighbour, wt] : adj[currNode]) {
                if(res[neighbour] > currDist + wt) {
                    res[neighbour] = currDist + wt;
                    pq.push({res[neighbour],neighbour});
                }
            }
        }
        return res[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = Dijkstra(edges, n, source, destination);

        if(currShortestDist < target)
            return {};

        bool targetMatch = (currShortestDist == target);

        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {
                edge[2] = (targetMatch == true) ? MAX_VAL : 1;

                if(targetMatch != true) {
                    ll newShortestDist = Dijkstra(edges, n, source, destination);

                    if(newShortestDist <= target) { // if we found the shortest path which can be made of target weight
                        targetMatch = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(targetMatch != true)
            return {};
        
        return edges;
    }
};