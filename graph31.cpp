// Directed Graph Cycle

#include<iostream>
using namespace std;

class Solution {
  private:
    bool dfs(int node,vector<int>&vis, vector<int>&pathvis,vector<vector<int>>&adjlist){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it:adjlist[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adjlist)==true){
                    return true;
                }
            }
            else if(pathvis[it]==1){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        
        vector<vector<int>>adjlist(V);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adjlist[u].push_back(v);
        }
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adjlist)==true){
                    return true;
                }
            }
        }
        return false;
    }
};