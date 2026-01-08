// Undirected Graph Cycle

//using dfs
#include<iostream>
using namespace std;

class Solution {
  private:
    bool dfs(int node, vector<vector<int>>&adjlist,vector<int>&vis,int parent){
        vis[node]=1;
        
        for(auto it:adjlist[node]){
            if(!vis[it]){
                if(dfs(it,adjlist,vis,node)==true){
                    return true;
                }
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adjlist(V);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adjlist,vis,-1)==true){
                    return true;
                }
            }
        }
        return false;
    }
};