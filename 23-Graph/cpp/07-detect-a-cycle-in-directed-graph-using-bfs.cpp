#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isCyclic(int N, vector<vector<int>>& adj) {
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count != N;
    }
};
