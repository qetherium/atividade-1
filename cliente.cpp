#include "cliente.h"

// construtor
Cliente::Cliente(string nome, string cpf){
    this->nome = nome;
    this->cpf = cpf;
}

// getters
string Cliente::getNome() const{
    return nome;
}

string Cliente::getCpf() const{
    return cpf;
}
