//733. Flood Fill (leetcode)

#include <iostream>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& image,int inicolor,vector<vector<int>>&ans,int delrow[],int delcol[],int sr,int sc, int newcolor){
        ans[sr][sc]=newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc +delcol[i];
            if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!= newcolor){
                ans[nrow][ncol]=newcolor;
                dfs(image,inicolor,ans,delrow,delcol,nrow,ncol,newcolor);
            }
        }
    }    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(image,inicolor,ans,delrow,delcol,sr,sc,color);
        return ans;
        
    }
};
