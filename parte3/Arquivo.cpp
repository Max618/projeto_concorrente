#include<iostream>
#include"Arquivo.h"
#include<string>

using namespace std;

Arquivo::Arquivo(string nome, bool e){
    this->nome = nome;
    this->espera = e;
}

Arquivo::Arquivo(){

}

Arquivo::~Arquivo(){}

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