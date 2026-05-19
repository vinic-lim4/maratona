#include <iostream>
#include <string>
using namespace std;

string preorder, inorder;

void postorder(string pre, string in) {
    if (pre.empty()) return;

    char root = pre[0];

    int pos = in.find(root);

    // esquerda
    string leftIn = in.substr(0, pos);
    string leftPre = pre.substr(1, leftIn.size());

    // direita
    string rightIn = in.substr(pos + 1);
    string rightPre = pre.substr(1 + leftIn.size());

    postorder(leftPre, leftIn);
    postorder(rightPre, rightIn);

    cout << root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> preorder >> inorder) {
        postorder(preorder, inorder);
        cout << '\n';
    }

    return 0;
}
