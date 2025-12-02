#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include "Types.h"

void gerenciamento_aeronave(int opcao, lista_naves_t *frota_nave);
void gerenciamento_rotas(int opcao, lista_rotas_t *lista_rota);
void gerenciamento_saida(int opcao, aeronave_t *inicio_nave, rotas_t *inicio_rota);


#endif