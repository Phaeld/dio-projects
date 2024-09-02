#include <iostream>
#include <string>

using namespace std;

// Definição dos enums para Valor e Naipe
enum Valor {
    As = 1, Valete, Dama, Rei
};

enum Naipe {
    Paus = 0, Ouros, Copas, Espadas
};

// Classe Carta com atributos Valor e Naipe
class Carta {
private:
    Valor valor;
    Naipe naipe;

public:
    // Construtor para inicializar a carta com valor e naipe
    Carta(Valor _valor, Naipe _naipe) : valor(_valor), naipe(_naipe) {}

    // Método para obter a representação da carta como string
    string obterNomeCarta() {
        string nomeValor, nomeNaipe;

        // Switch case para atribuir o nome do valor da carta
        switch (valor) {
            case As:
                nomeValor = "Ás";
                break;
            case Valete:
                nomeValor = "Valete";
                break;
            case Dama:
                nomeValor = "Dama";
                break;
            case Rei:
                nomeValor = "Rei";
                break;
            default:
                nomeValor = "Valor inválido";
                break;
        }

        // Switch case para atribuir o nome do naipe da carta
        switch (naipe) {
            case Paus:
                nomeNaipe = "Paus";
                break;
            case Ouros:
                nomeNaipe = "Ouros";
                break;
            case Copas:
                nomeNaipe = "Copas";
                break;
            case Espadas:
                nomeNaipe = "Espadas";
                break;
            default:
                nomeNaipe = "Naipe inválido";
                break;
        }

        return nomeValor + " de " + nomeNaipe;
    }
};

int main() {
    int valorEscolhido, naipeEscolhido;

    // Entrada do usuário para o valor e naipe da carta
    //cout << "Escolha o valor da carta (1 - Ás, 2 - Valete, 3 - Dama, 4 - Rei): ";
    cin >> valorEscolhido;

    //cout << "Escolha o naipe da carta (0 - Paus, 1 - Ouros, 2 - Copas, 3 - Espadas): ";
    cin >> naipeEscolhido;

    // Verificações para garantir que o valor e o naipe escolhidos sejam válidos
    Valor valorCarta;
    switch (valorEscolhido) {
        case 1:
            valorCarta = As;
            break;
        case 2:
            valorCarta = Valete;
            break;
        case 3:
            valorCarta = Dama;
            break;
        case 4:
            valorCarta = Rei;
            break;
        default:
            cerr << "Valor inválido escolhido." << endl;
            return 1;
    }

    Naipe naipeCarta;
    switch (naipeEscolhido) {
        case 0:
            naipeCarta = Paus;
            break;
        case 1:
            naipeCarta = Ouros;
            break;
        case 2:
            naipeCarta = Copas;
            break;
        case 3:
            naipeCarta = Espadas;
            break;
        default:
            cerr << "Naipe inválido escolhido." << endl;
            return 1;
    }

    // Criando a carta com os valores escolhidos
    Carta cartaEscolhida(valorCarta, naipeCarta);

    // Exibindo a carta escolhida
    cout << "Carta escolhida: " << cartaEscolhida.obterNomeCarta() << endl;

    return 0;
}
