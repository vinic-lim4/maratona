#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    while (cin >> N && N != 0) {
        int P;
        cin >> P;

        vector<int> dp(P + 1, 0);

        for (int i = 0; i < N; i++) {
            int tempo, pizzas;
            cin >> tempo >> pizzas;

            for (int j = P; j >= pizzas; j--) {
                dp[j] = max(dp[j], dp[j - pizzas] + tempo);
            }
        }

        cout << dp[P] << " min." << endl;
    }

    return 0;
}
