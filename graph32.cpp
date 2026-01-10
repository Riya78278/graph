// Topological Sort

#include<iostream>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adjlist, stack<int>&st){
        vis[node]=1;
        for(auto it : adjlist[node]){
            if(!vis[it]){
                dfs(it,vis,adjlist,st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adjlist(V);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            
            adjlist[u].push_back(v);
        }
        
        stack<int>st;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adjlist,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};