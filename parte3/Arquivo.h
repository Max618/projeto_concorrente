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
    public:
        Arquivo();
        Arquivo(string);
        ~Arquivo();
};
#endif