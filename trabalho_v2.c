#include <stdio.h>
#include <string.h>

#define SIZE_STR_1 7 
#define SIZE_STR_2 20

const char situacao_Nave[2][12] = {"Operação", "Manutenção"};
const char fabricantes_Nave[5][8] = {"Embraer", "Boeing", "Airbus", "Comac", "Outro"};
const char tipo_Nave[2][12] = {"Carga", "Transporte"};

typedef struct aeronave{
    int Identificacao;
    char Modelo[SIZE_STR_1];
    int Fabricante;
    char Matricula[SIZE_STR_1];
    int Ano_fabricacao;
    int Tipo;
    int Numero_passageiros;
    int Situacao;
    int Tripulacao_necessaria;
    int Qtd_manutencao;
} aeronave_t;

typedef char string_20_t[SIZE_STR_2];

typedef struct rotas{
    int Codigo;
    int Data[3];
    int Hora[3];
    char Local_partida[SIZE_STR_2];
    char Local_destino[SIZE_STR_2];
    int Tempo_estimado_voo[3];
    float Combustivel_necessario;
    int Quantidade_passageiros;
    float Quantidade_carga;
    string_20_t Membros_tripulacao[SIZE_STR_2];
    int Aeronave_alocada;
    int Total_membros;
} rotas_t;


int menu(void);
aeronave_t menu_cadastro_aeronave(void);
rotas_t menu_cadastro_rota(void);
void informacao_aeronave(aeronave_t *aeronave);
void leitura_string(char *ptr, int tamanho_vetor);
void perfumaria_linha(void);
int busca_nave_prefixo(aeronave_t *aeronave, char *matricula_buscada);//modificar para usar o total de naves cadastradas
void listagem_aeronave_fabricante(aeronave_t *nave, int naves_cadast, int fabricante);
int escolha_fabricante(void);
void listagem_aeronave_tipo(aeronave_t *nave, int naves_cadast, int tipo);
int escolha_tipo(void);
void listagem_aeronave_modelo(aeronave_t *nave, int naves_cadast, char *modelo);
void listagem_aeronave_ano(aeronave_t *nave, int naves_cadast, int ano);
void listagem_aeronave_situacao(aeronave_t *nave, int naves_cadast, int situacao);
void informacao_rota(rotas_t *rota);
void listagem_rota_data(rotas_t *rota, int rotas_cadast, int *data);
void listagem_rota_destino(rotas_t *rota, int rotas_cadast, char *destino);
void listagem_rota_origem(rotas_t *rota, int rotas_cadast, char *origem);
void percentual_voo_destino_intervalo_data(rotas_t *rota, int rotas_cadast, char *destino, int *data_inicio, int *data_fim);
void percentual_voo_aeronave(rotas_t *rota, int rotas_cadast);
void total_combustivel_intervalo_data(rotas_t *rota, int rotas_cadast, int *data_inicio, int *data_fim);
void rota_mais_passageiros(rotas_t *rota, int rotas_cadast);
void rota_menos_passageiros(rotas_t *rota, int rotas_cadast);
void quantidade_manutencoes_nave(aeronave_t *nave, int codigo, int naves_cadast);
void alterar_situacao_nave(aeronave_t *nave, int codigo, int naves_cadast);
void cadastro_membros_tripulacao(rotas_t *rota);
void mostrar_membros_tripulacao(rotas_t *rota);


int main ()
{
    int naves_cadastradas = 0, rotas_cadastradas = 0, opcao;

    aeronave_t frota_aeronave[100];
    rotas_t lista_rotas[100];


    do{
        int posicao_nave, maker, select_ano, select_tipo, select_situacao, select_data[3], select_data_2[3], select_codigo;
        char select_modelo[SIZE_STR_1], aeronave_procurada_matricula[SIZE_STR_1], select_destino[SIZE_STR_2], select_origem[SIZE_STR_2];
        opcao =  menu();
        switch (opcao) {    
            case 1: frota_aeronave[naves_cadastradas] = menu_cadastro_aeronave();
                    naves_cadastradas++;
                    break;

            case 2: lista_rotas[rotas_cadastradas] = menu_cadastro_rota();
                    rotas_cadastradas++;
                    break;
            case 3: for(int i = 0; i < naves_cadastradas; i++){
                        informacao_aeronave(&frota_aeronave[i]);
                        perfumaria_linha();
                    }
                    break;

            case 4: printf("Digite a matricula/prefixo da aeronave procurada.\n");
                    leitura_string(aeronave_procurada_matricula, SIZE_STR_1);
                    posicao_nave = busca_nave_prefixo(frota_aeronave, aeronave_procurada_matricula);
                    if(posicao_nave >= 0) {
                        informacao_aeronave(&frota_aeronave[posicao_nave]);
                    }
                    else{
                        printf("Esta aeronave não está cadastrada.\n");
                    }
                    break;

            case 5: maker = escolha_fabricante();
                    listagem_aeronave_fabricante(frota_aeronave, naves_cadastradas, maker);
                    break;
            case 6: select_tipo = escolha_tipo();
                    listagem_aeronave_tipo(frota_aeronave, naves_cadastradas, select_tipo);
                    break;
            case 7: printf("Digite o modelo das aeronaves procuradas:\n");
                    leitura_string(select_modelo, SIZE_STR_1);
                    listagem_aeronave_modelo(frota_aeronave, naves_cadastradas, select_modelo);
                    break;
            case 8: printf("Digite o ano que a aeronave que você busca foi fabricada: ");
                    scanf("%i", &select_ano);
                    getchar();
                    listagem_aeronave_ano(frota_aeronave, naves_cadastradas, select_ano);
                    break;
            case 9: printf("Digite a situação das aeronaves que está buscando:\n");
                    printf("0. Manutenção\n");
                    printf("1. Operação\n");
                    scanf("%i", &select_situacao);
                    getchar();
                    listagem_aeronave_situacao(frota_aeronave, naves_cadastradas, select_situacao);
                    break;
            case 10:printf("Digite a data da rota que você busca (dd/mm/aaaa): \n");
                    scanf("%i/%i/%i", &select_data[0], &select_data[1], &select_data[2]);
                    getchar();
                    listagem_rota_data(lista_rotas, rotas_cadastradas, select_data);
                    break;
            case 11:printf("Digite o local de destino das rotas que você busca:\n");
                    leitura_string(select_destino, SIZE_STR_2);
                    listagem_rota_destino(lista_rotas, rotas_cadastradas, select_destino);
                    break;
            case 12:printf("Digite o local de partida das rotas que você busca:\n");
                    leitura_string(select_origem, SIZE_STR_2);
                    listagem_rota_origem(lista_rotas, rotas_cadastradas, select_origem);
                    break;
            case 13:printf("Digite o destino que deseja saber o percentual de voos:\n");
                    leitura_string(select_destino, SIZE_STR_2);
                    printf("Digite a data de inicio (dd/mm/aaaa): ");
                    scanf("%i/%i/%i", &select_data[0], &select_data[1], &select_data[2]);
                    getchar();
                    printf("Digite a data de termino do periodo (dd/mm/aaaa):");
                    scanf("%i/%i/%i", &select_data_2[0], &select_data_2[1], &select_data_2[2]);
                    getchar();
                    percentual_voo_destino_intervalo_data(lista_rotas, rotas_cadastradas, select_destino, select_data, select_data_2);
                    break;
            case 14:percentual_voo_aeronave(lista_rotas, rotas_cadastradas);
                    perfumaria_linha();
                    break;
            case 15:printf("Digite a data de inicio (dd/mm/aaaa): ");
                    scanf("%i/%i/%i", &select_data[0], &select_data[1], &select_data[2]);
                    getchar();
                    printf("Digite a data de termino do periodo (dd/mm/aaaa):");
                    scanf("%i/%i/%i", &select_data_2[0], &select_data_2[1], &select_data_2[2]);
                    getchar();
                    total_combustivel_intervalo_data(lista_rotas, rotas_cadastradas, select_data, select_data_2);
                    break;
            case 16:rota_mais_passageiros(lista_rotas, rotas_cadastradas);
                    perfumaria_linha();
                    break;
            case 17:rota_menos_passageiros(lista_rotas, rotas_cadastradas);
                    perfumaria_linha();
                    break;
            case 18:printf("Digite o código da nave que deseja mudar a situação: ");
                    scanf("%i", &select_codigo);
                    getchar();
                    alterar_situacao_nave(frota_aeronave, select_codigo, naves_cadastradas);
                    break;
            case 19:printf("Digite o código da nave que deseja ver a quantidade de manutenções:\n");
                    scanf("%i", &select_codigo);
                    getchar();
                    quantidade_manutencoes_nave(frota_aeronave, select_codigo, naves_cadastradas);
                    break;
            case 0: printf("Tenha um bom dia.\n");
                    break;

        }
    } while(opcao != 0);

    return 0;
}

int menu()
{
    int opcao;

    printf("1.Cadastro de aeronaves; \n");
    printf("2.Cadastro de rotas; \n");
    printf("3.Relatório de aeronaves; \n");
    printf("4.Busca de aeronave por prefixo; \n");
    printf("5.Listar aeronaves por fabricante; \n");
    printf("6.Listar aeronaves por tipo (carga ou passageiro); \n");
    printf("7.Listar aeronaves por modelo; \n");
    printf("8.Listar aeronaves por ano de fabricação; \n");
    printf("9.Listar aeronaves por situação (em operação ou em manutenção); \n");
    printf("10.Consultar rota por data; \n");
    printf("11.Listar rotas por destino; \n");
    printf("12.Listar rotas por origem; \n");
    printf("13.Percentual de voos realizados para um determinado destino em um intervalo de datas; \n");
    printf("14.Percentual de voos realizados por aeronave; \n");
    printf("15.Consumo de combustível total em um intervalo de datas; \n");
    printf("16.Listar rotas com maior número de passageiros; \n");
    printf("17.Listar rotas com menor número de passageiros; \n");
    printf("18.Alterar Situação da aeronave;\n");
    printf("19.Quantidade de vezes que uma determinada aeronave entrou em manutenção; \n");
    printf("0.Sair do programa;\n");
    scanf("%i", &opcao);
    getchar();
    if(opcao > 19 || opcao < 0){
        printf("Esta opção não é válida!\n");
    }
    else{
        return opcao;
    }
}

aeronave_t menu_cadastro_aeronave(void)
{
    aeronave_t aeronave;

    printf("Digite a identificacao da aeronave:\n");
    scanf("%i", &aeronave.Identificacao);
    getchar();

    perfumaria_linha();

    printf("Digite o modelo da aeronave:\n");
    leitura_string(aeronave.Modelo, SIZE_STR_1);

    perfumaria_linha();

    printf("Digite a fabricante da aeronave:\n");
    printf("0 - Embraer\n");
    printf("1 - Boeing\n");
    printf("2 - Airbus\n");
    printf("3 - Comac\n");
    printf("4 - Outro\n");
    scanf("%i", &aeronave.Fabricante);
    getchar();

    perfumaria_linha();

    printf("Digite a matrícula da aeronave:\n");
    leitura_string(aeronave.Matricula, SIZE_STR_1);

    perfumaria_linha();

    printf("Digite o ano de fabricacao da aeronave:\n");
    scanf("%i", &aeronave.Ano_fabricacao);
    getchar();

    perfumaria_linha();

    printf("Digite o tipo da aeronave:\n");
    printf("Digite 0 se ela for para transporte de carga.\n");
    printf("Digite 1 se ela for para transporte de passageiros.\n");
    scanf("%i", &aeronave.Tipo);
    getchar();

    perfumaria_linha();

    printf("Digite o número de passageiros que a aeronave transporta:\n");
    scanf("%i", &aeronave.Numero_passageiros);
    getchar();

    perfumaria_linha();

    printf("Digite a situacao da aeronave:\n");
    printf("Digite 1 se ela estiver em manutencao.\n");
    printf("Digite 0 se ela estiver em operacao.\n");
    scanf("%i", &aeronave.Situacao);
    getchar();

    perfumaria_linha();

    printf("Digite a tripulacao necessária para a operar a aeronave:\n");
    scanf("%i", &aeronave.Tripulacao_necessaria);
    getchar();

    if (aeronave.Situacao){
        aeronave.Qtd_manutencao = 1;
    }
    else{
        aeronave.Qtd_manutencao = 0;
    }

    return aeronave;
}

rotas_t menu_cadastro_rota(void)
{
    rotas_t rota;

    printf("Digite o código da rota.\n");
    scanf("%i", &rota.Codigo);
    getchar();

    printf("Digite a data e hora.\n");
    printf("Data (dd/mm/aaaa): ");
    scanf("%i/%i/%i", &rota.Data[0], &rota.Data[1], &rota.Data[2]);
    getchar();
    printf("Hora (hh:mm:ss): ");
    scanf("%i:%i:%i", &rota.Hora[0], &rota.Hora[1], &rota.Hora[2]);
    getchar();

    printf("Digite o local de partida (origem).\n");
    leitura_string(rota.Local_partida, SIZE_STR_2);

    printf("Digite o local de destino (destino).\n");
    leitura_string(rota.Local_destino, SIZE_STR_2);

    printf("Digite o tempo estimado de voo (hh/mm/ss).\n");
    scanf("%i/%i/%i", &rota.Tempo_estimado_voo[0], &rota.Tempo_estimado_voo[1], &rota.Tempo_estimado_voo[2]);
    getchar();

    printf("Digite o combustível necessário (em litros).\n");
    scanf("%f", &rota.Combustivel_necessario);
    getchar();

    printf("Digite a quantidade de passageiros.\n");
    scanf("%i", &rota. Quantidade_passageiros);
    getchar();

    printf("Digite a quantidade de carga útil.\n");
    scanf("%f", &rota.Quantidade_carga);
    getchar();

    printf("Digite o nome dos membros da tripulação.\n");
    cadastro_membros_tripulacao(&rota);


    printf("Digite a aeronave alocada (código).\n");
    scanf("%i", &rota.Aeronave_alocada);
    getchar();

    return rota;
}

void informacao_aeronave(aeronave_t *aeronave)
{
    printf("Identificação: %i\n", aeronave->Identificacao);
    
    printf("Modelo: %s\n", aeronave->Modelo);

    printf("Fabricante: %s\n", fabricantes_Nave[aeronave->Fabricante]);

    printf("Matrícula: %s\n", aeronave->Matricula);
    
    printf("Ano de fabricação: %i\n", aeronave->Ano_fabricacao);
    
    printf("Tipo: %s\n", tipo_Nave[aeronave->Tipo]);
    
    printf("Número de passageiros que transporta: %i\n", aeronave->Numero_passageiros);
    
    printf("Situação: em %s\n", situacao_Nave[aeronave->Situacao]);

    printf("Tripulação necessária: %i\n", aeronave->Tripulacao_necessaria);
}

//Função para ler strings, entra com o vetor que será armazenado e o tamanho dele
void leitura_string(char *ptr, int tamanho_vetor)
{
    fgets(ptr, tamanho_vetor, stdin);
    
    for(int j = 0; j < strlen(ptr); j++){
        if(ptr[j]  == '\n'){
            ptr[j] = '\0';
        }
    }
    
}

void perfumaria_linha(void)
{
    for(int i = 0; i < 40; i++){
        printf("--");
    }
    printf("\n");
}

//busca a aeronave no banco de dados pela matricula e devolve a posição da nave, se ela estiver registrada
int busca_nave_prefixo(aeronave_t *aeronave, char *matricula_buscada)
{
    for(int i = 0; i < 100; i++){
        if(strcmp(aeronave[i].Matricula, matricula_buscada) == 0){
            return i;
        }
    }

    return -1;
}

//mostra as opções de fabricante e recebe a posição do fabricante desejado pelo usuario
int escolha_fabricante(void)
{
    int opcao;

    printf("Digite o número correspondente ao fabricante da aeronave que procura:\n");
    printf("0. %s\n", fabricantes_Nave[0]);
    printf("1. %s\n", fabricantes_Nave[1]);
    printf("2. %s\n", fabricantes_Nave[2]);
    printf("3. %s\n", fabricantes_Nave[3]);
    printf("4. %s\n", fabricantes_Nave[4]);
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

//recebe a posição 0 da frota de naves e busca nos dados cadastrados naves com o fabricante desejado e mostra
void listagem_aeronave_fabricante(aeronave_t *nave, int naves_cadast, int fabricante)
{
    for(int i = 0; i < naves_cadast; i++){
        if(nave[i].Fabricante == fabricante){
            informacao_aeronave(&nave[i]);
            perfumaria_linha();
        }
    }
}

int escolha_tipo(void)
{
    int opcao;

    printf("Digite o número correspondente ao fabricante da aeronave que procura:\n");
    printf("0. %s\n", tipo_Nave[0]);
    printf("1. %s\n", tipo_Nave[1]);
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

void listagem_aeronave_tipo(aeronave_t *nave, int naves_cadast, int tipo)
{
    for(int i = 0; i < naves_cadast; i++){
        if(nave[i].Tipo == tipo){
            informacao_aeronave(&nave[i]);
            perfumaria_linha();
        }
    }
}

void listagem_aeronave_modelo(aeronave_t *nave, int naves_cadast, char *modelo)
{
    for(int i = 0; i < naves_cadast; i++){
        if(strcmp(nave[i].Modelo, modelo) == 0){
            informacao_aeronave(&nave[i]);
            perfumaria_linha();
        }
    }
}

void listagem_aeronave_ano(aeronave_t *nave, int naves_cadast, int ano)
{
    for(int i = 0; i < naves_cadast; i++){
        if(nave[i].Ano_fabricacao == ano){
            informacao_aeronave(&nave[i]);
            perfumaria_linha();
        }
    }
}

void listagem_aeronave_situacao(aeronave_t *nave, int naves_cadast, int situacao)
{
   for(int i = 0; i < naves_cadast; i++){
        if(nave[i].Situacao == situacao){
            informacao_aeronave(&nave[i]);
            perfumaria_linha();
        }
    } 
}

//Funções de rota

void informacao_rota(rotas_t *rota)
{
    printf("Código da rota: %i\n", rota->Codigo);

    printf("Data e hora.\n");
    printf("Data: %i/%i/%i\n", rota->Data[0], rota->Data[1], rota->Data[2]);
    printf("Hora: %i:%i:%i\n", rota->Hora[0], rota->Hora[1], rota->Hora[2]);

    printf("Local de partida (origem): %s\n", rota->Local_partida);

    printf("Local de destino (destino): %s\n", rota->Local_destino);

    printf("Tempo estimado de voo: %i:%i:%i\n", rota->Tempo_estimado_voo[0], rota->Tempo_estimado_voo[1], rota->Tempo_estimado_voo[2]);

    printf("Combustível necessário (em litros): %.2f\n", rota->Combustivel_necessario);

    printf("Quantidade de passageiros: %i\n", rota->Quantidade_passageiros);

    printf("Quantidade de carga útil: %.2f\n", rota->Quantidade_carga);

    mostrar_membros_tripulacao(rota);

    printf("Aeronave alocada (código): %i\n", rota->Aeronave_alocada);
}

void listagem_rota_data(rotas_t *rota, int rotas_cadast, int *data)
{
    for(int i = 0; i < rotas_cadast; i++){
        if ((rota[i].Data[0] == data[0]) && (rota[i].Data[1] == data[1]) && (rota[i].Data[2] == data[2])){
            informacao_rota(&rota[i]);
            perfumaria_linha();
        }
    }
}

void listagem_rota_destino(rotas_t *rota, int rotas_cadast, char *destino)
{
    for(int i = 0; i < rotas_cadast; i++){
        if (strcmp(rota[i].Local_destino, destino) == 0){
            informacao_rota(&rota[i]);
            perfumaria_linha();
        }
    }
}

void listagem_rota_origem(rotas_t *rota, int rotas_cadast, char *origem)
{
    for(int i = 0; i < rotas_cadast; i++){
        if (strcmp(rota[i].Local_partida, origem) == 0){
            informacao_rota(&rota[i]);
            perfumaria_linha();
        }
    }
}

//verifica se a data da rota esta dentro do intervalo multiplicando ano e mês de forma que os números não tenham 
//interferencia entre si ao serem somados
void percentual_voo_destino_intervalo_data(rotas_t *rota, int rotas_cadast, char *destino, int *data_inicio, int *data_fim)
{
    unsigned long int data_inicio_soma, data_fim_soma;
    int contador_rota_destino = 0, contador_rota_destino_intervalo = 0;
    float percentual_voos;

    data_inicio_soma = ((data_inicio[2]*10000) + (data_inicio[1]*100) + data_inicio[0]);
    data_fim_soma = ((data_fim[2]*10000) + (data_fim[1]*100) + data_fim[0]);

    for(int i = 0; i < rotas_cadast; i++){
        if (strcmp(rota[i].Local_destino, destino) == 0){
            contador_rota_destino++;
            
            int data_analisada = (rota[i].Data[0]) + (rota[i].Data[1] * 100) + (rota[i].Data[2] * 10000);
            if(data_analisada >= data_inicio_soma && data_analisada <= data_fim_soma ){
                    contador_rota_destino_intervalo++;
                }

            // for(int j = data_inicio_soma; j <= data_fim_soma; j++){
            //     if(((rota[i].Data[0]) + (rota[i].Data[1] * 100) + (rota[i].Data[2] * 10000)) == j ){
            //         contador_rota_destino_intervalo++;
            //     }
            // }
        }
    }

    percentual_voos = (contador_rota_destino_intervalo * 100) / (float)contador_rota_destino;

    perfumaria_linha();
    printf("O percentual de voos para %s no intevalo dado é: %f.\n", destino, percentual_voos);
    perfumaria_linha();
}

//a variavel i acessa a lista de rotas e busca pelas naves alocadas em cada uma das rotas
//quando i acessa uma rota ela chama um laço for para verifizar se existe outra rota com a mesma nave na lista
//mas antes ela verifica se aquela nave ja não foi contabilizada analisando a variável total_voos_nave
void percentual_voo_aeronave(rotas_t *rota, int rotas_cadast)
{
    int total_voos_nave[100][2], total_naves_dif = 0;

    for(int i = 0; i < rotas_cadast; i++){
        total_voos_nave[i][1] = 0;
        int foi_contada = 0;

        for(int k = 0; k < i; k++){
            if(rota[i].Aeronave_alocada == total_voos_nave[k][0] && i != 0){
                foi_contada = 1;
            }
        }

        if(foi_contada == 0){
            for(int j = 0; j < rotas_cadast; j++){
                if (rota[i].Aeronave_alocada == rota[j].Aeronave_alocada){
                    total_voos_nave[total_naves_dif][0] = rota[i].Aeronave_alocada;
                    total_voos_nave[total_naves_dif][1] += 1;
                }
            }
            total_naves_dif++;
        }
    }


    for(int i = 0; i < total_naves_dif; i++){
        float percentual = (total_voos_nave[i][1] * 100) / (float)rotas_cadast;
        printf("O percentual de voos da nave %i é %f.\n", total_voos_nave[i][0], percentual);
    }
}

//usa a mesmo lógica da função anterior com datas
void total_combustivel_intervalo_data(rotas_t *rota, int rotas_cadast, int *data_inicio, int *data_fim)
{
    unsigned long int data_inicio_soma, data_fim_soma;
    float total_combustivel = 0;

    data_inicio_soma = ((data_inicio[2]*10000) + (data_inicio[1]*100) + data_inicio[0]);
    data_fim_soma = ((data_fim[2]*10000) + (data_fim[1]*100) + data_fim[0]);

    for(int i = 0; i < rotas_cadast; i++){
        
        int data_analisada = (rota[i].Data[0]) + (rota[i].Data[1] * 100) + (rota[i].Data[2] * 10000);
        
        if (data_analisada >= data_inicio_soma && data_analisada <= data_fim_soma ){
            total_combustivel += rota[i].Combustivel_necessario;
        }
        
    }

    perfumaria_linha();
    printf("O total de combustivel consumido no intervalo é de: %f\n", total_combustivel);
    perfumaria_linha();
}

void rota_mais_passageiros(rotas_t *rota, int rotas_cadast)
{
    int maior = rota[0].Quantidade_passageiros, p_rota = 0;

    for(int i = 0; i < rotas_cadast; i++){
        if (rota[i].Quantidade_passageiros > maior){
            maior = rota[i].Quantidade_passageiros;
            p_rota = i;
        }
    }

    printf("A rota com maior número de passageiros é: \n");
    informacao_rota(&rota[p_rota]);
}

void rota_menos_passageiros(rotas_t *rota, int rotas_cadast)
{
    int menor = rota[0].Quantidade_passageiros, p_rota = 0;

    for(int i = 0; i < rotas_cadast; i++){
        if (rota[i].Quantidade_passageiros < menor){
            menor = rota[i].Quantidade_passageiros;
            p_rota = i;
        }
    }

    printf("A rota com menor número de passageiros é: \n");
    informacao_rota(&rota[p_rota]);
}

void quantidade_manutencoes_nave(aeronave_t *nave, int codigo, int naves_cadast)
{
    for(int i = 0; i < naves_cadast; i++){
        if(nave[i].Identificacao == codigo){
            printf("O número de vezes que esta aeronave entrou em manutenção é: %i\n", nave[i].Qtd_manutencao);
        }
    }
}

void alterar_situacao_nave(aeronave_t *nave, int codigo, int naves_cadast)
{
    for(int i = 0; i < naves_cadast; i++){
        if(nave[i].Identificacao == codigo){
            printf("1. Manutenção\n");
            printf("0. Operação\n");
            scanf("%i", &nave[i].Situacao);
            getchar();
            if(nave[i].Situacao == 1) {
                nave[i].Qtd_manutencao++;
            }
        }
    }
}

void cadastro_membros_tripulacao(rotas_t *rota)
{
    rota->Total_membros = 0;
    int opc, i = 0;

    do{
        leitura_string(rota->Membros_tripulacao[i], SIZE_STR_2);
        rota->Total_membros += 1;

        i++;

        printf("1. Cadastar membro da tripulação.\n");
        printf("0. Parar de cadastrar\n");
        scanf("%i", &opc);
        getchar();
    } while(opc != 0 && i != 19);

}

void mostrar_membros_tripulacao(rotas_t *rota)
{
    printf("Os membros da tripulação são:\n");
    for(int i = 0; i < rota->Total_membros; i++){
        printf("->%s\n", rota->Membros_tripulacao[i]);
    }
}