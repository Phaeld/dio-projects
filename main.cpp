// main.cpp
#include "Conta.h"
#include <vector>

int main() {
    std::vector<Conta*> contas;
    contas.push_back(new ContaCorrente(500.0));
    contas.push_back(new ContaSalario(1000.0));
    contas.push_back(new ContaPoupanca(2000.0));
    contas.push_back(new ContaInvestimento(3000.0));

    double valorSaque = 2500.0;
    bool saqueRealizado = true;

    for (Conta* conta : contas) {
        if (!conta->sacar(valorSaque)) {
            saqueRealizado = false;
            std::cerr << "Saldo insuficiente na conta " << conta->getTipo() << "!\n";
        }
    }

    if (saqueRealizado) {
        std::cout << "Saque de " << valorSaque << " realizado com sucesso!\n";
    }

    // Limpeza da memória alocada
    for (Conta* conta : contas) {
        delete conta;
    }

    return 0;
}
