#ifndef RELATORIO_H
#define RELATORIO_H

#include "Types.h"

void informacao_aeronave(const aeronave_t * const aeronave);
void informacao_rota(const rotas_t * const rota);

void mostrar_membros_tripulacao(const rotas_t *rota);

/*
    FUNÇÕES DE AERONAVES
*/
void listar_aeronaves(const aeronave_t *frota);
void listar_aeronaves_prefixo(const aeronave_t *frota_primeiro, char *prefixo);
void listar_aeronaves_fabricante(const aeronave_t *frota_primeiro, int fabricante);
void listar_aeronaves_tipo(const aeronave_t *frota_primeiro, int tipo);
void listar_aeronaves_modelo(const aeronave_t *frota_primeiro, char *modelo);
void listar_aeronaves_ano(const aeronave_t *frota_primeiro, int ano);
void listar_aeronaves_situacao(const aeronave_t *frota_primeiro, int situacao);
void qtd_matutencao_aeronave(const aeronave_t *frota_primeiro, int id_nave);


/*
FUNÇÕES DE ROTAS
*/
void listar_rotas(const rotas_t *rotas);
void listar_rotas_data(const rotas_t *rotas, data_t data);
void listar_rotas_destino(const rotas_t *rotas, char *destino);
void listar_rotas_origem(const rotas_t *rotas, char *origem);
void percentual_voo_destino_intervalo_data(const rotas_t *rotas, data_t data_inicio, data_t data_fim, char *destino);
void percentual_voo_aeronave(const rotas_t *rotas, const aeronave_t *naves);
void consumo_combustivel_intervalo_data(const rotas_t *rotas, data_t data_inicio, data_t data_fim);
void listar_rota_mais_passageiros(rotas_t *rotas);
void listar_rota_menos_passageiros(rotas_t *rotas);

#endif
