#ifndef RELATORIO_H
#define RELATORIO_H

#include "Types.h"

void informacao_aeronave(const aeronave_t * const aeronave);
void informacao_rota(const rotas_t * const rota);

void mostrar_membros_tripulacao(const rotas_t *rota);

/*
    FUNÇÕES DE AERONAVES
*/
void listar_aeronaves(aeronave_t *frota);



/*
    FUNÇÕES DE ROTAS
*/
void listar_rotas(rotas_t *rotas);


#endif
