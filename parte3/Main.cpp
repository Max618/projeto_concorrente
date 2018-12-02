#include<iostream>
#include"Fila.cpp"
#include"Usuario.h"
#include"Arquivo.h"
#include<thread>

using namespace std;

int main() {
    Fila <Arquivo> *fila_impressao = new Fila<Arquivo>(3);
    
    Arquivo arq[5];
    

    //DEFININDO USUARIO 1
    for(int i = 0; i < 5; i++){
        arq[i].setNome("nome user 1");
    }
    arq[0].setNome("arq 1 user 1");
    arq[1].setNome("arq 2 user 1");
    
    Usuario usuario(1,"usuario 1",3, arq);
    //FIM USUARIO 1

    //DEFININDO USUARIO 2
    for(int i = 0; i < 5; i++){
        arq[i].setNome("nome user 2");
    }
    arq[0].setNome("arq 1 user 2");
    arq[1].setNome("arq 2 user 2");

    Usuario usuario2(1,"usuario 1",1, arq);
    //FIM USUARIO 2

    //THREADS
    thread t1 = usuario.thread_init(fila_impressao);
    thread t2 = usuario2.thread_init(fila_impressao);

    t1.join();
    t2.join();
    //FIM THREADS

    return 0;
}