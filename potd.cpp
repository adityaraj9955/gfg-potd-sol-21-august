#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> dist(N, -1); // Initialize distances with -1
        vector<vector<int>> adj(N); // Adjacency list

        // Build the graph
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS initialization
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        // BFS loop
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { // If the neighbor hasn't been visited
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
    }
};
