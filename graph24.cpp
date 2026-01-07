// dfs
#include<iostream>
using namespace std;
class Solution {
  private:
    void dfstraversal(int node ,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfstraversal(it,adj,vis,ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>ans;
        int start=0;
        dfstraversal(start,adj,vis,ans);
        return ans;
        
    }
};