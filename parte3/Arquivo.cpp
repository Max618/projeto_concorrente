#include<iostream>
#include"Arquivo.h"
#include<string>

using namespace std;

Arquivo::Arquivo(string nome, bool e, int p){
    this->nome = nome;
    this->espera = e;
    this->prioridade = p;
}

Arquivo::Arquivo(){
    this->prioridade = -1;
    this->espera = false;
}

Arquivo::~Arquivo(){}

bool Arquivo::operator>(Arquivo& obj){
    return this->prioridade > obj.prioridade;
}

void Arquivo::setNome(string nome){
    this->nome = nome;
}

string Arquivo::getNome(){
    return this->nome;
}

void Arquivo::setEspera(bool e){
    this->espera = e;
}

bool Arquivo::getEspera(){
    return this->espera;
}

int Arquivo::getPrioridade(){
    return this->prioridade;
}

void Arquivo::setPrioridade(int p){
    this->prioridade = p;
}

void Arquivo::imprimir(){
    cout << "\tIMPRIMINDO ARQUIVO: " << this->nome << endl;
    system("sleep 5");
}

ostream& operator<<(ostream& saida, const Arquivo& obj){
    saida << "[";
    saida << "PRIORIDADE: " << obj.prioridade << " ESPERA: " << obj.espera << " NOME: " << obj.nome.c_str();
    saida << "]";
    return saida; //permite cout << a << b << c;
}

Arquivo& Arquivo::operator=(Arquivo& obj){
    if(this != &obj){
        this->espera = obj.espera;
        this->nome = obj.nome;
        this->prioridade = obj.prioridade;
    }
     //cout << "OPERATOR ARQ: " << this->prioridade << " " << this->espera << " " << this->nome << endl;
    return *this;
}