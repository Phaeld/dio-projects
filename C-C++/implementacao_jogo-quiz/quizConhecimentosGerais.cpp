#include <iostream>
#include <vector>
#include <string>

// Classe Pergunta que contém o enunciado, opções e a resposta correta
class Pergunta {
public:
    std::string enunciado;  // Enunciado da pergunta
    std::vector<std::string> opcoes;  // Opções de resposta
    int respostaCorreta;  // Índice da resposta correta (baseado em 0)

    // Construtor da classe Pergunta
    Pergunta(std::string enunciado, std::vector<std::string> opcoes, int respostaCorreta)
        : enunciado(enunciado), opcoes(opcoes), respostaCorreta(respostaCorreta) {}
};

// Função para jogar o quiz
void jogar(const std::vector<Pergunta>& perguntas) {
    int pontuacao = 0;  // Variável para armazenar a pontuação

    // Itera sobre cada pergunta no vetor de perguntas
    for (const auto& pergunta : perguntas) {
        std::cout << pergunta.enunciado << std::endl;  // Exibe o enunciado da pergunta
        // Exibe as opções de resposta
        for (size_t i = 0; i < pergunta.opcoes.size(); ++i) {
            std::cout << i + 1 << ". " << pergunta.opcoes[i] << std::endl;
        }

        int resposta;  // Variável para armazenar a resposta do usuário
        std::cout << "Digite a sua resposta (1-" << pergunta.opcoes.size() << "): ";
        std::cin >> resposta;  // Lê a resposta do usuário

        // Verifica se a resposta do usuário está correta
        if (resposta - 1 == pergunta.respostaCorreta) {
            std::cout << "Correto!\n";
            pontuacao++;  // Incrementa a pontuação
        } else {
            std::cout << "Errado! Jogo reiniciado.\n";
            pontuacao = 0;  // Reseta a pontuação em caso de erro
            break;  // Interrompe o loop em caso de resposta errada
        }
    }

    // Exibe a pontuação final do usuário
    std::cout << "Sua pontuação final é: " << pontuacao << "\n";
}

// Função principal
int main() {
    // Vetor de perguntas para o quiz
    std::vector<Pergunta> perguntas = {
        Pergunta("Qual é a capital da França?", {"Berlim", "Madrid", "Paris", "Lisboa"}, 2),
        Pergunta("Qual é o maior oceano do mundo?", {"Atlântico", "Índico", "Pacífico", "Ártico"}, 2),
        Pergunta("Quem escreveu 'Dom Quixote'?", {"Miguel de Cervantes", "William Shakespeare", "Dante Alighieri", "J.K. Rowling"}, 0),
        Pergunta("Qual é o elemento químico representado pelo símbolo 'O'?", {"Ouro", "Prata", "Oxigênio", "Osmium"}, 2),
        Pergunta("Qual é o planeta mais próximo do Sol?", {"Terra", "Marte", "Mercúrio", "Vênus"}, 2),
        Pergunta("Quantos estados tem o Brasil?", {"24", "26", "27", "28"}, 1),
        Pergunta("Quem pintou a Mona Lisa?", {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet"}, 2),
        Pergunta("Qual é a moeda oficial do Japão?", {"Yuan", "Won", "Yen", "Dólar"}, 2),
        Pergunta("Qual é a montanha mais alta do mundo?", {"K2", "Everest", "Kangchenjunga", "Lhotse"}, 1),
        Pergunta("Qual é o rio mais longo do mundo?", {"Nilo", "Amazonas", "Yangtze", "Mississippi"}, 1)
    };

    char jogarNovamente;  // Variável para armazenar a decisão de jogar novamente

    // Loop para permitir que o usuário jogue novamente
    do {
        jogar(perguntas);  // Chama a função para jogar o quiz

        std::cout << "Deseja jogar novamente? (s/n): ";
        std::cin >> jogarNovamente;  // Lê a decisão do usuário
    } while (jogarNovamente == 's' || jogarNovamente == 'S');  // Repete o loop se o usuário escolher 's'

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
