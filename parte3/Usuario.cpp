#include<iostream>
#include"Usuario.h"
#include"Arquivo.h"
#include<string>

using namespace std;

Usuario::Usuario(int numero, string nome_usuario, int prior): arquivos(){
    this->numero = numero;
    this->nome = nome_usuario;
    this->prioridade = prior;
}

Usuario::~Usuario(){}

void Usuario::setArquivos(Arquivo arq[]){
    for(int i=0; i<5; i++)
    {
        this->arquivos[i] = arq[i];
    }
}

Arquivo* Usuario::getArquivos(){
    return this->arquivos;
}

int Usuario::getNumero(){
    return this->numero;
}

int Usuario::getPrioridade(){
    return this->prioridade;
}

string Usuario::getNome(){
    return this->nome;
}

