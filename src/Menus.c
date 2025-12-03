#include "../include/Menus.h"
#include "../include/Auxiliar.h"
#include <stdio.h>

int menu_principal(void)
{
    int opcao;

    limpar_tela();

    printf("1.Menu - Aeronaves;\n");
    printf("2.Menu - Rotas;\n");
    printf("0.Sair do programa;\n");
    scanf_melhorado_simples('i', &opcao);  
    
    if(opcao > 2 || opcao < 0){
        printf("Esta opcao nao eh valida!\n");
        return menu_principal();
    }

    limpar_tela();
    return opcao;
}

int sub_menu_aeronaves(void)
{
    int opcao;
    
    limpar_tela();

    printf("1.Cadastro de aeronaves; \n");
    printf("2.Relatório de aeronaves; \n");
    printf("3.Busca de aeronave por prefixo; \n");
    printf("4.Listar aeronaves por fabricante; \n");
    printf("5.Listar aeronaves por tipo (carga ou passageiro); \n");
    printf("6.Listar aeronaves por modelo; \n");
    printf("7.Listar aeronaves por ano de fabricação; \n");
    printf("8.Listar aeronaves por situação (em operação ou em manutenção); \n");
    printf("9.Alterar Situação da aeronave;\n");
    printf("10.Quantidade de vezes que uma aeronave entrou em manutenção; \n");
    printf("0.Voltar;\n");
    scanf_melhorado_simples('i', &opcao);  
    
    if(opcao > 10 || opcao < 0){
        printf("Esta opcao nao eh valida!\n");
        return sub_menu_aeronaves();
    }

    limpar_tela();
    return opcao; 
}

int sub_menu_rotas(void)
{
    int opcao;

    limpar_tela();

    printf("1.Cadastro de rotas; \n");
    printf("2.Relatório de rotas;\n");
    printf("3.Consultar rota por data; \n");
    printf("4.Listar rotas por destino; \n");
    printf("5.Listar rotas por origem; \n");
    printf("6.Percentual de voos realizados para um determinado destino em um intervalo de datas; \n");
    printf("7.Percentual de voos realizados por aeronave; \n");
    printf("8.Consumo de combustível total em um intervalo de datas; \n");
    printf("9.Listar rotas com maior número de passageiros; \n");
    printf("10.Listar rotas com menor número de passageiros; \n");
    printf("0.Voltar;\n");
    scanf_melhorado_simples('i', &opcao);
    
    if(opcao > 10 || opcao < 0){
        printf("Esta opcao nao eh valida!\n");
        return sub_menu_rotas();
    }

    limpar_tela();
    return opcao;
}

int sub_menu_saida(void)
{
    int opcao;

    limpar_tela();

    printf("1.Sair\n");
    printf("2.Salvar em arquivo binário e sair\n");
    printf("3.Salvar em arquivo texto e sair\n");
    printf("4.Salvar em arquivo csv e sair\n");
    printf("5.Salvar em arquivo html e sair\n")
    scanf_melhorado_simples('i', &opcao);

    if(opcao > 5 || opcao < 1){
        printf("Esta opcao nao eh valida\n");
        return sub_menu_saida();
    }

    limpar_tela();
    return opcao;
}