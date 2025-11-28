#ifndef CADASTRO_H
#define CADASTRO_H

#include "Types.h"


//Cadastros
aeronave_t *cadastro_aeronave(int *id_nave);
rotas_t *cadastro_rota(int *id_rota);

//Inicializar listas
void inicializar_lista_aeronaves(lista_naves_t *lista);
void inicializar_lista_rotas(lista_rotas_t *lista);

//Inserção na lista
void inserir_aeronave_lista(lista_naves_t *frota, aeronave_t *nave_cadastrada);
void inserir_rota_lista(lista_rotas_t *lista, rotas_t *rota_cadastrada);




#endif