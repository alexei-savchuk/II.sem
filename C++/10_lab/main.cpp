#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

// ��������� ��� ����� ������
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

// ������� ��� ������� ������ �������� � ������
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
    return root;
}

// ������� ��� �������� ���������� ����� � ������� �������
int countEvenNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if (root->key % 2 == 0) {
        count++;
    }
    count += countEvenNodes(root->left);
    count += countEvenNodes(root->right);
    return count;
}

// ������� ��� ������ ������ �� �����
void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->key << " ";
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        cout << endl;
    }
}

// ������� ��� ������ ���� ������ ��������
void printMenu() {
    cout << "1. Add node" << endl;
    cout << "2. Count even nodes" << endl;
    cout << "3. Print tree" << endl;
    cout << "4. Exit" << endl;
}

// �������� ������� ��� �������� ������ ���������
int main() {
    Node* root = new Node(10);
    while (true) {
        printMenu();
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int key;
            cout << "Enter key: ";
            cin >> key;
            insert(root, key);
            break;
        }
        case 2: {
            int count = countEvenNodes(root);
            cout << "Number of even nodes: " << count << endl;
            break;
        }
        case 3: {
            cout << "***********************************" << endl;
            cout << " " << endl;
            printTree(root);
            cout << " " << endl;
            cout << "***********************************" << endl;
            break;
        }
        case 4: {
            exit(0);
        }
        default: {
            cout << "Invalid choice!" << endl;
            break;
        }
        }
    }
    return 0;
}
