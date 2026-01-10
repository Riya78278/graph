// kahn's algorithm
#include<iostream>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegree(V);
        vector<vector<int>>adjlist(V);
        
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adjlist[u].push_back(v);
            
        }
        
        for(int i=0;i<V;i++){
            for(auto it:adjlist[i]){
                indegree[it]++;
                
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adjlist[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        return ans;
        
    }
};