// Account Merge


#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionbyRank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbySize(int u, int v) {
        int x = findUpar(u);
        int y = findUpar(v);
        if (x == y)
            return;
        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        // Step 1: Union emails of the same user
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) { // ✅ fixed
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionbySize(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Group mails by parent node
        vector<vector<string>> mergemail(n); // ✅ fixed
        for (auto &it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergemail[node].push_back(mail);
        }

        // Step 3: Prepare final output
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergemail[i].empty()) continue;
            sort(mergemail[i].begin(), mergemail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // username
            for (auto &mail : mergemail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

