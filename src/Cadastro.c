aeronave_t *cadastro_aeronave()
{
    aeronave_t *aeronave = NULL;

    aeronave = (aeronave_t*)malloc(sizeof(aeronave_t));

    printf("Digite a identificacao da aeronave:\n");
    scanf_melhorado_simples('i', &aeronave->Identificacao);

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

    return aeronave;
}

rotas_t *menu_cadastro_rota(void)
{
    rotas_t *rota;

    rota = (rotas_t*)malloc(sizeof(rotas_t));

    //há modificações pendentes na forma com que o codigo é passado
    //desejo usar um funcao para passar essa informacao
    printf("Digite o código da rota......................:");
    scanf("%i", &rota->Codigo);
    getchar();

    printf("Data de partida(dd/mm/aaaa)..................: ");
    scanf("%i/%i/%i", &rota->Data[0], &rota->Data[1], &rota->Data[2]);
    getchar();
    printf("Hora de partida(hh:mm:ss)....................: ");
    scanf("%i:%i:%i", &rota->Hora[0], &rota->Hora[1], &rota->Hora[2]);
    getchar();

    printf("Digite o local de partida (origem)...........: ");
    leitura_string(rota->Local_partida, SIZE_STR_2);

    printf("Digite o local de destino (destino)..........: ");
    leitura_string(rota->Local_destino, SIZE_STR_2);

    printf("Digite o tempo estimado de voo (hh:mm:ss)....: ");
    scanf("%i:%i:%i", &rota->Tempo_estimado_voo[0], &rota->Tempo_estimado_voo[1], &rota->Tempo_estimado_voo[2]);
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

    return rota;
}
