#include "contaBancaria.h"

ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo)
    : numero(numero), titular(titular), saldo(saldo) {}

void ContaBancaria::depositar(double valor){
    if (valor > 0) saldo += valor;
}

void ContaBancaria::sacar(double valor){
    if (valor > saldo){
        cout << "Saldo insuficiente para saque!" << endl;
    } else if (valor > 0){
        saldo -= valor;
    }
}

// transferência simples
void ContaBancaria::transferir(double valor, ContaBancaria &destino){
    if (valor > saldo){
        cout << "Saldo insuficiente para transferencia!" << endl;
    } else if (valor > 0){
        saldo -= valor;
        destino.depositar(valor);
        cout << "Transferido: R$ " << valor << " da conta "
             << numero << " para a conta " << destino.numero << endl;
    }
}

// transferência dupla (sobrecarga)
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2){
    double metade = valor / 2.0;
    if (valor > saldo) {
        cout << "Saldo insuficiente para transferencia!" << endl;
    } else if (valor > 0){
        saldo -= valor;
        destino1.depositar(metade);
        destino2.depositar(metade);
        cout << "Transferido: R$ " << metade << " para cada conta ("
             << destino1.numero << " e " << destino2.numero
             << ") da conta " << numero << endl;
    }
}

// exibir saldo
void ContaBancaria::exibirSaldo() const{
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}

// sxibir informações
void ContaBancaria::exibirInformacoes() const{
    cout << "Titular: " << titular.getNome()
         << ", CPF: " << titular.getCpf() << endl;
    cout << "Numero da Conta: " << numero
         << ", Saldo: R$ " << saldo << endl << endl;
}
