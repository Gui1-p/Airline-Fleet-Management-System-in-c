#include "../include/Types.h"
#include "../include/Cadastro.h"
#include "../include/Relatorio.h"
#include <stdlib.h>
#include <stdio.h>



void salvar_dados_naves(aeronave_t *inicio)
{
    FILE *fp = NULL;

    fp = fopen("naves.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo naves.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(aeronave_t), 1, fp);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void salvar_dados_rotas(rotas_t *inicio)
{
    FILE *fp = NULL;

    fp = fopen("rotas.bin", "wb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo rotas.bin\n");
        return;
    }

    while (inicio) {
        fwrite(inicio, sizeof(rotas_t), 1, fp);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void carregar_dados_naves(lista_naves_t *naves)
{
    FILE *fp = NULL;
    aeronave_t *novo = NULL;

    fp = fopen("naves.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo naves.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (aeronave_t*)malloc(sizeof(aeronave_t));

        fread(novo, sizeof(aeronave_t), 1, fp);
        novo->Proximo = NULL;

        if (!feof(fp)) {
            inserir_aeronave_lista(naves, novo);
            if(naves->Contador <= novo->Identificacao) {
                naves->Contador = novo->Identificacao + 1;
            }
        }
        else {
            free(novo);
        }

    }

    fclose(fp);
}

void carregar_dados_rotas(lista_rotas_t *rotas)
{
    FILE *fp = NULL;
    rotas_t *novo = NULL;

    fp = fopen("rotas.bin", "rb");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo rotas.bin\n");
        return;
    }

    while (!feof(fp)) {
        novo = (rotas_t*)malloc(sizeof(rotas_t));

        fread(novo, sizeof(rotas_t), 1, fp);
        novo->Proximo = NULL;
        if (!feof(fp)) {
            inserir_rota_lista(rotas, novo);
            
            if(rotas->Contador <= novo->Codigo) {
                rotas->Contador = novo->Codigo + 1;
            }
        }
        else {
            free(novo);
        }
    }



    fclose(fp);  
}


//Funções extras
void dados_nave(aeronave_t *nave, FILE *fp_arq)
{
    fprintf(fp_arq, "Identificação..........................: %i\n", nave->Identificacao);
    
    fprintf(fp_arq, "Modelo.................................: %s\n", nave->Modelo);

    fprintf(fp_arq, "Fabricante.............................: %s\n", *(fabricantes_Nave + nave->Fabricante));

    fprintf(fp_arq, "Matrícula..............................: %s\n", nave->Matricula);
    
    fprintf(fp_arq, "Ano de fabricação......................: %i\n", nave->Ano_fabricacao);
    
    fprintf(fp_arq, "Tipo...................................: %s\n", *(tipo_Nave + nave->Tipo));
    
    fprintf(fp_arq, "Número de passageiros que transporta...: %i\n", nave->Numero_passageiros);
    
    fprintf(fp_arq, "Situação...............................: em %s\n", *(situacao_Nave + nave->Situacao));

    fprintf(fp_arq, "Tripulação necessária..................: %i\n", nave->Tripulacao_necessaria);
}

void dados_rota(rotas_t *rota, FILE *fp_arq, int opc)
{
    fprintf(fp_arq, "Código da rota.......................: %i\n", rota->Codigo);
    
    fprintf(fp_arq, "Data.................................: %i/%i/%i\n", rota->Data.Dia, rota->Data.Mes, rota->Data.Ano);
    fprintf(fp_arq, "Hora.................................: %i:%i:%i\n", rota->Horario.Hora, rota->Horario.Minuto, rota->Horario.Segundo);
    
    fprintf(fp_arq, "Local de partida (origem)............: %s\n", rota->Local_partida);
    
    fprintf(fp_arq, "Local de destino (destino)...........: %s\n", rota->Local_destino);
    
    fprintf(fp_arq, "Tempo estimado de voo................: %i:%i:%i\n",  rota->Tempo_estimado_voo.Hora, rota->Tempo_estimado_voo.Minuto, rota->Tempo_estimado_voo.Segundo);
    
    fprintf(fp_arq, "Combustível necessário (em litros)...: %.2f\n", rota->Combustivel_necessario);
    
    fprintf(fp_arq, "Quantidade de passageiros............: %i\n", rota->Quantidade_passageiros);
    
    fprintf(fp_arq, "Quantidade de carga útil.............: %.2f\n", rota->Quantidade_carga);
    
    if(opc == 0){
        mostrar_membros_tripulacao(rota, fp_arq);
    }
    
    fprintf(fp_arq, "Aeronave alocada (código)............: %i\n", rota->Aeronave_alocada);

}



void salvar_dados_naves_arq_texto(aeronave_t *inicio, char *nome)
{
    FILE *fp = NULL;

    fp = fopen(nome, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome);
        return;
    }

    while (inicio) {
        dados_nave(inicio, fp);
        fprintf(fp, "\n");
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void salvar_dados_rotas_arq_texto(rotas_t *inicio, char *nome)
{
    FILE *fp = NULL;

    fp = fopen(nome, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome);
        return;
    }

    while (inicio) {
        dados_rota(inicio, fp, 0);
        fprintf(fp, "\n");
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void salvar_dados_naves_arq_csv(aeronave_t *inicio, char *nome)
{
    FILE *fp = NULL;

    fp = fopen(nome, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome);
        return;
    }

    fprintf(fp, "IDENTIFICAÇÃO;MODELO;FABRICANTE;MATRÍCULA;ANO DE FABRICAÇÃO;TIPO;NÚMERO DE PASSAGEIROS;SITUAÇÃO;TRIPULAÇÃO NECESSÁRIA");
    while (inicio) {
        fprintf(fp, "%i;%s;%s;%s;%i;%s;%i;%s;%i\n", inicio->Identificacao, inicio->Modelo, *(fabricantes_Nave + inicio->Fabricante), inicio->Matricula, 
            inicio->Ano_fabricacao, *(tipo_Nave + inicio->Tipo), inicio->Numero_passageiros, *(situacao_Nave + inicio->Situacao), inicio->Tripulacao_necessaria);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void salvar_dados_rotas_arq_csv(rotas_t *inicio, char *nome)
{
    FILE *fp = NULL;

    fp = fopen(nome, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome);
        return;
    }

    fprintf(fp, "CÓDIGO;DATA;HORA;ORIGEM;DESTINO;TEMPO ESTIMADO;COMBUSTÍVEL NECESSÁRIO;QUANTIDADE DE PASSAGEIROS;CARGA ÚTIL;MEMBROS TRIPULAÇÃO; AERONAVE ALOCADA");
    while (inicio) {
        fprintf(fp, "%i;%i/%i/%i;%i:%i:%i;%s;%s;%i:%i:%i;%.2f;%i;%.2f;%s;%i\n", inicio->Codigo, inicio->Data.Dia, inicio->Data.Mes, inicio->Data.Ano, inicio->Horario.Hora, inicio->Horario.Minuto, inicio->Horario.Segundo, inicio->Local_partida, inicio->Local_destino, inicio->Tempo_estimado_voo.Hora, inicio->Tempo_estimado_voo.Minuto, inicio->Tempo_estimado_voo.Segundo, inicio->Combustivel_necessario, inicio->Quantidade_passageiros, inicio->Quantidade_carga, "Dados Imcompatíveis", inicio->Aeronave_alocada);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void salvar_dados_naves_arq_html(aeronave_t *inicio, char *nome)
{
    FILE *fp = NULL;

    fp = fopen(nome, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome);
        return;
    }

    fprintf(fp, "<HTML> <HEAD> <TITLE> RELATORIO DE NAVES </TITLE> </HEAD> <BODY> \n");
    fprintf(fp, "<TABLE border = '1'> <TR> <TH> IDENTIFICAÇÃO </TH> <TH> MODELO </TH> <TH> FABRICANTE </TH> <TH> MATRÍCULA </TH> <TH> ANO DE FABRICAÇÃO 
        </TH> <TH> TIPO </TH> <TH> NÚMERO DE PASSAGEIROS </TH> <TH> SITUAÇÃO </TH> <TH> TRIPULAÇÃO NECESSÁRIA </TH> </TR>\n");
    while (inicio) {
        fprintf(fp, "<TR> <TD> %i </TD> <TD %s </TD> <TD> %s </TD> <TD> %s </TD> <TD> %i </TD> <TD> %s </TD> <TD> %i </TD> <TD> %s </TD> <TD> %i</TD> </TR>\n", 
            inicio->Identificacao, inicio->Modelo, *(fabricantes_Nave + inicio->Fabricante), inicio->Matricula, inicio->Ano_fabricacao, 
            *(tipo_Nave + inicio->Tipo), inicio->Numero_passageiros, *(situacao_Nave + inicio->Situacao), inicio->Tripulacao_necessaria);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}

void salvar_dados_rotas_arq_html(rotas_t *inicio, char *nome)
{
    FILE *fp = NULL;

    fp = fopen(nome, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome);
        return;
    }

    fprintf(fp, "<HTML> <HEAD> <TITLE> RELATORIO DE ROTAS </TITLE> </HEAD> <BODY> \n");
    fprintf(fp, "<TABLE border = '1'> <TR> <TH> CÓDIGO </TH> <TH> DATA </TH> <TH> HORA </TH> <TH> ORIGEM </TH> <TH> DESTINO 
        </TH> <TH> TEMPO ESTIMADO </TH> <TH> COMBUSTÍVEL NECESSÁRIO </TH> <TH> QUANTIDADE DE PASSAGEIROS </TH> <TH> CARGA ÚTIL </TH> <TH>
        MEMBROS TRIPULAÇÃO </TH> <TH>  AERONAVE ALOCADA </TH> </TR>\n");
    while (inicio) {
        fprintf(fp, "<TR> <TD> %i </TD> <TD %i/%i/%i </TD> <TD %i:%i:%i </TD> <TD %s </TD> <TD %s </TD> <TD %i:%i:%i</TD> <TD %.2f </TD> <TD>
        %i </TD> <TD %.2f </TD> <TD %s </TD> <TD %i </TD> </TR>\n", inicio->Codigo, inicio->Data.Dia, inicio->Data.Mes, inicio->Data.Ano,
        inicio->Horario.Hora, inicio->Horario.Minuto, inicio->Horario.Segundo, inicio->Local_partida, inicio->Local_destino, inicio->Tempo_estimado_voo.Hora,
        inicio->Tempo_estimado_voo.Minuto, inicio->Tempo_estimado_voo.Segundo, inicio->Combustivel_necessario, inicio->Quantidade_passageiros
        inicio->Quantidade_carga, "Dados Imcompatíveis", inicio->Aeronave_alocada);
        inicio = inicio->Proximo;
    }

    fclose(fp);
}