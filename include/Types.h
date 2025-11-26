#define SIZE_STR_1          7 
#define SIZE_STR_2          20
#define TOTAL_FABRICANTES   5



typedef char string_20[SIZE_STR_2];

typedef struct data{
    int Dia;
    int Mes;
    int Ano;
} data_t;

typedef struct hora{
    int Hora;
    int Minuto;
    int Segundo;
} hora_t;

typedef enum {
    EMBRAER =   0,
    BOEING =    1,
    AIRBUS =    2,
    COMAC =     3,
    OUTROS =    4
} fabricantes_t;

typedef enum {
    MANUTENCAO,
    OPERACAO
} situacao_t;

typedef enum {
    CARGA,
    TRANSPORTE
} tipos_t;


typedef struct aeronave{
    int Identificacao;
    char Modelo[SIZE_STR_1];
    fabricantes_t Fabricante;
    char Matricula[SIZE_STR_1];
    int Ano_fabricacao;
    tipos_t Tipo;
    int Numero_passageiros;
    situacao_t Situacao;
    int Tripulacao_necessaria;
    int Qtd_manutencao;
    struct aeronave *Proximo;
} aeronave_t;

typedef struct rotas{
    int Codigo;
    data_t Data;
    hora_t Hora;
    string_20 Local_partida;
    string_20 Local_destino;
    hora_t Tempo_estimado_voo;
    float Combustivel_necessario;
    int Quantidade_passageiros;
    float Quantidade_carga;
    string_20 Membros_tripulacao[SIZE_STR_2];
    int Aeronave_alocada;
    int Total_membros;
    struct rotas *Proximo;
} rotas_t;

typedef struct lista_naves{
    unsigned int Contador;
    struct lista_naves *Primeiro;
    struct lista_naves *Ultimo;
} lista_naves_t;

typedef struct lista_rotas{
    unsigned int Contador;
    struct lista_rotas *Primeiro;
    struct lista_rotas *Ultimo;
} lista_rotas_t;