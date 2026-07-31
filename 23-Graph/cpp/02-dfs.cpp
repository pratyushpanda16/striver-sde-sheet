#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dfsOfGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result;
        vector<bool> visited(V, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            result.push_back(node);
            for (int i = (int)adj[node].size() - 1; i >= 0; i--) {
                int next = adj[node][i];
                if (!visited[next]) {
                    visited[next] = true;
                    st.push(next);
                }
            }
        }

        return result;
    }

    vector<int> bfsOfGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result;
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        return result;
    }
};
