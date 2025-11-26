int main ()
{
    int opcao;
    unsigned int ultimo_id_nave, ultimo_id_rota;

    aeronave_t *Frota_aeronave = NULL;
    rotas_t *Lista_rotas = NULL;


    do{
        opcao =  menu();
        switch (opcao) {    

            case 1: gerenciamento_aeronaves(sub_menu_aeronave(), Frota_aeronave, ultimo_id_nave);
                    break;

            case 2: gerenciamento_rotas(sub_menu_rota(), Lista_rotas, ultimo_id_rota);
                    break;

            case 0: sub_menu_saida();
                    printf("Tenha um bom dia.\n");
                    break;

        }
    } while(opcao != 0);

    return 0;
}