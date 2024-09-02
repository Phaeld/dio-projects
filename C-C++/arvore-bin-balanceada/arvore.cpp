#include <iostream>
using namespace std;

// Estrutura do nó da árvore
struct Node {
    int key;       // Valor armazenado no nó
    Node* left;    // Ponteiro para o nó filho à esquerda
    Node* right;   // Ponteiro para o nó filho à direita
    int height;    // Altura do nó na árvore
};

// Função para obter a altura do nó
int height(Node* N) {
    if (N == nullptr)
        return 0;
    return N->height;  // Retorna a altura do nó
}

// Função para obter o valor máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;  // Retorna o maior valor entre 'a' e 'b'
}

// Função para criar um novo nó
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;          // Atribui a chave ao nó
    node->left = nullptr;     // Inicializa o ponteiro da esquerda como nulo
    node->right = nullptr;    // Inicializa o ponteiro da direita como nulo
    node->height = 1;         // Novo nó é inicialmente adicionado como folha
    return node;
}

// Rotação à direita
Node* rightRotate(Node* y) {
    Node* x = y->left;        // Define 'x' como o filho à esquerda de 'y'
    Node* T2 = x->right;      // 'T2' é o filho à direita de 'x'

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
    Node* y = x->right;       // Define 'y' como o filho à direita de 'x'
    Node* T2 = y->left;       // 'T2' é o filho à esquerda de 'y'

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
    return height(N->left) - height(N->right);  // Calcula o fator de balanceamento
}

// Função para inserir um nó na árvore AVL
Node* insert(Node* node, int key) {
    // Passo 1: Realiza a inserção normal de uma árvore binária
    if (node == nullptr)
        return newNode(key);  // Cria um novo nó se a posição estiver vazia

    if (key < node->key)
        node->left = insert(node->left, key);  // Insere na subárvore esquerda
    else if (key > node->key)
        node->right = insert(node->right, key);  // Insere na subárvore direita
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
        inOrder(root->left);            // Imprime a subárvore esquerda
        cout << root->key << " ";       // Imprime a chave do nó atual
        inOrder(root->right);           // Imprime a subárvore direita
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
