#ifndef CADASTRO_H
#define CADASTRO_H

#include "Types.h"

void inicializar_lista_nave(lista_naves_t *lista);
void inicializar_lista_rota(lista_rotas_t *lista);

aeronave_t *cadastro_aeronave(void);
rotas_t *cadastro_rota(void);


void cadastro_membros_tripulacao(rotas_t *rota);

void inserir_lista_fim_nave(aeronave_t **Primeiro, aeronave_t *novo_elemento);
void inserir_lista_fim_rota(rotas_t **Primeiro, rotas_t *novo_elemento);



#endif