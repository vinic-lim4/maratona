#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    cout << N << '\n';

    int notas[] = {100, 50, 20, 10, 5, 2, 1};

    for (int nota : notas) {
        int qtd = N / nota;
        cout << qtd << " nota(s) de R$ " << nota << ",00\n";
        N %= nota;
    }

    return 0;
}
