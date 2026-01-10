// Course Schedule II
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adjlist(n);
        for(auto e:prerequisites){
            int u=e[0];
            int v=e[1];
            adjlist[v].push_back(u);
        }

        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it :adjlist[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
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
        if(ans.size()==n){
            return ans;
        }
        return {};
        
    }
};