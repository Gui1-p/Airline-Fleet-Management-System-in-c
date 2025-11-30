#include "../include/Relatorio.h"

//FUNÇÕES BÁSICAS DE EXIBIÇÃO

void informacao_aeronave(const aeronave_t * const aeronave)
{
    printf("Identificação..........................: %i\n", aeronave->Identificacao);
    
    printf("Modelo.................................: %s\n", aeronave->Modelo);

    printf("Fabricante.............................: %s\n", fabricantes_Nave[aeronave->Fabricante]);

    printf("Matrícula..............................: %s\n", aeronave->Matricula);
    
    printf("Ano de fabricação......................: %i\n", aeronave->Ano_fabricacao);
    
    printf("Tipo...................................: %s\n", tipo_Nave[aeronave->Tipo]);
    
    printf("Número de passageiros que transporta...: %i\n", aeronave->Numero_passageiros);
    
    printf("Situação...............................: em %s\n", situacao_Nave[aeronave->Situacao]);

    printf("Tripulação necessária..................: %i\n", aeronave->Tripulacao_necessaria);
}

void informacao_rota(const rotas_t * const rota)
{
    printf("Código da rota.......................: %i\n", rota->Codigo);

    printf("Data.................................: %i/%i/%i\n", rota->Data.Dia, rota->Data.Mes, rota->Data.Ano);
    printf("Hora.................................: %i:%i:%i\n", rota->Horario.Hora, rota->Horario.Minuto, rota->Horario.Segundo);

    printf("Local de partida (origem)............: %s\n", rota->Local_partida);

    printf("Local de destino (destino)...........: %s\n", rota->Local_destino);

    printf("Tempo estimado de voo................: %i:%i:%i\n",  rota->Tempo_estimado_voo.Hora, rota->Tempo_estimado_voo.Minuto, rota->Tempo_estimado_voo..Segundo);

    printf("Combustível necessário (em litros)...: %.2f\n", rota->Combustivel_necessario);

    printf("Quantidade de passageiros............: %i\n", rota->Quantidade_passageiros);

    printf("Quantidade de carga útil.............: %.2f\n", rota->Quantidade_carga);

    mostrar_membros_tripulacao(rota);

    printf("Aeronave alocada (código)............: %i\n", rota->Aeronave_alocada);
}

void mostrar_membros_tripulacao(const rotas_t *rota)
{
    printf("Os membros da tripulação são:\n");
    for(int i = 0; i < rota->Total_membros; i++){
        printf("->%s\n", rota->*(Membros_tripulacao + i));
    }
}


/*
    FUNÇÕES DE AERONAVES
*/
void listar_aeronaves(lista_naves_t *frota_primeiro)
{
    for(frota_primeiro; frota_primeiro != NULL, frota_primeiro = frota_primeiro->Proximo){
        informacao_aeronave(frota_primeiro);
    }
}



/*
    FUNÇÕES DE ROTAS
*/
void listar_rotas(lista_rotas_t *rotas_primeiro)
{
    for(rotas_primeiro; rotas_primeiro != NULL; rotas_primeiro = rotas_primeiro->Proximo){
        informacao_rota(rotas_primeiro);
    }
}