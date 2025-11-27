#include "Cadastro.h"


void gerenciamento_aeronaves(int opcao, aeronave_t **Frota_naves, int *id_ultimo)
{

     switch (opcao) {    
            case 1: inserir_lista_fim_nave(&Frota_naves, cadastro_aeronave(&Frota_naves.Contador));
                    break;
            case 2: 
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
        
        }
            
}

void gerenciamento_rotas(int opcao, rotas_t **Lista_rotas, int *id_ultimo)
{

    switch (opcao) {
        case 1: inserir_lista_fim_rota(&Lista_rotas, cadastro_rota(&Lista_rotas.Contador));
                break;

        case 2: 
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
    }
}
