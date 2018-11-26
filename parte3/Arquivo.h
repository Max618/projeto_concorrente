#ifndef ARQUIVO_H
#define ARQUIVO_H
#include<string>
#include<iostream>
using namespace std;
class Arquivo {
/*----------------- File: Arquivo.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 25/11/2018|
+-----------------------------------------------------+ */
    private:
        string nome;
        bool espera;
        int prioridade;
    public:
        Arquivo();
        Arquivo(string, bool, int);
        ~Arquivo();

        void setNome(string);
        string getNome();
        bool getEspera();
        void setEspera(bool);
        int getPrioridade();
        void setPrioridade(int);

        bool operator>(Arquivo&);
};
#endif