#include<iostream>
using namespace std;
class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis,
             vector<vector<int>>& bridges,
             int tin[], int low[],
             vector<vector<int>>& adj) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, vis, bridges, tin, low, adj);

                low[node] = min(low[node], low[it]);

                // ✅ correct condition
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }
            else {
                // ✅ correct back-edge handling
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {

        vector<vector<int>> adj(V);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(V, 0);
        int tin[V], low[V];
        vector<vector<int>> bridges;

        // ✅ handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, bridges, tin, low, adj);
            }
        }

        // ✅ check if (c, d) is a bridge
        for (auto &b : bridges) {
            if ((b[0] == c && b[1] == d) ||
                (b[0] == d && b[1] == c)) {
                return true;
            }
        }

        return false;
    }
};