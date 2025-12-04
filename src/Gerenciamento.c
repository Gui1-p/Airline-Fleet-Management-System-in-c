#include "../include/Gerenciamento.h"
#include "../include/Cadastro.h"
#include "../include/Menus.h"
#include "../include/Relatorio.h"
#include "../include/Arquivos.h"
#include "../include/Auxiliar.h"
#include <stdio.h>
#include <string.h>

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
        char string_aux[SIZE_STR_2];
        data_t data_aux, data_aux_2;

    switch (opcao){
        case 1: inserir_rota_lista(lista_rota, cadastro_rota(&lista_rota->Contador, primeiro));
                break;
        case 2: listar_rotas(lista_rota->Primeiro);
                mostar_msg("Pressione para continuar");
                break;
        case 3: printf("Digite a data da rota que você procura\n");
                scanf("%i/%i/%i", &data_aux.Dia, &data_aux.Mes, &data_aux.Ano);
                getchar();                    
                listar_rotas_data(lista_rota->Primeiro, data_aux);
                mostar_msg("Pressione para continuar");
                break;

        case 4: printf("Digite o destino da rota que você procura\n");
                leitura_string(string_aux, SIZE_STR_2);
                listar_rotas_destino(lista_rota->Primeiro, string_aux);
                mostar_msg("Pressione para continuar");
                break;
                
        case 5: printf("Digite o destino da rota que você procura\n");
                leitura_string(string_aux, SIZE_STR_2);
                listar_rotas_origem(lista_rota->Primeiro, string_aux);
                mostar_msg("Pressione para continuar");
                break;
        
        case 6: printf("Digite o destino\n");
                leitura_string(string_aux, SIZE_STR_2);
                printf("Digite a data de inicio\n");
                scanf("%i/%i/%i", &data_aux.Dia, &data_aux.Mes, &data_aux.Ano);
                getchar();
                printf("Digite a data de termino\n");
                scanf("%i/%i/%i", &data_aux_2.Dia, &data_aux_2.Mes, &data_aux_2.Ano);
                getchar();
                percentual_voo_destino_intervalo_data(lista_rota->Primeiro, data_aux, data_aux_2, string_aux);
                mostar_msg("Pressione para continuar");
                break;

        case 7: percentual_voo_aeronave(lista_rota->Primeiro, primeiro);
                mostar_msg("Pressione para continuar");
                break;//Esta com problemas

        case 8: printf("Digite a data de inicio do intervalo\n");
                scanf("%i/%i/%i", &data_aux.Dia, &data_aux.Mes, &data_aux.Ano);
                getchar();
                printf("Digite a data de termino do intervalo\n");
                scanf("%i/%i/%i", &data_aux_2.Dia, &data_aux_2.Mes, &data_aux_2.Ano);
                getchar();
                consumo_combustivel_intervalo_data(lista_rota->Primeiro, data_aux, data_aux_2);
                mostar_msg("Pressione para continuar");
                break;
        case 9: listar_rota_mais_passageiros(lista_rota->Primeiro);
                mostar_msg("Pressione para continuar");
                break;
        case 10:listar_rota_menos_passageiros(lista_rota->Primeiro); 
                mostar_msg("Pressione para continuar"); 
                break;
        case 0: 
                break;
}
}

void gerenciamento_saida(int opcao, aeronave_t *inicio_nave, rotas_t *inicio_rota)
{
        string_20 aux;

    switch (opcao){
        case 1: 
                break;
        case 2: salvar_dados_naves(inicio_nave);
                salvar_dados_rotas(inicio_rota);
                break;

        case 3: printf("Digite o nome do arquivo que deseja salvar...:");
                leitura_string(aux, SIZE_STR_2);
                strcat(aux, ".txt");
                salvar_dados_naves_arq_texto(inicio_nave, aux);
                break;
                
        case 4: printf("Digite o nome do arquivo que deseja salvar...:");
                leitura_string(aux, SIZE_STR_2);
                strcat(aux, ".txt");
                salvar_dados_rotas_arq_texto(inicio_rota, aux);
                break;

        case 5: printf("Digite o nome do arquivo que deseja salvar...:");
                leitura_string(aux, SIZE_STR_2);
                strcat(aux, ".csv");
                salvar_dados_naves_arq_csv(inicio_nave, aux);
                break;

        case 6: printf("Digite o nome do arquivo que deseja salvar...:");
                leitura_string(aux, SIZE_STR_2);
                strcat(aux, ".csv");
                salvar_dados_rotas_arq_csv(inicio_rota, aux);
                break;

        case 7: printf("Digite o nome do arquivo que deseja salvar...:");
                leitura_string(aux, SIZE_STR_2);
                strcat(aux, ".html");
                salvar_dados_naves_arq_html(inicio_nave, aux);
                break;

        case 8: printf("Digite o nome do arquivo que deseja salvar...:");
                leitura_string(aux, SIZE_STR_2);
                strcat(aux, ".html");
                salvar_dados_rotas_arq_html(inicio_rota, aux);
                break;
        }       
}
