#include <iostream>
#include <string>

using namespace std;

// Definição da classe Robo
class Robo {
private:
    string nome;
    string modelo;
    int anoFabricacao;

public:
    // Construtor para inicializar os atributos
    Robo(string _nome, string _modelo, int _ano) : nome(_nome), modelo(_modelo), anoFabricacao(_ano) {}

    // Método para exibir as informações do robô
    void exibirInformacoes() {
        cout << "O robô " << nome << ", modelo " << modelo << ", foi fabricado em " << anoFabricacao << "." << endl;
    }
};

int main() {
    string nome, modelo;
    int ano;

    // Entrada dos dados do robô
    //cout << "Digite o nome do robô: ";
    getline(cin, nome);

    //cout << "Digite o modelo do robô: ";
    getline(cin, modelo);

    //cout << "Digite o ano de fabricação do robô: ";
    cin >> ano;

    // Criação do objeto Robo com os dados fornecidos
    Robo robo(nome, modelo, ano);

    // Exibe as informações do robô usando o método da classe
    robo.exibirInformacoes();

    return 0;
}
