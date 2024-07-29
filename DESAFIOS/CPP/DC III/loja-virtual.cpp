#include <iostream>
#include <string>

using namespace std;

// Classe base Produto
class Produto {
protected:
    string nome;

public:
    Produto(string _nome) : nome(_nome) {}

    // Método virtual puro
    virtual string informacoes() = 0;
};

// Classe Eletronico, derivada de Produto
class Eletronico : public Produto {
private:
    int garantia;

public:
    Eletronico(string _nome, int _garantia) : Produto(_nome), garantia(_garantia) {}

    // Implementação do método informacoes()
    string informacoes() override {
        return nome + ", garantia: " + to_string(garantia) + " meses";
    }
};

// Classe Vestuario, derivada de Produto
class Vestuario : public Produto {
private:
    string tamanho;

public:
    Vestuario(string _nome, string _tamanho) : Produto(_nome), tamanho(_tamanho) {}

    // Implementação do método informacoes()
    string informacoes() override {
        return nome + ", tamanho: " + tamanho;
    }
};

int main() {
    string nome;
    char tipo;
    string detalhe;

    // Leitura da entrada
    getline(cin, nome);
    cin >> tipo >> detalhe;

    // Verifica o tipo de produto e cria o objeto adequado
    Produto *produto;
    if (tipo == 'E') {
        int garantia = stoi(detalhe);
        produto = new Eletronico(nome, garantia);
    } else if (tipo == 'V') {
        string tamanho = detalhe;
        produto = new Vestuario(nome, tamanho);
    } else {
        cerr << "Tipo de produto inválido." << endl;
        return 1;
    }

    // Imprime as informações do produto
    cout << produto->informacoes() << endl;

    // Libera a memória alocada dinamicamente
    delete produto;

    return 0;
}
