#include "../include/Cadastro.h"

void inicializar_lista_nave(lista_naves_t *lista)
{
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
    lista->Contador = 0;
}
void inicializar_lista_rota(lista_rotas_t *lista)
{
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
    lista->Contador = 0;
}


aeronave_t *cadastro_aeronave(unsigned int *id_nave)
{
    aeronave_t *aeronave = NULL;

    aeronave = (aeronave_t*)malloc(sizeof(aeronave_t));

    printf("A identificacao da aeronave é: %i\n", *id_nave);

    perfumaria_linha();

    printf("Digite o modelo da aeronave:\n");
    leitura_string(aeronave->Modelo, SIZE_STR_1);

    perfumaria_linha();

    printf("Digite a fabricante da aeronave:\n");
    mostrar_fabricantes();
    scanf_melhorado_simples('i', &aeronave->Fabricante);  

    perfumaria_linha();

    printf("Digite a matrícula da aeronave:\n");
    leitura_string(aeronave->Matricula, SIZE_STR_1);

    perfumaria_linha();

    printf("Digite o ano de fabricacao da aeronave:\n");
    scanf_melhorado_simples('i', &aeronave->Ano_fabricacao);

    perfumaria_linha();

    printf("Digite o tipo da aeronave:\n");
    printf("Digite 0 se ela for para transporte de carga.\n");
    printf("Digite 1 se ela for para transporte de passageiros.\n");
    scanf_melhorado_simples('i', &aeronave->Tipo);

    perfumaria_linha();

    printf("Digite o número de passageiros que a aeronave transporta:\n");
    scanf_melhorado_simples('i', &aeronave->Numero_passageiros);

    perfumaria_linha();

    printf("Digite a situacao da aeronave:\n");
    printf("Digite 0 se ela estiver em manutencao.\n");
    printf("Digite 1 se ela estiver em operacao.\n");
    scanf_melhorado_simples('i', &aeronave->Situacao);

    perfumaria_linha();

    printf("Digite a tripulacao necessária para a operar a aeronave:\n");
    scanf_melhorado_simples('i', &aeronave->Tripulacao_necessaria);

    if (!aeronave.Situacao){
        aeronave->Qtd_manutencao = 1;
    }
    else{
        aeronave->Qtd_manutencao = 0;
    }

    aeronave->Proximo = NULL;
    *id_nave += 1;

    return aeronave;
}

rotas_t *cadastro_rota(unsigned int *id_rota)
{
    rotas_t *rota;
    
    rota = (rotas_t*)malloc(sizeof(rotas_t));
    
    printf("O código da rota é...........................: %i", *id_rota);
    
    printf("Data de partida(dd/mm/aaaa)..................: ");
    scanf("%i/%i/%i", &rota->Data->Dia, &rota->Data->Mes, &rota->Data->Ano);
    getchar();
    printf("Hora de partida(hh:mm:ss)....................: ");
    scanf("%i:%i:%i", &rota->Horario->Hora, &rota->Horario->Minuto, &rota->Horario->Segundo);
    getchar();
    
    printf("Digite o local de partida (origem)...........: ");
    leitura_string(rota->Local_partida, SIZE_STR_2);
    
    printf("Digite o local de destino (destino)..........: ");
    leitura_string(rota->Local_destino, SIZE_STR_2);
    
    printf("Digite o tempo estimado de voo (hh:mm:ss)....: ");
    scanf("%i:%i:%i", &rota->Tempo_estimado_voo->Hora, &rota->Tempo_estimado_voo->Minuto, &rota->Tempo_estimado_voo->Segundo);
    getchar();

    printf("Digite o combustível necessário (em litros)..: ");
    scanf_melhorado_simples('f', &rota->Combustivel_necessario);

    printf("Digite a quantidade de passageiros...........: ");
    scanf_melhorado_simples('i', &rota->Quantidade_passageiros);

    printf("Digite a quantidade de carga útil............: ");
    scanf_melhorado_simples('f', &rota->Quantidade_carga);

    printf("Digite o nome dos membros da tripulação......: ");
    cadastro_membros_tripulacao(&rota);

    printf("Digite a aeronave alocada (código)...........: ");
    scanf_melhorado_simples('i', &rota->Aeronave_alocada);
    
    rota->Proximo = NULL;
    *id_rota += 1; 

    return rota;
}

void inserir_lista_fim_nave(lista_naves_t *lista, aeronave_t *novo_elemento)
{   
    if (lista->Ultimo == NULL) {
        lista->Primeiro = novo_elemento;
        lista->Ultimo = novo_elemento;
    }
    else {
        lista->fim->Proximo = novo_elemento;
        lista->fim = novo_elemento;
    }
}

void inserir_lista_fim_rota(lista_rotas_t *lista, rotas_t *novo_elemento)
{
    if (lista->Ultimo == NULL){
        lista->Primeiro = novo_elemento;
        lista->Ultimo = novo_elemento;
    }
    else{
        lista->fim->Proximo = novo_elemento;
        lista->fim = novo_elemento;
    }
}