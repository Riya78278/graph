// Undirected Graph Cycle
// using bfs
#include<iostream>
using namespace std;


class Solution {
    //using bfs
  private:
    bool isdetect(int node,  vector<vector<int>>&adjlist,vector<int>&vis){
        vis[node]=1;
        queue<pair<int,int>>q;
        q.push({node,-1});
        while(!q.empty()){
            int nodde=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adjlist[nodde]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,nodde});
                }
                else if(parent != it){
                    return true;
                }
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
                if(isdetect(i,adjlist,vis)==true){
                    return true;
                }
            }
        }
        return false;
        
    }
};