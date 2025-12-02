#include "../include/Relatorio.h"
#include "../include/Auxiliar.h"
#include <string.h>
#include <stdio.h>

//FUNÇÕES BÁSICAS DE EXIBIÇÃO

void informacao_aeronave(const aeronave_t * const aeronave)
{
    printf("Identificação..........................: %i\n", aeronave->Identificacao);
    
    printf("Modelo.................................: %s\n", aeronave->Modelo);

    printf("Fabricante.............................: %s\n", fabricantes_Nave[aeronave->Fabricante]);

    printf("Matrícula..............................: %s\n", aeronave->Matricula);
    
    printf("Ano de fabricação......................: %i\n", aeronave->Ano_fabricacao);
    
    printf("Tipo...................................: %s\n", tipo_Nave[aeronave->Tipo]);
    
    printf("Número de passageiros que transporta...: %i\n", aeronave->Numero_passageiros);
    
    printf("Situação...............................: em %s\n", situacao_Nave[aeronave->Situacao]);

    printf("Tripulação necessária..................: %i\n", aeronave->Tripulacao_necessaria);
}

void informacao_rota(const rotas_t * const rota)
{
    printf("Código da rota.......................: %i\n", rota->Codigo);

    printf("Data.................................: %i/%i/%i\n", rota->Data.Dia, rota->Data.Mes, rota->Data.Ano);
    printf("Hora.................................: %i:%i:%i\n", rota->Horario.Hora, rota->Horario.Minuto, rota->Horario.Segundo);

    printf("Local de partida (origem)............: %s\n", rota->Local_partida);

    printf("Local de destino (destino)...........: %s\n", rota->Local_destino);

    printf("Tempo estimado de voo................: %i:%i:%i\n",  rota->Tempo_estimado_voo.Hora, rota->Tempo_estimado_voo.Minuto, rota->Tempo_estimado_voo.Segundo);

    printf("Combustível necessário (em litros)...: %.2f\n", rota->Combustivel_necessario);

    printf("Quantidade de passageiros............: %i\n", rota->Quantidade_passageiros);

    printf("Quantidade de carga útil.............: %.2f\n", rota->Quantidade_carga);

    mostrar_membros_tripulacao(rota);

    printf("Aeronave alocada (código)............: %i\n", rota->Aeronave_alocada);
}

void mostrar_membros_tripulacao(const rotas_t *rota)
{
    printf("Os membros da tripulação são:\n");
    for(int i = 0; i < rota->Total_membros; i++){
        printf("->%s\n", rota->Membros_tripulacao[i]);
    }
}


/*
    FUNÇÕES DE AERONAVES
*/
void listar_aeronaves(const aeronave_t *frota_primeiro)
{
    for(frota_primeiro; frota_primeiro != NULL; frota_primeiro = frota_primeiro->Proximo){
        informacao_aeronave(frota_primeiro);
        printf("\n");
    }
}

void listar_aeronaves_prefixo(const aeronave_t *frota_primeiro, char *prefixo)
{
    int contador = 0;
    while(frota_primeiro){
        if(!strcmp(frota_primeiro->Matricula, prefixo)){
            informacao_aeronave(frota_primeiro);
            printf("\n");
            contador++;
        }

        if(frota_primeiro->Proximo == NULL){
            if(contador == 0){
                printf("Não há naves cadastradas com este prefixo!\n");
            }
            return;
        }
        
        frota_primeiro = frota_primeiro->Proximo;
    }
}

void listar_aeronaves_fabricante(const aeronave_t *frota_primeiro, int fabricante)
{
    int contador = 0;
    while(frota_primeiro){
        if(frota_primeiro->Fabricante == fabricante)
        {
            informacao_aeronave(frota_primeiro);
            printf("\n");
            contador++;
        }


        if(frota_primeiro->Proximo == NULL){
            if(contador == 0){
                printf("Não há naves deste fabricante cadastradas!\n");
            }
            return;
        }

        frota_primeiro = frota_primeiro->Proximo;
    }
}

void listar_aeronaves_tipo(const aeronave_t *frota_primeiro, int tipo)
{
    int contador = 0;
    while(frota_primeiro){
        if(frota_primeiro->Tipo == tipo)
        {
            informacao_aeronave(frota_primeiro);
            printf("\n");
            contador++;
        }
    
        if(frota_primeiro->Proximo == NULL){
            if(contador == 0){
                printf("Não há naves deste tipo cadastradas!\n");
            }
            return;
        }

        frota_primeiro = frota_primeiro->Proximo;
    }
}

void listar_aeronaves_modelo(const aeronave_t *frota_primeiro, char *modelo)
{
    int contador = 0;
    while(frota_primeiro){
        if(!strcmp(frota_primeiro->Modelo, modelo)){
            informacao_aeronave(frota_primeiro);
            printf("\n");
            contador++;
        }

        if(frota_primeiro->Proximo == NULL){
            if(contador == 0){
                printf("Não há naves cadastradas com este prefixo!\n");
            }
            return;
        }

        frota_primeiro = frota_primeiro->Proximo;
    }
}

void listar_aeronaves_ano(const aeronave_t *frota_primeiro, int ano)
{
    int contador = 0;
    while(frota_primeiro){
        if(frota_primeiro->Ano_fabricacao == ano)
        {
            informacao_aeronave(frota_primeiro);
            printf("\n");
            contador++;
        }

        if(frota_primeiro->Proximo == NULL){
            if(contador == 0){
                printf("Não há naves fabricadas neste ano cadastradas!\n");
            }
            return;
        }

        frota_primeiro = frota_primeiro->Proximo;
    }
}

void listar_aeronaves_situacao(const aeronave_t *frota_primeiro, int situacao)
{
    int contador = 0;
    while(frota_primeiro){
        if(frota_primeiro->Situacao == situacao)
        {
            informacao_aeronave(frota_primeiro);
            printf("\n");
            contador++;
        }

        if(frota_primeiro->Proximo == NULL){
            if(contador == 0){
                printf("Não há naves nesta situação cadastradas!\n");
            }
            return;
        }

        frota_primeiro = frota_primeiro->Proximo;
    }
}

void qtd_matutencao_aeronave(const aeronave_t *frota_primeiro, int id_nave)
{
    int contador = 0;
    while(frota_primeiro){
        if(frota_primeiro->Identificacao == id_nave)
        {
            printf("Esta aeronave entrou em manutenção %d vezes.\n", frota_primeiro->Qtd_manutencao);
            printf("\n");
            contador++;
            return;
        }

        if(frota_primeiro->Proximo == NULL){
            if(contador == 0){
                printf("Não há nenhuma nave com este id cadastrada!\n");
            }
            return;
        }

        frota_primeiro = frota_primeiro->Proximo;
    }
}





/*
    FUNÇÕES DE ROTAS
*/
void listar_rotas(const rotas_t *rotas_primeiro)
{
    for(rotas_primeiro; rotas_primeiro != NULL; rotas_primeiro = rotas_primeiro->Proximo){
        informacao_rota(rotas_primeiro);
        printf("\n");
    }
}