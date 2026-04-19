

#include <iostream>
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
  private:
    bool isvalid(int adjr,int adjc,int n,int m){
        return adjr>=0 && adjr<n && adjc>=0 && adjc<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        Disjointset ds(n*m);
        vector<int>ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //memset(vis,0,sizeof(vis));
        int count=0;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            
            if(vis[row][col]==1){
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjr=row+dr[i];
                int adjc=col+dc[i];
                if(isvalid(adjr,adjc,n,m)){
                    if(vis[adjr][adjc]==1){
                        int nodeno=row*m+col;
                        int adjnode=adjr*m+adjc;
                        if(ds.findupar(nodeno) != ds.findupar(adjnode)){
                            count--;
                            ds.unionbysize(nodeno,adjnode);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
        
        
    }
};
