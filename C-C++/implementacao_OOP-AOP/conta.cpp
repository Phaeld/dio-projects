// Conta.h
#ifndef CONTA_H  // Verifica se CONTA_H não foi definido anteriormente
#define CONTA_H  // Define CONTA_H para evitar múltiplas inclusões

#include <string>  // Inclui a biblioteca string para manipulação de strings
#include <iostream>  // Inclui a biblioteca iostream para operações de entrada e saída

// Classe base Conta
class Conta {
protected:
    std::string tipo;  // Tipo da conta (Corrente, Salário, Poupança, Investimento)
    double saldo;  // Saldo da conta

public:
    // Construtor da classe Conta que inicializa o tipo e o saldo
    Conta(std::string tipo, double saldoInicial) : tipo(tipo), saldo(saldoInicial) {}
    // Destrutor virtual da classe Conta
    virtual ~Conta() {}

    // Função virtual para sacar um valor da conta
    virtual bool sacar(double valor) {
        if (valor > saldo) {
            return false;  // Retorna false se o valor do saque for maior que o saldo
        }
        saldo -= valor;  // Subtrai o valor do saque do saldo
        return true;  // Retorna true se o saque for bem-sucedido
    }

    // Função para depositar um valor na conta
    void depositar(double valor) {
        saldo += valor;  // Adiciona o valor do depósito ao saldo
    }

    // Função para obter o saldo da conta
    double getSaldo() const {
        return saldo;  // Retorna o saldo atual da conta
    }

    // Função para obter o tipo da conta
    std::string getTipo() const {
        return tipo;  // Retorna o tipo da conta
    }
};

// Classe ContaCorrente que herda de Conta
class ContaCorrente : public Conta {
public:
    // Construtor da classe ContaCorrente que inicializa o saldo e define o tipo como "Corrente"
    ContaCorrente(double saldoInicial) : Conta("Corrente", saldoInicial) {}
};

// Classe ContaSalario que herda de Conta
class ContaSalario : public Conta {
public:
    // Construtor da classe ContaSalario que inicializa o saldo e define o tipo como "Salário"
    ContaSalario(double saldoInicial) : Conta("Salário", saldoInicial) {}
};

// Classe ContaPoupanca que herda de Conta
class ContaPoupanca : public Conta {
public:
    // Construtor da classe ContaPoupanca que inicializa o saldo e define o tipo como "Poupança"
    ContaPoupanca(double saldoInicial) : Conta("Poupança", saldoInicial) {}
};

// Classe ContaInvestimento que herda de Conta
class ContaInvestimento : public Conta {
public:
    // Construtor da classe ContaInvestimento que inicializa o saldo e define o tipo como "Investimento"
    ContaInvestimento(double saldoInicial) : Conta("Investimento", saldoInicial) {}
};

#endif // CONTA_H  // Finaliza a verificação de múltipla inclusão
