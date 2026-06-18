#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> consultas(N);

    for (int i = 0; i < N; i++) {
        cin >> consultas[i].first >> consultas[i].second;
    }

    sort(consultas.begin(), consultas.end(),
         [](const auto& a, const auto& b) {
             return a.second < b.second;
         });

    int resposta = 0;
    int fimAtual = 0;

    for (auto [inicio, fim] : consultas) {
        if (inicio >= fimAtual) {
            resposta++;
            fimAtual = fim;
        }
    }

    cout << resposta << '\n';

    return 0;
}
