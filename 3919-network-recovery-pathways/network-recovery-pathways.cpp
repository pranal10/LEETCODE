class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> adj; // adj[u] = {v, cost}
    vector<bool> online;
    long long  k;

    // Returns true if there's a path 0 -> n-1 with total cost <= k,
    // using only edges with cost >= minEdge, and online intermediate nodes.
    bool feasible(int minEdge) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            if (u == n - 1) return d <= k; // reached target
            for (auto [v, cost] : adj[u]) {
                if (cost < minEdge) continue;              // skip edges below threshold
                if (v != n - 1 && !online[v]) continue;    // intermediate node must be online
                if (d + cost < dist[v]) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] != LLONG_MAX && dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& onlineArr, long long  kk) {
        n = onlineArr.size();
        online = onlineArr;
        k = kk;
        adj.assign(n, {});
        int lo = INT_MAX, hi = 0;
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            lo = min(lo, e[2]);
            hi = max(hi, e[2]);
        }

        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) {
                ans = mid;      // this score works, try for a bigger one
                lo = mid + 1;
            } else {
                hi = mid - 1;   // too strict, relax the threshold
            }
        }
        return ans;
    }
};