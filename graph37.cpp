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