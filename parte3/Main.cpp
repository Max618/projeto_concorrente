#include<iostream>
#include"Fila.cpp"
#include"Usuario.h"
#include"Arquivo.h"
#include<thread>

using namespace std;

int main() {
    Fila <Arquivo> *fila_impressao = new Fila<Arquivo>(4);
    
    Arquivo arq[5];
    

    //DEFININDO USUARIO 1
    arq[0].setNome("arq 1 user 1");
    arq[1].setNome("arq 2 user 1");
    arq[2].setNome("arq 3 user 1");
    arq[3].setNome("arq 4 user 1");
    arq[4].setNome("arq 5 user 1");
    Usuario usuario(1,"usuario 1",1, arq);
    //FIM USUARIO 1

    //DEFININDO USUARIO 2
    arq[0].setNome("arq 1 user 2");
    arq[1].setNome("arq 2 user 2");
    arq[2].setNome("arq 3 user 2");
    arq[3].setNome("arq 4 user 2");
    arq[4].setNome("arq 5 user 2");
    Usuario usuario2(2,"usuario 2",1, arq);
    //FIM USUARIO 2

    //DEFININDO USUARIO 3
    arq[0].setNome("arq 1 user 3");
    arq[1].setNome("arq 2 user 3");
    arq[2].setNome("arq 3 user 3");
    arq[3].setNome("arq 4 user 3");
    arq[4].setNome("arq 5 user 3");
    Usuario usuario3(3,"usuario 3",1, arq);
    //FIM USUARIO 3

    //DEFININDO USUARIO 4
    arq[0].setNome("arq 1 user 4");
    arq[1].setNome("arq 2 user 4");
    arq[2].setNome("arq 3 user 4");
    arq[3].setNome("arq 4 user 4");
    arq[4].setNome("arq 5 user 4");

    Usuario usuario4(4,"usuario 4",2, arq);
    //FIM USUARIO 4

    //DEFININDO USUARIO 5
    arq[0].setNome("arq 1 user 5");
    arq[1].setNome("arq 2 user 5");
    arq[2].setNome("arq 3 user 5");
    arq[3].setNome("arq 4 user 5");
    arq[4].setNome("arq 5 user 5");

    Usuario usuario5(5,"usuario 5",2, arq);
    //FIM USUARIO 5

    //DEFININDO USUARIO 6
    arq[0].setNome("arq 1 user 6");
    arq[1].setNome("arq 2 user 6");
    arq[2].setNome("arq 3 user 6");
    arq[3].setNome("arq 4 user 6");
    arq[4].setNome("arq 5 user 6");

    Usuario usuario6(6,"usuario 6",2, arq);
    //FIM USUARIO 6

    //THREADS
    thread t4 = usuario4.thread_init(fila_impressao);
    thread t5 = usuario5.thread_init(fila_impressao);
    thread t6 = usuario6.thread_init(fila_impressao);
    thread t1 = usuario.thread_init(fila_impressao);
    thread t2 = usuario2.thread_init(fila_impressao);
    thread t3 = usuario3.thread_init(fila_impressao);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    //FIM THREADS

    cout << "FIM PROGRAMA" << endl;

    return 0;
}