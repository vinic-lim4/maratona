#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    int instancia = 1;

    while (cin >> N >> T) {
        if (N == 0 && T == 0)
            break;

        vector<int> dp(T + 1, 0);

        for (int i = 0; i < N; i++) {
            int D, P;
            cin >> D >> P;

            for (int j = D; j <= T; j++) {
                dp[j] = max(dp[j], dp[j - D] + P);
            }
        }

        cout << "Instancia " << instancia << endl;
        cout << dp[T] << endl << endl;

        instancia++;
    }

    return 0;
}
