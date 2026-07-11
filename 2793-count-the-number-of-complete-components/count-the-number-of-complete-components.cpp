class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    int nodes, edgeCount;

    void dfs(int u) {
        vis[u] = true;
        nodes++;
        edgeCount += adj[u].size();

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.assign(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                nodes = 0;
                edgeCount = 0;

                dfs(i);

                edgeCount /= 2;   // each edge counted twice

                if (edgeCount == (long long)nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};