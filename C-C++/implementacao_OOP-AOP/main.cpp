// main.cpp
#include "Conta.h"  // Inclui o cabeçalho "Conta.h" que contém as definições das classes de conta
#include <vector>  // Inclui a biblioteca vector para utilizar a estrutura de dados std::vector

int main() {
    // Cria um vetor de ponteiros para Conta
    std::vector<Conta*> contas;
    
    // Adiciona diferentes tipos de contas ao vetor
    contas.push_back(new ContaCorrente(500.0));  // Adiciona uma conta corrente com saldo inicial de 500.0
    contas.push_back(new ContaSalario(1000.0));  // Adiciona uma conta salário com saldo inicial de 1000.0
    contas.push_back(new ContaPoupanca(2000.0));  // Adiciona uma conta poupança com saldo inicial de 2000.0
    contas.push_back(new ContaInvestimento(3000.0));  // Adiciona uma conta investimento com saldo inicial de 3000.0

    double valorSaque = 2500.0;  // Define o valor do saque
    bool saqueRealizado = true;  // Variável para verificar se todos os saques foram realizados com sucesso

    // Itera sobre cada conta no vetor e tenta realizar o saque
    for (Conta* conta : contas) {
        // Se o saque não puder ser realizado devido a saldo insuficiente
        if (!conta->sacar(valorSaque)) {
            saqueRealizado = false;  // Define saqueRealizado como false
            // Exibe mensagem de erro com o tipo da conta
            std::cerr << "Saldo insuficiente na conta " << conta->getTipo() << "!\n";
        }
    }

    // Se todos os saques foram realizados com sucesso
    if (saqueRealizado) {
        std::cout << "Saque de " << valorSaque << " realizado com sucesso!\n";  // Exibe mensagem de sucesso
    }

    // Limpeza da memória alocada para evitar vazamentos de memória
    for (Conta* conta : contas) {
        delete conta;  // Deleta cada objeto Conta criado dinamicamente
    }

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
