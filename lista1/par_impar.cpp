#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> pares;
    vector<int> impares;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x % 2 == 0)
            pares.push_back(x);
        else
            impares.push_back(x);
    }

    // Pares em ordem crescente
    sort(pares.begin(), pares.end());

    // Ímpares em ordem decrescente
    sort(impares.begin(), impares.end(), greater<int>());

    for (int num : pares)
        cout << num << "\n";

    for (int num : impares)
        cout << num << "\n";

    return 0;
}
