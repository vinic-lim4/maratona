#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void preorder(Node* root, vector<int>& v) {
    if (root == nullptr) return;

    v.push_back(root->value);
    preorder(root->left, v);
    preorder(root->right, v);
}

void inorder(Node* root, vector<int>& v) {
    if (root == nullptr) return;

    inorder(root->left, v);
    v.push_back(root->value);
    inorder(root->right, v);
}

void postorder(Node* root, vector<int>& v) {
    if (root == nullptr) return;

    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->value);
}

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;

    for (int caso = 1; caso <= C; caso++) {
        int N;
        cin >> N;

        Node* root = nullptr;

        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            root = insert(root, x);
        }

        vector<int> pre, in, post;

        preorder(root, pre);
        inorder(root, in);
        postorder(root, post);

        cout << "Case " << caso << ":\n";

        cout << "Pre.: ";
        printVector(pre);

        cout << "In..: ";
        printVector(in);

        cout << "Post: ";
        printVector(post);

        cout << "\n";
    }

    return 0;
}
