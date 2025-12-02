#include "../include/Gerenciamento.h"
#include "../include/Cadastro.h"
#include "../include/Menus.h"
#include "../include/Relatorio.h"
#include "../include/Arquivos.h"
#include "../include/Auxiliar.h"
#include <stdio.h>

void gerenciamento_aeronave(int opcao, lista_naves_t *frota_nave)
{
    char string_aux[SIZE_STR_1];
    int aux;


    switch (opcao){
        case 1: inserir_aeronave_lista(frota_nave, cadastro_aeronave(&frota_nave->Contador));
                break;

        case 2: listar_aeronaves(frota_nave->Primeiro);
                mostar_msg("Pressione para continuar");
                break;

        case 3: leitura_string(string_aux, SIZE_STR_1);
                listar_aeronaves_prefixo(frota_nave->Primeiro, string_aux);
                mostar_msg("Pressione para continuar");
                break;

        case 4: listar_aeronaves_fabricante(frota_nave->Primeiro, escolha_fabricante());
                mostar_msg("Pressione para continuar");
                break;

        case 5: listar_aeronaves_tipo(frota_nave->Primeiro, escolha_tipo());
                mostar_msg("Pressione para continuar");
                break;

        case 6: leitura_string(string_aux, SIZE_STR_1);
                listar_aeronaves_modelo(frota_nave->Primeiro, string_aux);
                mostar_msg("Pressione para continuar");
                break;

        case 7: printf("Digite o ano de fabricação da aeronave que deseja\n");
                scanf_melhorado_simples('i', &aux);
                listar_aeronaves_ano(frota_nave->Primeiro, aux);
                mostar_msg("Pressione para continuar");
                break;

        case 8: printf("Digite a situação de fabricação da aeronave que deseja\n");
                printf("0.Manutenção\n");
                printf("1.Operação\n");
                scanf_melhorado_simples('i', &aux);
                listar_aeronaves_situacao(frota_nave->Primeiro, aux);
                mostar_msg("Pressione para continuar");
                break;

        case 9: printf("Digite a identificação da aeronave que deseja\n");
                scanf_melhorado_simples('i', &aux);
                alterar_situacao_nave(frota_nave->Primeiro, aux);
                break;

        case 10:printf("Digite a identificação da aeronave que deseja\n");
                scanf_melhorado_simples('i', &aux);
                qtd_matutencao_aeronave(frota_nave->Primeiro, aux);
                mostar_msg("Pressione para continuar");
                break;
        case 0: 
                break;
}

}

void gerenciamento_rotas(int opcao, lista_rotas_t *lista_rota, aeronave_t *primeiro)
{
        char string_aux[SIZE_STR_1];

    switch (opcao){
        case 1: inserir_rota_lista(lista_rota, cadastro_rota(&lista_rota->Contador, primeiro));
                break;
        case 2: listar_rotas(lista_rota->Primeiro);
                mostar_msg("Pressione para continuar");
                break;
        case 3: 
        
                break;
        case 4: 
                break;
        case 5: 
                break;
        case 6: 
                
                break;
        case 7: 
                break;
        case 8: 
                break;
        case 9: 
                break;
        case 10:
                break;
        case 0: 
                break;
}
}

void gerenciamento_saida(int opcao, aeronave_t *inicio_nave, rotas_t *inicio_rota)
{

    switch (opcao){
        case 1: 
                break;
        case 2: salvar_dados_naves(inicio_nave);
                salvar_dados_rotas(inicio_rota);
                break;
        case 3: 
                break;
        case 4: 
                break;
        case 5: 
                break;

}
}
