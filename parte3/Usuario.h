#ifndef USUARIO_H
#define USUARIO_H
#include"Arquivo.h"
#include<string>
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
        Arquivo arquivos[5];
        int prioridade;
    public:
        Usuario(int, string, int);
        ~Usuario();
        void setArquivos(Arquivo*);
        Arquivo* getArquivos();
        int getNumero();
        int getPrioridade();
        string getNome();
        
};
#endif