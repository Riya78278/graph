// City With the Smallest Number of Neighbors at a Threshold Distance

#include <iostream>
using namespace std;
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto it: edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        int citycount=n;
        int cityno=-1;
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
                
            }
            if(count <= citycount){
                citycount=count;
                cityno=i;
            }
        }
        return cityno;
    }
};
