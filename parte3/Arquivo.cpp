#include<iostream>
#include"Arquivo.h"
#include<string>

using namespace std;

Arquivo::Arquivo(string nome){
    this->nome = nome;
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