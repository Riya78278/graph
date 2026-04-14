#include<iostream>
using namespace std;

class Disjointset{
    vector<int>rank,size,parent;
    public:
    Disjointset(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findupar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int up_u=findupar(u);
        int up_v=findupar(v);
        if(up_u==up_v){
            return ;
        }
        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }
        else if(rank[up_v]<rank[up_u]){
            parent[up_v]=up_u;
        }
        else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }
    void unionbysize(int u,int v){
        int up_u=findupar(u);
        int up_v=findupar(v);
        if(up_u==up_v){
            return ;
        }
        if(size[up_u]<size[up_v]){
            size[up_v] += size[up_u];
            parent[up_u]=up_v;
        }
        else{
            size[up_u] +=size[up_v];
            parent[up_v]=up_u;
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        Disjointset ds(maxrow+maxcol+1);
        unordered_map<int,int>stonenode;
        int count=0;
        for(auto it:stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionbysize(noderow,nodecol);
            stonenode[noderow]=1;
            stonenode[nodecol]=1;
        }
        for(auto it:stonenode){
            if(ds.findupar(it.first)==it.first){
                count++;
            }
        }
        return n-count;
    }
};