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

void Usuario::SetArquivos(Arquivo *arq){`
    this->arquivos = arq;
}

Arquivo* Usuario::GetArquivos(){
    return this->arquivos;
}