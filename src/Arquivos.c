#include "../include/Types.h"
#include "../include/Cadastro.h"
#include <stdlib.h>
#include <stdio.h>



void salvar_dados_naves(aeronave_t *inicio)
{
    FILE *fp = NULL;

    fp = fopen("naves.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo naves.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(aeronave_t), 1, fp);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void salvar_dados_rotas(rotas_t *inicio)
{
    FILE *fp = NULL;

    fp = fopen("rotas.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo rotas.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(rotas_t), 1, fp);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void carregar_dados_naves(lista_naves_t *naves)
{
    FILE *fp = NULL;
    aeronave_t *novo = NULL;

    fp = fopen("naves.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo naves.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (aeronave_t*)malloc(sizeof(aeronave_t));

        fread(novo, sizeof(aeronave_t), 1, fp);
        novo->Proximo = NULL;

        if (!feof(fp)) {
            inserir_aeronave_lista(naves, novo);
        }
        else {
            free(novo);
        }
    }

    fclose(fp);
}

void carregar_dados_rotas(lista_rotas_t *rotas)
{
    FILE *fp = NULL;
    rotas_t *novo = NULL;

    fp = fopen("rotas.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo rotas.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (rotas_t*)malloc(sizeof(rotas_t));

        fread(novo, sizeof(rotas_t), 1, fp);
        novo->Proximo = NULL;
        if (!feof(fp)) {
            inserir_rota_lista(rotas, novo);
        }
        else {
            free(novo);
        }
    }

    fclose(fp);  
}
