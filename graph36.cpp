// Shortest path in Directed Acyclic Graph
#include<iostream>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<pair<int,int>>>& adjlist,
             vector<int>& vis, stack<int>& st) {

        vis[node] = 1;

        for (auto it : adjlist[node]) {
            int v = it.first;
            if (!vis[v]) {
                dfs(v, adjlist, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adjlist(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adjlist[u].push_back({v, wt});
        }

        stack<int> st;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adjlist, vis, st);
            }
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto it : adjlist[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};
