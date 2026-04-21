//547. Number of Provinces (leetcode)

#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjlist) {
        vis[node] = 1;
        for (auto item : adjlist[node]) {
            if (!vis[item]) {
                dfs(item, vis, adjlist);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);  // ✅ use vector of vector

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;  // ✅ define count

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, adjlist);
            }
        }

        return count;
    }
};

