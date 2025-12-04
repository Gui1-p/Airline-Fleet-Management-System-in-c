# Airline-Fleet-Management-System-in-c

![Linguagem C](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Padrão](https://img.shields.io/badge/Padrão-C99-lightgrey.svg)


## 📖 Sobre o Projeto
Este projeto/trabalho é um sistema de gerenciamento de frota aérea para uma nova CIA, desenvolvido em C. O objetivo é aplicar conceitos de programação procedural, structs, ponteiros e modularização para criar um sistema de gerenciamento completo.

## ✨ Funcionalidades (Features)
  - Cadastro de aeronaves;
  - Cadastro de rotas;
  - Relatório de aeronaves;
  - Busca de aeronave por prefixo;
  - Listagem de aeronaves por fabricante;
  - Listagem de aeronaves por tipo de avião (carga ou passageiro);
  - Listagem de aeronaves por modelo;
  - Listagem de aeronaves por ano de fabricação;
  - Listagem de aeronaves por situação (em operação ou em manutenção);
  - Consultar rota por data;
  - Listagem de rotas por destino;
  - Listagem de rotas por origem;
  - Percentual de voos realizados para um determinado destino em um intervalo de datas;
  - Percentual de voos realizados por aeronave;
  - Consumo de combustível total em um intervalo de datas;
  - Mostar rota com maior número de passageiros;
  - Mostar rota com menor número de passageiros;
  - Quantidade de vezes que uma determinada aeronave entrou em manutenção.


## 🚀 Como Compilar e Executar

Este projeto possui um `Makefile` configurado para facilitar a compilação.

### Pré-requisitos
* Compilador GCC instalado
* Sistema operacional Linux (ou WSL no Windows)


## 🛠️ Tecnologias e Conceitos Utilizados

* **Linguagem C:** Padrão C99.
* **Modularização:** Separação clara entre interface (`.h`) e implementação (`.c`).
* **Makefiles:** Automação de compilação.
* **Estruturas de Dados:** Uso intensivo de `structs` e `typedefs` para modelagem de dados.
* **Gerenciamento de Memória:** Alocação dinâmica (Listas Encadeadas) para gerenciamento eficiente da frota.
* **Persistência de Dados:** Manipulação de arquivos binários e texto para salvar/carregar dados.


## 📂 Estrutura do Projeto

* `src/`: Contém o código-fonte (`.c`) das implementações.
* `include/`: Contém os cabeçalhos (`.h`) e definições de tipos.
* `objs/`: Diretório para os arquivos objeto compilados.
* `Makefile`: Script de compilação automatizada.
