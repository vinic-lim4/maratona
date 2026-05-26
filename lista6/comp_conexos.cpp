#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;

void dfs(int u, vector<char>& componente) {
    visitado[u] = true;
    componente.push_back('a' + u);

    for (int v : grafo[u]) {
        if (!visitado[v]) {
            dfs(v, componente);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int caso = 1; caso <= N; caso++) {
        int V, E;
        cin >> V >> E;

        grafo.assign(V, vector<int>());
        visitado.assign(V, false);

        for (int i = 0; i < E; i++) {
            char a, b;
            cin >> a >> b;

            int u = a - 'a';
            int v = b - 'a';

            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        // Ordena adjacências
        for (int i = 0; i < V; i++) {
            sort(grafo[i].begin(), grafo[i].end());
        }

        int componentes = 0;

        cout << "Case #" << caso << ":\n";

        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                vector<char> componente;

                dfs(i, componente);

                sort(componente.begin(), componente.end());

                for (char c : componente) {
                    cout << c << ",";
                }

                cout << "\n";
                componentes++;
            }
        }

        cout << componentes << " connected components\n\n";
    }

    return 0;
}
