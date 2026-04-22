//Minimize connections


#include <iostream>
using namespace std;
class DisjointSet{
    public:
      vector<int>rank,parent,size;
      // constructor
      DisjointSet(int n){
          rank.resize(n+1,0);
          parent.resize(n+1);
          size.resize(n+1,1);
          for(int i=0;i<=n;i++){
              parent[i]=i;
          }
      }
      int findUpar(int node){
          if(node== parent[node]){
              return node;
          }
          return parent[node]=findUpar(parent[node]);
      }
      void unionbyRank(int u,int v){
          int ulp_u=findUpar(u);
          int ulp_v=findUpar(v);
          if(ulp_u==ulp_v){
              return;
          }
          if(rank[ulp_u]<rank[ulp_v]){
              parent[ulp_u]=parent[ulp_v];
          }
          else if(rank[ulp_v]<rank[ulp_u]){
              parent[ulp_v]=parent[ulp_u];
          }
          else{
              parent[ulp_v]=ulp_u;
              rank[ulp_u]++;
          }
          
      }
      void unionbySize(int u,int v){
          int x=findUpar(u);
          int y=findUpar(v);
          if(x==y) {
              return;
          }
          if(size[x]<size[y]){
              parent[x]=y;
              size[y] +=size[x];
          }else{
              parent[y]=x;
              size[x] +=size[y];
          }
      }
};
class Solution {
  public:
    int minimumConnections(int n, vector<vector<int>> &connections) {
        // code here
        DisjointSet ds(n);
        int count_extra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v)){
                count_extra++;
            }
            else{
                ds.unionbySize(u,v);
            }
        }
        int connected_comp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                connected_comp++;
            }
        }
        int ans=connected_comp-1;
        if(count_extra>=ans){
            return ans;
        }
        return -1;
        
        
        
    }
};
