#include<iostream>
#include<set>
using namespace std;

class Disjointset{
    
    public:
    vector<int>rank,size,parent;
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
private:
    bool isvalid(int newr,int newc,int n){
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjointset ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    if(isvalid(newr,newc,n)&& grid[newr][newc]==1){
                        int nodeno=row*n+col;
                        int adjnode= newr* n+newc;
                        ds.unionbysize(nodeno,adjnode);
                    }
                }
            }
        }
        //step 2 for zeroes;
        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                set<int>component;
                if(grid[row][col]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    if(isvalid(newr,newc,n)){
                        if(grid[newr][newc]==1){
                            int nodeno=row*n+col;
                            int adjnode= newr* n+newc;
                            component.insert(ds.findupar(adjnode));

                        }
                    }
                }
                int sizetotal=0;
                for(auto it:component){
                    sizetotal +=ds.size[it];
                }
                maxi=max(maxi,sizetotal+1);

            }
        }
        //what if there is no zero
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findupar(i)]);
        }
        return maxi;

    }
};