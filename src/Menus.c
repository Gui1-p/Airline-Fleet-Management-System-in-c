


int menu()
{
    int opcao;
    printf("1.Menu - Aeronaves;\n");
    printf("2.Menu - Rotas;\n");
    printf("0.Sair do programa;\n");
    scanf_melhorado_simples('i', &opcao);  
    if(opcao > 2 || opcao < 0){
        printf("Esta opcao nao eh valida!\n");
        return;
    }
    else{
        
    }
}

int sub_menu_aeronave()
{
    int opcao; 

    printf("1.Cadastro de aeronaves; \n");
    printf("2.Relatório de aeronaves; \n");
    printf("3.Busca de aeronave por prefixo; \n");
    printf("4.Listar aeronaves por fabricante; \n");
    printf("5.Listar aeronaves por tipo (carga ou passageiro); \n");
    printf("6.Listar aeronaves por modelo; \n");
    printf("7.Listar aeronaves por ano de fabricação; \n");
    printf("8.Listar aeronaves por situação (em operação ou em manutenção); \n");
    printf("9.Alterar Situação da aeronave;\n");
    printf("10.Quantidade de vezes que uma determinada aeronave entrou em manutenção; \n");
    printf("0.Voltar;\n");
    scanf_melhorado_simples('i', &opcao);  
    
    if(opcao > 10 || opcao < 0){
        printf("Esta opcao nao eh valida!\n");
        return;
    }
    return opcao; 
}

int sub_menu_rota()
{
    int opcao;

    printf("1.Cadastro de rotas; \n");
    printf("2.Consultar rota por data; \n");
    printf("3.Listar rotas por destino; \n");
    printf("4.Listar rotas por origem; \n");
    printf("5.Percentual de voos realizados para um determinado destino em um intervalo de datas; \n");
    printf("6.Percentual de voos realizados por aeronave; \n");
    printf("7.Consumo de combustível total em um intervalo de datas; \n");
    printf("8.Listar rotas com maior número de passageiros; \n");
    printf("9.Listar rotas com menor número de passageiros; \n");
    printf("0.Voltar;\n");
    scanf_melhorado_simples('i', &opcao);
    
    if(opcao > 9 || opcao < 0){
        printf("Esta opcao nao eh valida!\n");
        return;
    }
    return opcao;
    
}
