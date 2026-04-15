// Shortest Distance in a Binary Maze

#include<iostream>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();

        // If source or destination is blocked
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        // If source equals destination and it's open, distance is 0
        if (source == destination) return 0;

        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;

        // Queue stores {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int distance = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == 1 && distance + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = distance + 1;

                    if (nrow == destination.first && ncol == destination.second)
                        return distance + 1;

                    q.push({distance + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};
