#ifndef RELATORIO_H
#define RELATORIO_H

#include "Types.h"

/*
    RELATORIOS DE AERONAVES
*/

void informacao_aeronave(const aeronave_t* const aeronave);
void listagem_nave_prefixo(lista_rotas_t *Primeiro, char *matricula_buscada);//modificar para usar o total de naves cadastradas
void listagem_aeronave_fabricante(aeronave_t *nave, int naves_cadast, int fabricante);
void listagem_aeronave_tipo(aeronave_t *nave, int naves_cadast, int tipo);
void listagem_aeronave_modelo(aeronave_t *nave, int naves_cadast, char *modelo);
void listagem_aeronave_ano(aeronave_t *nave, int naves_cadast, int ano);
void listagem_aeronave_situacao(aeronave_t *nave, int naves_cadast, int situacao);
void quantidade_manutencoes_nave(aeronave_t *nave, int codigo, int naves_cadast);
void mostrar_membros_tripulacao(rotas_t *rota);



/*
    RELATORIOS DE ROTAS
*/

void informacao_rota(const rotas_t * const rota);
void listagem_rota_data(rotas_t *rota, int rotas_cadast, int *data);
void listagem_rota_destino(rotas_t *rota, int rotas_cadast, char *destino);
void listagem_rota_origem(rotas_t *rota, int rotas_cadast, char *origem);
void percentual_voo_destino_intervalo_data(rotas_t *rota, int rotas_cadast, char *destino, int *data_inicio, int *data_fim);
void percentual_voo_aeronave(rotas_t *rota, int rotas_cadast);
void total_combustivel_intervalo_data(rotas_t *rota, int rotas_cadast, int *data_inicio, int *data_fim);
void rota_mais_passageiros(rotas_t *rota, int rotas_cadast);
void rota_menos_passageiros(rotas_t *rota, int rotas_cadast);



#endif
