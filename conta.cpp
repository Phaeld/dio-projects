// Conta.h
#ifndef CONTA_H
#define CONTA_H

#include <string>
#include <iostream>

class Conta {
protected:
    std::string tipo;
    double saldo;

public:
    Conta(std::string tipo, double saldoInicial) : tipo(tipo), saldo(saldoInicial) {}
    virtual ~Conta() {}

    virtual bool sacar(double valor) {
        if (valor > saldo) {
            return false;
        }
        saldo -= valor;
        return true;
    }

    void depositar(double valor) {
        saldo += valor;
    }

    double getSaldo() const {
        return saldo;
    }

    std::string getTipo() const {
        return tipo;
    }
};

class ContaCorrente : public Conta {
public:
    ContaCorrente(double saldoInicial) : Conta("Corrente", saldoInicial) {}
};

class ContaSalario : public Conta {
public:
    ContaSalario(double saldoInicial) : Conta("Salário", saldoInicial) {}
};

class ContaPoupanca : public Conta {
public:
    ContaPoupanca(double saldoInicial) : Conta("Poupança", saldoInicial) {}
};

class ContaInvestimento : public Conta {
public:
    ContaInvestimento(double saldoInicial) : Conta("Investimento", saldoInicial) {}
};

#endif // CONTA_H
