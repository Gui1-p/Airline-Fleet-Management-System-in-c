#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "Types.h"

    void salvar_dados_naves(aeronave_t *inicio);
    void salvar_dados_rotas(rotas_t *inicio);

    void carregar_dados_naves(lista_naves_t *naves);
    void carregar_dados_rotas(lista_rotas_t *rotas);



#endif