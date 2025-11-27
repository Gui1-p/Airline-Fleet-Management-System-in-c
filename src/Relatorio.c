#include "../include/Relatorio.h"
/*
    Relatórios de aeronaves
*/

//Função base para exibição de aeronaves
void informacao_aeronave(const aeronave_t* const aeronave)
{
    printf("Identificação..........................: %i\n", aeronave->Identificacao);
    
    printf("Modelo.................................: %s\n", aeronave->Modelo);

    printf("Fabricante.............................: %s\n", fabricantes_Nave);

    printf("Matrícula..............................: %s\n", aeronave->Matricula);
    
    printf("Ano de fabricação......................: %i\n", aeronave->Ano_fabricacao);
    
    printf("Tipo...................................: %s\n", tipo_Nave[aeronave->Tipo]);
    
    printf("Número de passageiros que transporta...: %i\n", aeronave->Numero_passageiros);
    
    printf("Situação...............................: em %s\n", situacao_Nave[aeronave->Situacao]);

    printf("Tripulação necessária..................: %i\n", aeronave->Tripulacao_necessaria);
}

void listagem_nave_prefixo(lista_rotas_t *Primeiro, char *matricula_buscada)
{
    for(Primeiro; Primeiro != NULL; Primeiro = Primeiro->Proximo){
        if(strcmp(Primeiro->Matricula, matricula_buscada) == 0){
            informacao_aeronave(Primeiro);
        }
    }
}



/*
    Relatórios de rotas
*/

//Função base para exibição de rotas
void informacao_rota(const rotas_t * const rota)
{
    printf("Código da rota.......................: %i\n", rota->Codigo);

    printf("Data.................................: %i/%i/%i\n", rota->Data->Dia, rota->Data->Mes, rota->Data->Ano);
    printf("Hora.................................: %i:%i:%i\n", rota->Horario->Hora, rota->Horario->Minuto, rota->Horario->Segundo);

    printf("Local de partida (origem)............: %s\n", rota->Local_partida);

    printf("Local de destino (destino)...........: %s\n", rota->Local_destino);

    printf("Tempo estimado de voo................: %i:%i:%i\n",  rota->Tempo_estimado_voo->Hora, rota->Tempo_estimado_voo->Minuto, rota->Tempo_estimado_voo->Segundo);

    printf("Combustível necessário (em litros)...: %.2f\n", rota->Combustivel_necessario);

    printf("Quantidade de passageiros............: %i\n", rota->Quantidade_passageiros);

    printf("Quantidade de carga útil.............: %.2f\n", rota->Quantidade_carga);

    mostrar_membros_tripulacao(rota);

    printf("Aeronave alocada (código)............: %i\n", rota->Aeronave_alocada);
}