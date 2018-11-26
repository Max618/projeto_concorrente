#ifndef USUARIO_H
#define USUARIO_H
#include"Arquivo.h"
class Usuario {
/*----------------- File: Usuario.h ---------------------+
|DESCRICAO DO ARQUIVO 								  |
| 													  |
| 													  |
| Implementado por "Gabriel Maximiniano" em 25/11/2018|
+-----------------------------------------------------+ */
    private:
        int numero;
        Arquivo arquivos[5];
    public:
        Usuario(int);
        ~Usuario();
};
#endif