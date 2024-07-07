#include <iostream>
using namespace std;

// Estrutura do nó da árvore
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Função para obter a altura do nó
int height(Node* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// Função para obter o valor máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;  // novo nó é inicialmente adicionado como folha
    return node;
}

// Rotação à direita
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Executa rotação
    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Retorna nova raiz
    return x;
}

// Rotação à esquerda
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Executa rotação
    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Retorna nova raiz
    return y;
}

// Função para obter o fator de balanceamento do nó
int getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Função para inserir um nó na árvore AVL
Node* insert(Node* node, int key) {
    // Passo 1: Realiza a inserção normal de uma árvore binária
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Chaves iguais não são permitidas na árvore AVL
        return node;

    // Passo 2: Atualiza a altura deste nó ancestral
    node->height = 1 + max(height(node->left), height(node->right));

    // Passo 3: Obtém o fator de balanceamento deste nó ancestral para verificar se ele ficou desbalanceado
    int balance = getBalance(node);

    // Se este nó ficou desbalanceado, existem 4 casos

    // Caso Esquerda-Esquerda
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso Direita-Direita
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso Esquerda-Direita
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso Direita-Esquerda
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Retorna o ponteiro do nó (inalterado)
    return node;
}

// Função para imprimir a árvore em ordem
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Função principal
int main() {
    Node* root = nullptr;

    // Inserindo valores na árvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Imprimindo a árvore em ordem
    cout << "Árvore AVL em ordem: ";
    inOrder(root);

    return 0;
}
