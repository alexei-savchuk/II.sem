#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
        return root;
    }
    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    return root;
}

// Function to count the number of nodes with even keys
int countNodesWithEvenKeys(Node* root) {
    if (root == NULL)
        return 0;

    int count = countNodesWithEvenKeys(root->left) + countNodesWithEvenKeys(root->right);

    if (root->key % 2 == 0)
        count++;

    return count;
}

// Function to display the binary tree (inorder traversal)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Function to display the binary tree (preorder traversal)
void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to display the binary tree (postorder traversal)
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* root = NULL;
    int choice, key;

    do {
        cout << "1. Вставить узел\n";
        cout << "2. Подсчет узлов с четными ключами\n";
        cout << "3. Отображение дерева (по порядку)\n";
        cout << "4. Показать дерево (предварительный заказ)\n";
        cout << "5. Отображение дерева (постпорядок)\n";
        cout << "6. Выход\n";
        cout << "Введите свой выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите клавишу для вставки: ";
            cin >> key;
            root = insertNode(root, key);
            break;
        case 2:
            cout << "Количество узлов с четными ключами: " << countNodesWithEvenKeys(root) << endl;
            break;
        case 3:
            cout << "Порядковый обход: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Обход предварительного порядка: ";
            preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Обход последовательностей: ";
            postorder(root);
            cout << endl;
                break;
        case 6:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор\n";
        }
    } while (choice != 6);



    return 0;
}
