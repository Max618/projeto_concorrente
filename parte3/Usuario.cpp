#include<iostream>
#include"Usuario.h"
#include"Arquivo.h"
#include<string>
#include<thread>

using namespace std;

Usuario::Usuario(int numero, string nome_usuario, int prior, Arquivo *arq): arquivos(){
    this->numero = numero;
    this->nome = nome_usuario;
    this->prioridade = prior;
    this->setArquivos(arq,prior);
}

Usuario::~Usuario(){
    delete [] this->arquivos;
}

void Usuario::setArquivos(Arquivo *arq, int p){
    this->arquivos = new Arquivo[5];
    for(int i=0; i<5; i++)
    {
        this->arquivos[i] = arq[i];
        this->arquivos[i].setPrioridade(p);
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

thread Usuario::thread_init(Fila<Arquivo>* fila){
    return thread( [=] { inserirNaFila(fila); } );
}


void Usuario::imprimirArquivo(Arquivo& arq){
    cout << "-------IMPRIMINDO-------" << endl;
    cout << "USUARIO: " << this->nome << " - PRIORIDADE: " << this->prioridade << endl;
    arq.imprimir();
    cout << "-------FIM IMPRIMINDO-------" << endl;
}

bool Usuario::inserirNaFila(Fila<Arquivo> *fila){
    int i=0;
    while(this->arquivos[i].getEspera())
    {
        i++;
    }

    this->arquivos[i].setEspera(true);

    fila->inserir(this->arquivos[i]);

    fila->ordenar();

    Arquivo aux = fila->remover();
    this->imprimirArquivo(aux);

    return true;

}