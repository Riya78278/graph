// account merge


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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjointset ds(n);
        unordered_map<string,int>mapmailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end()){
                    mapmailnode[mail]=i;
                }
                else{
                    ds.unionbysize(i,mapmailnode[mail]);
                }
            }
        }
        vector<string>mergemail[n];
        for(auto it:mapmailnode){
            string mail=it.first;
            int node=ds.findupar(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergemail[i].size()==0)continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;


    }
};
