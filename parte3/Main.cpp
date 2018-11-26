#include<iostream>
#include<thread>
#include"Fila.cpp"
#include"Usuario.h"
#include"Arquivo.h"

using namespace std;

int main() {
    Fila <int> *fila_impressao = new Fila<int>(30);
    Arquivo arq[5];
    //cout << "hue";
    for(int i = 0; i < 5; i++){
        arq[i].setNome("nome");
    }
    Usuario user1(1,"usuario 1",1);
    
    user1.setArquivos(arq);

    for(int i = 0; i < 5; i++){
        cout << user1.getArquivos()[i].getNome() << " ";
    }

    delete [] fila_impressao;
    return 0;
}