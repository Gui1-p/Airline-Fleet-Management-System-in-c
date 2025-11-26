


void gerenciamento_aeronaves(int opcao, aeronave_t **Frota_naves, int *id_ultimo)
{
    int aux;
    char str_aux[SIZE_STR_1];

     switch (opcao) {    
            case 1: inserir_lista_fim_nave(Frota_naves, cadastro_aeronave());
                    break;

            case 2: for(int i = 0; i < naves_cadastradas; i++){
                        informacao_aeronave(&frota_aeronave[i]);
                        perfumaria_linha();
                    }
                    break;

            case 3: printf("Digite a matricula/prefixo da aeronave procurada.\n");
                    leitura_string(str_aux, SIZE_STR_1);
                    aux = busca_nave_prefixo(frota_aeronave, str_aux);
                    if(aux >= 0) {
                        informacao_aeronave(&frota_aeronave[aux]);
                    }
                    else{
                        printf("Esta aeronave não está cadastrada.\n");
                    }
                    break;

            case 4: aux = escolha_fabricante();
                    listagem_aeronave_fabricante(frota_aeronave, naves_cadastradas, aux);
                    break;

            case 5: aux = escolha_tipo();
                    listagem_aeronave_tipo(frota_aeronave, naves_cadastradas, aux);
                    break;

            case 6: printf("Digite o modelo das aeronaves procuradas:\n");
                    leitura_string(str_aux, SIZE_STR_1);
                    listagem_aeronave_modelo(frota_aeronave, naves_cadastradas, str_aux);
                    break;

            case 7: printf("Digite o ano que a aeronave que você busca foi fabricada: ");
                    scanf_melhorado_simples('i', &aux);  
                    listagem_aeronave_ano(frota_aeronave, naves_cadastradas, aux);
                    break;

            case 8: printf("Digite a situação das aeronaves que está buscando:\n");
                    printf("0. Manutenção\n");
                    printf("1. Operação\n");
                    scanf_melhorado_simples('i', &aux);  
                    listagem_aeronave_situacao(frota_aeronave, naves_cadastradas, aux);
                    break;
            
            case 9: printf("Digite o código da nave que deseja mudar a situação: ");
                    scanf_melhorado_simples('i', &aux);  
                    alterar_situacao_nave(frota_aeronave, naves_cadastradas);
                    break;

            case 10:printf("Digite o código da nave que deseja ver a quantidade de manutenções:\n");
                    scanf_melhorado_simples('i', &aux);        
                    quantidade_manutencoes_nave(frota_aeronave, naves_cadastradas);
                    break;
            
                }
            
}

void gerenciamento_rotas(int opcao, rotas_t **Lista_rotas, int *id_ultimo)
{
    int select_data[3], select_data_2[3];
    string_20 str_aux_2;

    switch (opcao) {
        case 1: lista_rotas[rotas_cadastradas] = menu_cadastro_rota();
                rotas_cadastradas++;
                break;

        case 2: printf("Digite a data da rota que você busca (dd/mm/aaaa): \n");
                scanf("%i/%i/%i", &select_data[0], &select_data[1], &select_data[2]);
                getchar();
                listagem_rota_data(lista_rotas, rotas_cadastradas, select_data);
                break;

        case 3: printf("Digite o local de destino das rotas que você busca:\n");
                leitura_string(str_aux_2, SIZE_STR_2);
                listagem_rota_destino(lista_rotas, rotas_cadastradas, str_aux_2);
                break;

        case 4: printf("Digite o local de partida das rotas que você busca:\n");
                 leitura_string(str_aux_2, SIZE_STR_2);
                 listagem_rota_origem(lista_rotas, rotas_cadastradas, str_aux_2);
                 break;

        case 5: printf("Digite o destino que deseja saber o percentual de voos:\n");
                leitura_string(str_aux_2, SIZE_STR_2);
                printf("Digite a data de inicio (dd/mm/aaaa): ");
                scanf("%i/%i/%i", &select_data[0], &select_data[1], &select_data[2]);
                getchar();
                printf("Digite a data de termino do periodo (dd/mm/aaaa):");
                scanf("%i/%i/%i", &select_data_2[0], &select_data_2[1], &select_data_2[2]);
                getchar();
                percentual_voo_destino_intervalo_data(lista_rotas, rotas_cadastradas, str_aux_2, select_data, select_data_2);
                break;

        case 6: percentual_voo_aeronave(lista_rotas, rotas_cadastradas);
                perfumaria_linha();
                break;

        case 7: printf("Digite a data de inicio (dd/mm/aaaa): ");
                scanf("%i/%i/%i", &select_data[0], &select_data[1], &select_data[2]);
                getchar();
                printf("Digite a data de termino do periodo (dd/mm/aaaa):");
                scanf("%i/%i/%i", &select_data_2[0], &select_data_2[1], &select_data_2[2]);
                getchar();
                total_combustivel_intervalo_data(lista_rotas, rotas_cadastradas, select_data, select_data_2);
                break;

        case 8: rota_mais_passageiros(lista_rotas, rotas_cadastradas);
                perfumaria_linha();
                break;

        case 9: rota_menos_passageiros(lista_rotas, rotas_cadastradas);
                perfumaria_linha();
                break;
    }
}
