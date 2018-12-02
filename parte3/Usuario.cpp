#include<iostream>
#include"Usuario.h"
#include"Arquivo.h"
#include<string>
#include<thread>
#include<queue>
#include<shared_mutex>         
#include<condition_variable>

using namespace std;

shared_timed_mutex mtx_inserir;
condition_variable_any cv_inserir;
bool ready_inserir = true;

shared_timed_mutex mtx_imprimir;
condition_variable_any cv_imprimir;
bool ready_imprimir = true;




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

bool Usuario::temArquivo(){
    for(int i = 0; i < 5; i++){
        if(!this->arquivos[i].getEspera())
            return true;
    }
    return false;
}

void Usuario::imprimirArquivo(Arquivo& arq){
    cout << "-------IMPRIMINDO-------" << endl;
    cout << "USUARIO(" << this->numero << "): " << this->nome << " - PRIORIDADE: " << this->prioridade << endl;
    arq.imprimir();
    cout << "-------FIM IMPRIMINDO-------" << endl;
}

bool Usuario::waitSecs(){
    cout << "ESPERANDO 3 SECS" << endl;
    system("sleep 3");
    return true;
}

bool Usuario::inserirNaFila(Fila<Arquivo> *fila){
    shared_lock<shared_timed_mutex> lck(mtx_inserir);
    shared_lock<shared_timed_mutex> lck2(mtx_imprimir);
    int i;
        do{
            system("sleep 3");
            i=0;
            while(this->arquivos[i].getEspera() && i < 5)
            {
                i++;
            }

            this->arquivos[i].setEspera(true);

            while(fila->cheia() || !ready_inserir){ 
                cv_inserir.wait(lck);
            }
                cout << "ENTRANDO CRITICA INSERIR FILA - " << this->numero << endl;
                fila->inserir(this->arquivos[i]);
                cout << "SAIDO CRITICA INSERIR FILA- " << this->numero << endl;
            cv_inserir.notify_all(); 

            while(!ready_imprimir){ 
                cv_imprimir.wait(lck2); 
            }
            fila->ordenar();
            ready_inserir = false;
            ready_imprimir = false;
                cout << "ENTRANDO CRITICA REMOVER FILA- " << this->numero << endl;
                Arquivo aux = fila->remover();
                this->imprimirArquivo(aux);
                cout << "SAINDO CRITICA REMOVER FILA- " << this->numero << endl;

            ready_imprimir = true;
            ready_inserir = true;
            cv_imprimir.notify_all(); 
        }while(this->waitSecs() && this->temArquivo());
    return true;
}