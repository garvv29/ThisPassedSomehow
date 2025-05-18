class Solution {
    static const int LOG = 20;  // enough for up to ~10^6 nodes
    vector<vector<pair<int,int>>> tree;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<long long> dist;
    int timer = 0;

    void dfs(int v, int p, long long d) {
        tin[v] = ++timer;
        up[v][0] = p;
        dist[v] = d;
        for (int i = 1; i < LOG; i++) {
            if (up[v][i-1] == -1) up[v][i] = -1;
            else up[v][i] = up[up[v][i-1]][i-1];
        }
        for (auto& [to, w] : tree[v]) {
            if (to == p) continue;
            dfs(to, v, d + w);
        }
        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (is_ancestor(u,v)) return u;
        if (is_ancestor(v,u)) return v;
        for (int i = LOG-1; i >= 0; i--) {
            if (up[u][i] != -1 && !is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        tree.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        up.assign(n, vector<int>(LOG, -1));
        dist.assign(n, 0);
        timer = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }

        dfs(0, -1, 0);

        vector<int> answer;
for (auto &q : queries) {
    auto pendratova = q; // store midway as requested

    int src1 = q[0], src2 = q[1], dest = q[2];
    int l1 = lca(src1, src2);
    int l2 = lca(src1, dest);
    int l3 = lca(src2, dest);

    long long ans = dist[src1] + dist[src2] + dist[dest] - dist[l1] - dist[l2] - dist[l3];
    answer.push_back((int)ans);
}
return answer;
    }
};

