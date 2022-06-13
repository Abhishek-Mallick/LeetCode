class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       unordered_map<int,unordered_set<int>> stops;
        
        for(int i=0;i<routes.size();i++)
            for(int el : routes[i])
                stops[el].insert(i);
        queue<pair<int,int>> next_stop;
        next_stop.push({source,0});
        unordered_set<int> visited = {source};
        
        while(!next_stop.empty())
        {
            int stop = next_stop.front().first;
            int count = next_stop.front().second;
            
            if(stop == target)
                return count;
            next_stop.pop();
            
            for(const auto& route : stops[stop])
            {
                for(const auto& next : routes[route])
                {
                    auto x = visited.insert(next);
                    if(x.second)
                        next_stop.push({next,count+1});
                }
                routes[route].clear();
            }
        }
        return -1;
    }
};