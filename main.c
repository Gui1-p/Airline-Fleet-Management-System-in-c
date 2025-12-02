#include "include/Gerenciamento.h"
#include "include/Menus.h"
#include "include/Cadastro.h"
#include "include/Arquivos.h"
#include <stdio.h>





int main ()
{
    int opcao;

    lista_naves_t Frota_aeronaves;
    lista_rotas_t Lista_rotas;

    inicializar_lista_aeronaves(&Frota_aeronaves);
    inicializar_lista_rotas(&Lista_rotas);

    carregar_dados_naves(&Frota_aeronaves);
    carregar_dados_rotas(&Lista_rotas);

    do{
        opcao =  menu_principal();
        switch (opcao) {    

            case 1: gerenciamento_aeronave(sub_menu_aeronaves(), &Frota_aeronaves);
                    break;

            case 2: gerenciamento_rotas(sub_menu_rotas(), &Lista_rotas);
                    break;

            case 0: gerenciamento_saida(sub_menu_saida(), Frota_aeronaves.Primeiro, Lista_rotas.Primeiro);
                    printf("Tenha um bom dia.\n");
                    break;

        }
    } while(opcao != 0);

    return 0;
}