#include <iostream>
using namespace std;

int main() {
    int N;

    while (cin >> N) { 
        int custo;
        cin >> custo;

        int max_lucro = 0;
        int atual = 0;

        for (int i = 0; i < N; i++) {
            int receita;
            cin >> receita;

            int lucro_dia = receita - custo;

            atual = max(0, atual + lucro_dia);
            max_lucro = max(max_lucro, atual);
        }

        cout << max_lucro << endl;
    }

    return 0;
}
