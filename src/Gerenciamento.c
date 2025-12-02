#include "../include/Gerenciamento.h"
#include "../include/Cadastro.h"
#include "../include/Menus.h"
#include "../include/Relatorio.h"

void gerenciamento_aeronave(int opcao, lista_naves_t *frota_nave)
{

    switch (opcao){
        case 1: inserir_aeronave_lista(frota_nave, cadastro_aeronave(&frota_nave->Contador));
                break;
        case 2: listar_aeronaves(frota_nave->Primeiro);
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
        case 0:
                break;
}

}

void gerenciamento_rotas(int opcao, lista_rotas_t *lista_rota)
{
    switch (opcao){
        case 1: inserir_rota_lista(lista_rota, cadastro_rota(&lista_rota->Contador));
                break;
        case 2: listar_rotas(lista_rota->Primeiro);
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
        case 0: 
                break;
}
}

void gerenciamento_saida(int opcao)
{

    switch (opcao){
        case 1: 
                break;
        case 2: 
                break;
        case 3: 
                break;
        case 4: 
                break;
        case 5: 
                break;

}
}
