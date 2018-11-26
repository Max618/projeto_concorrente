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