class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        rank_.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;

        for (auto& r : roads) {
            unite(r[0], r[1]);
        }

        int root1 = find(1);
        int ans = INT_MAX;
        for (auto& r : roads) {
            if (find(r[0]) == root1) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
    }
};