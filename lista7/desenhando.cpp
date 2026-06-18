#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N; // vértice inicial (não é necessário usar)
        cin >> N;

        int V, A;
        cin >> V >> A;

        set<pair<int, int>> edges;

        for (int i = 0; i < A; i++) {
            int u, v;
            cin >> u >> v;

            if (u > v) swap(u, v); // trata arestas não direcionadas
            edges.insert({u, v});
        }

        cout << 2 * (int)edges.size() << "\n";
    }

    return 0;
}
