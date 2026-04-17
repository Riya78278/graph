#include<iostream>
using namespace std;

class Solution {
  private:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
  private:
    void dfs3(int node,vector<vector<int>>&adjt,vector<int>&vis){
        vis[node]=1;
        for(auto it: adjt[node]){
            if(!vis[it]){
                dfs3(it,adjt,vis);
            }
        }
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        stack<int>st;
        vector<int>vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        //reverse
        vector<vector<int>>adjt(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjt[it].push_back(i);
            }
        }
        
        int count =0;
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            if(!vis[node]){
                count++;
                dfs3(node,adjt,vis);
            }
        }
        return count;
    }
};