//Cheapest Flights Within K Stops

#include <iostream>
using namespace std;
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        vector<pair<int,int>>adj[n];
        for(auto e:flights){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
        }
        
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int steps=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            
            for(auto itt: adj[node]){
                int adjnode=itt.first;
                int adjwt=itt.second;
                
                if(cost+adjwt < dist[adjnode] && steps <=K){
                    dist[adjnode]=cost +adjwt;
                    q.push({steps+1,{adjnode,cost+adjwt}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
        
    }
};
