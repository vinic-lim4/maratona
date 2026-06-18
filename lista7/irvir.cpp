#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<bool>& vis) {
    vis[u] = true;

    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    while (cin >> N >> M && (N || M)) {

        vector<vector<int>> g(N + 1);
        vector<vector<int>> gt(N + 1);

        for (int i = 0; i < M; i++) {
            int V, W, P;
            cin >> V >> W >> P;

            g[V].push_back(W);
            gt[W].push_back(V);

            if (P == 2) {
                g[W].push_back(V);
                gt[V].push_back(W);
            }
        }

        vector<bool> vis(N + 1, false);

        dfs(1, g, vis);

        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            fill(vis.begin(), vis.end(), false);

            dfs(1, gt, vis);

            for (int i = 1; i <= N; i++) {
                if (!vis[i]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? 1 : 0) << '\n';
    }

    return 0;
}
