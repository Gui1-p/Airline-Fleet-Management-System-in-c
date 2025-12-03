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

    mostrar_membros_tripulacao(rota, stdout);

    printf("Aeronave alocada (código)............: %i\n", rota->Aeronave_alocada);
}

void mostrar_membros_tripulacao(const rotas_t *rota, FILE *fp_arq)
{
    printf("Os membros da tripulação são:\n");
    for(int i = 0; i < rota->Total_membros; i++){
        fprintf(fp_arq ,"->%s\n", *(rota.Membros_tripulacao + i));
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

void listar_rotas_data(const rotas_t *rotas, data_t data)
{
    for(rotas; rotas != NULL; rotas = rotas->Proximo){
        if(data.Dia == rotas->Data.Dia && data.Mes == rotas->Data.Mes && data.Ano == rotas->Data.Ano){
            informacao_rota(rotas);
            printf("\n");
        }
    }
}

void listar_rotas_destino(const rotas_t *rotas, char *destino)
{
        for(rotas; rotas != NULL; rotas = rotas->Proximo){
        if(!strcmp(rotas->Local_destino, destino)){
            informacao_rota(rotas);
            printf("\n");
        }
    }
}

void listar_rotas_origem(const rotas_t *rotas, char *origem)
{
    for(rotas; rotas != NULL; rotas = rotas->Proximo){
        if(!strcmp(rotas->Local_partida, origem)){
            informacao_rota(rotas);
            printf("\n");
        }
    }
}

void percentual_voo_destino_intervalo_data(const rotas_t *rotas, data_t data_inicio, data_t data_fim, char *destino)
{
    unsigned long int data_inicio_soma, data_fim_soma;
    int contador_rota_destino = 0, contador_rota_destino_intervalo = 0;
    float percentual_voos;

    data_inicio_soma = ((data_inicio.Ano*10000) + (data_inicio.Mes*100) + data_inicio.Dia);
    data_fim_soma = ((data_fim.Ano*10000) + (data_fim.Mes*100) + data_fim.Dia);

    for(rotas; rotas != NULL; rotas = rotas->Proximo){
        
        if (!strcmp(rotas->Local_destino, destino)){
            contador_rota_destino++;
            
            int data_analisada = (rotas->Data.Dia) + (rotas->Data.Mes * 100) + (rotas->Data.Ano * 10000);
            if(data_analisada >= data_inicio_soma && data_analisada <= data_fim_soma ){
                    contador_rota_destino_intervalo++;
                }
        }
    }

    percentual_voos = (contador_rota_destino_intervalo * 100) / (float)contador_rota_destino;

    perfumaria_linha();
    printf("O percentual de voos para %s no intevalo dado é: %.2f\n", destino, percentual_voos);
    perfumaria_linha();
}

void percentual_voo_aeronave(const rotas_t *rotas, const aeronave_t *naves)
{
    while(naves){
        const rotas_t *rotas_aux = rotas;

        int total_voos_nave = 0, total_voos = 0;
        float percentual_voos;

        for(rotas_aux; rotas_aux != NULL; rotas_aux = rotas_aux->Proximo){
            total_voos++;
            if(rotas_aux->Aeronave_alocada == naves->Identificacao){
            total_voos_nave++; 
        }
    }
    percentual_voos = ((float)total_voos_nave / total_voos) * 100;

    if(total_voos == 0) percentual_voos = 0;

    printf("O percentual de voos da nave %d é : %.2f%%\n", naves->Identificacao, percentual_voos);
    naves = naves->Proximo;
    }
}

void consumo_combustivel_intervalo_data(const rotas_t *rotas, data_t data_inicio, data_t data_fim)
{
    unsigned long int data_inicio_soma, data_fim_soma;
    float total_combustivel = 0;

    data_inicio_soma = ((data_inicio.Ano*10000) + (data_inicio.Mes*100) + data_inicio.Dia);
    data_fim_soma = ((data_fim.Ano*10000) + (data_fim.Mes*100) + data_fim.Dia);

    for(rotas; rotas != NULL; rotas = rotas->Proximo){

        int data_analisada = (rotas->Data.Dia) + (rotas->Data.Mes * 100) + (rotas->Data.Ano * 10000);
        if(data_analisada >= data_inicio_soma && data_analisada <= data_fim_soma ){
            total_combustivel += rotas->Combustivel_necessario;
        }
    }

    printf("O consumo total de combustivel nesse intervalo foi de: %f", total_combustivel);
}

void listar_rota_mais_passageiros(rotas_t *rotas)
{
    rotas_t *maior = rotas;
    int maior_int = rotas->Quantidade_passageiros;
    
    for(rotas; rotas != NULL; rotas = rotas->Proximo){
        if(rotas->Quantidade_passageiros > maior_int){
            maior_int = rotas->Quantidade_passageiros;
            maior = rotas;
        }
    }

    informacao_rota(maior);
    printf("\n");
}

void listar_rota_menos_passageiros(rotas_t *rotas)
{
    rotas_t *menor = rotas;
    int menor_int = rotas->Quantidade_passageiros;
    
    for(rotas; rotas != NULL; rotas = rotas->Proximo){
        if(menor_int > rotas->Quantidade_passageiros){
            menor_int = rotas->Quantidade_passageiros;
            menor = rotas;
        }
    }

    informacao_rota(menor);
    printf("\n");
}