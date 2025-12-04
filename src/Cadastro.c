#include "../include/Cadastro.h"
#include "../include/Auxiliar.h"
#include "../include/Relatorio.h"
#include <stdlib.h>
#include <stdio.h>

#define MANUTENCAO  0
#define OPERACAO    1

//Cadastros
aeronave_t *cadastro_aeronave(unsigned int *id_nave)
{
    aeronave_t *aeronave = NULL;

    aeronave = (aeronave_t*)malloc(sizeof(aeronave_t));

    aeronave->Identificacao = *id_nave;
    printf("A identificacao da aeronave é: %i\n", aeronave->Identificacao);

    printf("Digite o modelo da aeronave:\n");
    leitura_string(aeronave->Modelo, SIZE_STR_1);

    printf("Digite a fabricante da aeronave:\n");
    mostrar_fabricantes();
    scanf_melhorado_simples('i', &aeronave->Fabricante);  

    printf("Digite a matrícula da aeronave:\n");
    leitura_string(aeronave->Matricula, SIZE_STR_1);

    printf("Digite o ano de fabricacao da aeronave:\n");
    scanf_melhorado_simples('i', &aeronave->Ano_fabricacao);

    printf("Digite o tipo da aeronave:\n");
    printf("Digite 0 se ela for para transporte de carga.\n");
    printf("Digite 1 se ela for para transporte de passageiros.\n");
    scanf_melhorado_simples('i', &aeronave->Tipo);

    printf("Digite o número de passageiros que a aeronave transporta:\n");
    scanf_melhorado_simples('i', &aeronave->Numero_passageiros);

    printf("Situacao da aeronave:\n");
    printf("Digite 0 se ela estiver em manutencao.\n");
    printf("Digite 1 se ela estiver em operacao.\n");
    scanf_melhorado_simples('i', &aeronave->Situacao);

    printf("Digite a tripulacao necessária para a operar a aeronave:\n");
    scanf_melhorado_simples('i', &aeronave->Tripulacao_necessaria);

    if (!aeronave->Situacao){
        aeronave->Qtd_manutencao = MANUTENCAO;
    }
    else{
        aeronave->Qtd_manutencao = OPERACAO;
    }

    aeronave->Proximo = NULL;
    *id_nave += 1;

    return aeronave;
}

rotas_t *cadastro_rota(unsigned int *id_rota, aeronave_t *nave)
{
    rotas_t *rota;
    
    rota = (rotas_t*)malloc(sizeof(rotas_t));
    
    rota->Codigo = *id_rota;
    printf("O código da rota é...........................: %i\n", rota->Codigo);
    
    printf("Data de partida(dd/mm/aaaa)..................: ");
    scanf("%i/%i/%i", &rota->Data.Dia, &rota->Data.Mes, &rota->Data.Ano);
    getchar();
    printf("Hora de partida(hh:mm:ss)....................: ");
    scanf("%i:%i:%i", &rota->Horario.Hora, &rota->Horario.Minuto, &rota->Horario.Segundo);
    getchar();
    
    printf("Digite o local de partida (origem)...........: ");
    leitura_string(rota->Local_partida, SIZE_STR_2);
    
    printf("Digite o local de destino (destino)..........: ");
    leitura_string(rota->Local_destino, SIZE_STR_2);
    
    printf("Digite o tempo estimado de voo (hh:mm:ss)....: ");
    scanf("%i:%i:%i", &rota->Tempo_estimado_voo.Hora, &rota->Tempo_estimado_voo.Minuto, &rota->Tempo_estimado_voo.Segundo);
    getchar();

    printf("Digite o combustível necessário (em litros)..: ");
    scanf_melhorado_simples('f', &rota->Combustivel_necessario);

    printf("Digite a quantidade de passageiros...........: ");
    scanf_melhorado_simples('i', &rota->Quantidade_passageiros);

    printf("Digite a quantidade de carga útil............: ");
    scanf_melhorado_simples('f', &rota->Quantidade_carga);

    printf("Digite o nome dos membros da tripulação......: ");
    cadastro_membros_tripulacao(rota);
    
    alocar_nave_rota(nave, &rota->Aeronave_alocada);

    rota->Proximo = NULL;
    *id_rota += 1; 

    return rota;
}

//Inicializar listas
void inicializar_lista_aeronaves(lista_naves_t *lista)
{
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
    lista->Contador = 0;
}
void inicializar_lista_rotas(lista_rotas_t *lista)
{
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
    lista->Contador = 0;
}

//Inserção na lista
void inserir_aeronave_lista(lista_naves_t *frota, aeronave_t *nave_cadastrada)
{
    if(frota->Primeiro == NULL){
        frota->Primeiro = nave_cadastrada;
        frota->Ultimo = nave_cadastrada;
        return;
    }

    frota->Ultimo->Proximo = nave_cadastrada;
    frota->Ultimo = nave_cadastrada;
}

void inserir_rota_lista(lista_rotas_t *lista, rotas_t *rota_cadastrada)
{
    if(lista->Primeiro == NULL){
        lista->Primeiro = rota_cadastrada;
        lista->Ultimo = rota_cadastrada;
        return;
    }

    lista->Ultimo->Proximo = rota_cadastrada;
    lista->Ultimo = rota_cadastrada;
}


void cadastro_membros_tripulacao(rotas_t *rota)
{
    rota->Total_membros = 0;
    int opc, i = 0;

    do{
        leitura_string(rota->Membros_tripulacao[i], SIZE_STR_2);
        rota->Total_membros += 1;   

        i++;

        printf("1. Cadastar membro da tripulação.\n");
        printf("0. Parar de cadastrar\n");
        scanf_melhorado_simples('i', &opc);

    } while(opc != 0 && i != 19);

}

void alocar_nave_rota(aeronave_t *nave, int *id_nave)
{
    int opc = 1;
    while(opc){
        aeronave_t *primeiro_lista = nave;

        printf("Digite a aeronave alocada (código)...........: ");
        scanf_melhorado_simples('i', id_nave);

        while(primeiro_lista != NULL){
            if(primeiro_lista->Identificacao == *id_nave){
                if(primeiro_lista->Situacao == OPERACAO){
                    return;
                }
            }
            primeiro_lista = primeiro_lista->Proximo;
        }
        printf("Aeronave inválida\n");
        printf("Digite 1 se deseja continuar ou 0 para sair..: ");
        scanf_melhorado_simples('i', &opc);
        limpar_tela();
        printf("Estas são as aeronaves cadastradas:\n");
        listar_aeronaves(nave);
        mostar_msg("Pressione para continuar");

    }
}
