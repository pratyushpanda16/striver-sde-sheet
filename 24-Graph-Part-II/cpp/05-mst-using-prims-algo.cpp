#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<vector<int>>>& adj) {
        vector<bool> visited(V, false);
        // {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        int sum = 0;
        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;
            sum += weight;

            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int adjWeight = neighbor[1];
                if (!visited[adjNode]) {
                    pq.push({adjWeight, adjNode});
                }
            }
        }

        return sum;
    }
};
