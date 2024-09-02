#include <iostream>
#include <string>
using namespace std;

// Definindo a classe Pessoa
class Pessoa {
private:
    string nome;
    int idade;

public:
    // Método para definir o nome
    void setNome(string n) {
        nome = n;
    }

    // Método para definir a idade
    void setIdade(int i) {
        idade = i;
    }

    // Método para obter o nome
    string getNome() {
        return nome;
    }

    // Método para obter a idade
    int getIdade() {
        return idade;
    }
};

int main() {
    // Criando um objeto do tipo Pessoa
    Pessoa pessoa;

    // Variáveis para armazenar entrada do usuário
    string nome;
    int idade;

    // Solicitando o nome da pessoa
    //cout << "Insira o nome da pessoa: ";
    getline(cin, nome);  // Usando getline para permitir espaços no nome

    // Solicitando a idade da pessoa
    //cout << "Insira a idade da pessoa: ";
    cin >> idade;

    // Definindo os atributos do objeto pessoa
    pessoa.setNome(nome);
    pessoa.setIdade(idade);

    // Exibindo o nome e a idade da pessoa
    cout << "Nome: " << pessoa.getNome() << ", Idade: " << pessoa.getIdade() << endl;

    return 0;
}
