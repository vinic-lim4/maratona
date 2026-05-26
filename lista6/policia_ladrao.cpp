#include <iostream>
#include <queue>

using namespace std;

int matriz[5][5];
bool visitado[5][5];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool bfs() {
    // Se início ou fim estiver bloqueado
    if (matriz[0][0] == 1 || matriz[4][4] == 1)
        return false;

    queue<pair<int, int>> fila;

    fila.push({0, 0});
    visitado[0][0] = true;

    while (!fila.empty()) {
        auto atual = fila.front();
        fila.pop();

        int x = atual.first;
        int y = atual.second;

        // Chegou no destino
        if (x == 4 && y == 4)
            return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Verifica limites
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {

                // Só anda em 0 e não visitado
                if (!visitado[nx][ny] && matriz[nx][ny] == 0) {
                    visitado[nx][ny] = true;
                    fila.push({nx, ny});
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {

        // Leitura da matriz
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> matriz[i][j];
                visitado[i][j] = false;
            }
        }

        if (bfs())
            cout << "COPS\n";
        else
            cout << "ROBBERS\n";
    }

    return 0;
}
