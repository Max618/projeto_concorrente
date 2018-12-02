#ifndef USUARIO_H
#define USUARIO_H
#include"Arquivo.h"
#include"Fila.cpp"
#include<string>
#include<thread>
using namespace std;
class Usuario {
/*----------------- File: Usuario.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 25/11/2018|
+-----------------------------------------------------+ */
    private:
        int numero;
        string nome;
        Arquivo *arquivos;
        int prioridade;
    public:
        Usuario(int, string, int,Arquivo*);
        ~Usuario();
        void setArquivos(Arquivo*,int );
        Arquivo* getArquivos();
        int getNumero();
        int getPrioridade();
        string getNome();
        bool inserirNaFila(Fila<Arquivo>*);
        void imprimirArquivo(Arquivo &);

        thread thread_init(Fila<Arquivo>*);
};
#endif