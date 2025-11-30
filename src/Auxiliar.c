#include "../include/Auxiliar.h"
#include <ctypes.h>
#include <stdio.h>
#include <string.h>



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
        *(str + i) = toupper(*(ptr + i));
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
    for(int i = 0; i < TOTAL_TIPO_NAVE; i++){
        printf("%d. %s\n", i, *(tipo_Nave + i));
    }
    scanf_melhorado_simples('i', &opcao);

    return opcao;
}

void mostrar_fabricantes(void)
{
    for(int i = 0; i < TOTAL_FABRICANTES; i++){
        printf("i. %s\n", *(fabricantes_Nave + i));
    }
}