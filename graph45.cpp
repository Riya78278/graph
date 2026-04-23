
#include<iostream>
using namespace std;

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis,
             vector<int>& tin, vector<int>& low,
             vector<int>& mark,
             vector<int> adj[]) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);

                low[node] = min(low[node], low[it]);

                // articulation condition
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }

        // root condition
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {

        vector<int> vis(V, 0), tin(V), low(V), mark(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i]) ans.push_back(i);
        }

        if (ans.empty()) return {-1};
        return ans;
    }
};
