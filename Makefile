CC = gcc
SRC = ./src
OBJS = ./objs
TARGET = Fleet_Manegement
LIMPAR = rm

all: objetos
	$(CC) $(OBJS)/Arquivos.o $(OBJS)/Auxiliar.o $(OBJS)/Cadastro.o $(OBJS)/Gerenciamento.o $(OBJS)/Menus.o $(OBJS)/Relatorio.o $(OBJS)/Main.o -o $(TARGET)
	

objetos:
	$(CC) -c $(SRC)/Arquivos.c -o $(OBJS)/Arquivos.o
	$(CC) -c $(SRC)/Auxiliar.c -o $(OBJS)/Auxiliar.o
	$(CC) -c $(SRC)/Cadastro.c -o $(OBJS)/Cadastro.o
	$(CC) -c $(SRC)/Gerenciamento.c -o $(OBJS)/Gerenciamento.o
	$(CC) -c $(SRC)/Menus.c -o $(OBJS)/Menus.o
	$(CC) -c $(SRC)/Relatorio.c -o $(OBJS)/Relatorio.o
	$(CC) -c main.c -o $(OBJS)/main.o


clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)