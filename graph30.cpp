//  Is Graph Bipartite?
#include<iostream>
using namespace std;

class Solution {
private:
    bool dfs(int node,int val ,vector<int>&color,vector<vector<int>>&graph){
        color[node]=val;
        for(auto it: graph[node]){
            if(color[it]==-1){
                if(dfs(it,!val,color,graph)==false){
                    return false;
                }
            }
            else if(color[it]== val){
                return false;
            }
        }
        return true;

    }    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};