#include "../include/Auxiliar.h"
#include "../include/Types.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void leitura_string(char *ptr, int tamanho_vetor)
{
    fgets(ptr, tamanho_vetor, stdin);
    retirar_enter(ptr);
    formatar_maiusculo(ptr);
}

void perfumaria_linha(void)
{
    for(int i = 0; i < 20; i++){
        printf(">>>");
    }
    printf("\n");
}

void retirar_enter(char *ptr)
{
    *(ptr + (strlen(ptr) - 1)) = '\0';
}

void formatar_maiusculo(char *ptr)
{
    for(int i = 0; i < strlen(ptr); i++){
        *(ptr + i) = toupper(*(ptr + i));
    }
}

void scanf_melhorado_simples(char tipo, void *destino)
{
    switch (tipo){
        case 'i': scanf("%i", (int*)destino);
                  getchar();
                  break;
        case 'f': scanf("%f", (float*)destino);
                  getchar();
                  break;
    }
}

void limpar_tela(void)
{
    system("clear");
}

void mostar_msg(char *msg)
{
    printf("\n");
    perfumaria_linha();
    printf("%s\n", msg);
    perfumaria_linha();
    getchar();
}

int escolha_fabricante(void)
{
    int opcao;

    printf("Digite o número correspondente ao fabricante da aeronave que procura:\n");
    mostrar_fabricantes();
    scanf_melhorado_simples('i', &opcao);

    return opcao;
}

int escolha_tipo(void)
{
    int opcao;

    printf("Digite o número correspondente ao fabricante da aeronave que procura:\n");
    for(int i = 0; i < TOTAL_TIPOS_NAVE; i++){
        printf("%d. %s\n", i, *(tipo_Nave + i));
    }
    scanf_melhorado_simples('i', &opcao);

    return opcao;
}

void mostrar_fabricantes(void)
{
    for(int i = 0; i < TOTAL_FABRICANTES; i++){
        printf("%d. %s\n", i, *(fabricantes_Nave + i));
    }
}

void alterar_situacao_nave(aeronave_t *lista_nave, int id_nave)
{
    int contador = 0;

    if(lista_nave->Identificacao == id_nave){
        printf("0.Manutenção\n");
        printf("1.Operação\n");
        scanf_melhorado_simples('i', &lista_nave->Situacao);
        return;
    }

    lista_nave = lista_nave->Proximo;

    if(lista_nave->Proximo == NULL){
        if(contador == 0){
            printf("Está aeronave não foi encontrada\n");
        }
        return;
    }
}