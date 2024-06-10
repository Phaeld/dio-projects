#include <iostream>
#include <vector>
#include <string>

class Pergunta {
public:
    std::string enunciado;
    std::vector<std::string> opcoes;
    int respostaCorreta;

    Pergunta(std::string enunciado, std::vector<std::string> opcoes, int respostaCorreta)
        : enunciado(enunciado), opcoes(opcoes), respostaCorreta(respostaCorreta) {}
};

void jogar(const std::vector<Pergunta>& perguntas) {
    int pontuacao = 0;

    for (const auto& pergunta : perguntas) {
        std::cout << pergunta.enunciado << std::endl;
        for (size_t i = 0; i < pergunta.opcoes.size(); ++i) {
            std::cout << i + 1 << ". " << pergunta.opcoes[i] << std::endl;
        }

        int resposta;
        std::cout << "Digite a sua resposta (1-" << pergunta.opcoes.size() << "): ";
        std::cin >> resposta;

        if (resposta - 1 == pergunta.respostaCorreta) {
            std::cout << "Correto!\n";
            pontuacao++;
        } else {
            std::cout << "Errado! Jogo reiniciado.\n";
            pontuacao = 0;
            break;
        }
    }

    std::cout << "Sua pontuação final é: " << pontuacao << "\n";
}

int main() {
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

    char jogarNovamente;

    do {
        jogar(perguntas);

        std::cout << "Deseja jogar novamente? (s/n): ";
        std::cin >> jogarNovamente;
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    return 0;
}
