#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "Types.h"
#include <stdio.h>

    //Funções essenciais
    void salvar_dados_naves(aeronave_t *inicio);
    void salvar_dados_rotas(rotas_t *inicio);

    void carregar_dados_naves(lista_naves_t *naves);
    void carregar_dados_rotas(lista_rotas_t *rotas);
    void mostrar_membros_tripulacao_p_arq(const rotas_t *rota, FILE *fp_arq);

    //Funções extras
    void dados_nave(aeronave_t *nave, FILE *fp_arq);
    void dados_rota(rotas_t *rota, FILE *fp_arq, int opc);

    void salvar_dados_naves_arq_texto(aeronave_t *inicio, char *nome);
    void salvar_dados_rotas_arq_texto(rotas_t *inicio, char *nome);

    void salvar_dados_naves_arq_csv(aeronave_t *inicio, char *nome);
    void salvar_dados_rotas_arq_csv(rotas_t *inicio, char *nome);

    void salvar_dados_naves_arq_html(aeronave_t *inicio, char *nome);
    void salvar_dados_rotas_arq_html(rotas_t *inicio, char *nome);

    void liberar_memoria_naves(aeronave_t *aeronaves);
    void liberar_memoria_rotas(rotas_t *rotas);


#endif