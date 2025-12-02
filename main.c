#include "include/Types.h"
#include "include/Relatorio.h"
#include "include/Menus.h"
#include "include/Gerenciamento.h"
#include "include/Cadastro.h"
#include "include/Auxiliar.h"
#include "include/Arquivos.h"




int main ()
{
    int opcao;

    lista_naves_t Frota_aeronaves;
    lista_rotas_t Lista_rotas;

    inicializar_lista_nave(&Frota_aeronaves);
    inicializar_lista_rota(&Lista_rotas);

    do{
        opcao =  menu();
        switch (opcao) {    

            case 1: gerenciamento_aeronaves(sub_menu_aeronave(), &Frota_aeronaves);
                    break;

            case 2: gerenciamento_rotas(sub_menu_rota(), &Lista_rotas);
                    break;

            case 0: sub_menu_saida();
                    printf("Tenha um bom dia.\n");
                    break;

        }
    } while(opcao != 0);

    return 0;
}