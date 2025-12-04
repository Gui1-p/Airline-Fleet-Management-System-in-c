#include "../include/Menus.h"
#include "../include/Auxiliar.h"
#include <stdio.h>

int menu_principal(void)
{
    int opcao;

    do{
        limpar_tela();

        printf("1.Menu - Aeronaves;\n");
        printf("2.Menu - Rotas;\n");
        printf("3.Menu - Salvar arquivos;\n");
        printf("0.Sair do programa;\n");
        
        scanf_melhorado_simples('i', &opcao);  
        
        if(opcao > 3 || opcao < 0){
            printf("Esta opcao nao eh valida!\n");
        }
    } while(opcao > 3 || opcao < 0);
    
    limpar_tela();
    return opcao;
}

int sub_menu_aeronaves(void)
{
    int opcao;
    
    do{
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

        }
    } while(opcao > 10 || opcao < 0);
    limpar_tela();
    return opcao; 
}

int sub_menu_rotas(void)
{
    int opcao;

    do{
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
        }
    } while(opcao > 10 || opcao < 0);

    limpar_tela();
    return opcao;
}

int sub_menu_saida(void)
{
    int opcao;

    do{
        limpar_tela();

        printf("1.Voltar\n");

        printf("2.Salvar em arquivo binário\n");
        
        printf("3.Salvar em naves em arquivo texto e sair\n");
        printf("4.Salvar em rotas em arquivo texto e sair\n");

        printf("5.Salvar em naves em arquivo csv e sair\n");
        printf("6.Salvar em rotas em arquivo csv e sair\n");

        printf("7.Salvar em naves em arquivo html e sair\n");
        printf("8.Salvar em rotas em arquivo html e sair\n");


        scanf_melhorado_simples('i', &opcao);

        if(opcao > 8 || opcao < 1){
            printf("Esta opcao nao eh valida\n");
        }
    } while(opcao > 8 || opcao < 1);

    limpar_tela();
    return opcao;
}