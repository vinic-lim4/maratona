#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    cin.ignore();

    while (N--) {
        string linha;
        getline(cin, linha);

        stringstream ss(linha);
        set<string> itens;

        string palavra;

        // Insere automaticamente sem repetição e ordenado
        while (ss >> palavra) {
            itens.insert(palavra);
        }

        bool primeiro = true;

        for (const string& item : itens) {
            if (!primeiro)
                cout << " ";

            cout << item;
            primeiro = false;
        }

        cout << "\n";
    }

    return 0;
}
