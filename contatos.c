#include <stdio.h>
#include "contatos.h"//incluindo o contatos.h

void clearBuffer() {//função para limpar a quebra de linha e o fim do contato
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void criando_contatos(CONTATO CONTATOS_LIMITE[], int *posicao) {//função para criar contatos, com o parametro de posição e as variaveis do struct da .h
  
    if (*posicao >= MAX_CONTATOS){//verificando se a posição é maior que o limite
      printf("Limite de contatos atingido.\n");//se sim, não é possivel continuar
    }else{// caso não seja maior 
    printf("\n\n*******CRIE SEU CONTATO*******\n");
    printf("Digite o nome do contato:\n ");
    scanf("%s", CONTATOS_LIMITE[*posicao].nome);//pegando o nome do contato
    clearBuffer();

    printf("Digite o sobrenome do contato:\n ");
    scanf("%s", &CONTATOS_LIMITE[*posicao].sobrenome);//pegando o sobrenome 
    clearBuffer();
    
    printf("Digite o telefone do contato:\n ");
    scanf("%s", &CONTATOS_LIMITE[*posicao].telefone);//pegando o telefone
    clearBuffer();
    
    printf("Digite o email do contato:\n ");
    scanf("%s", &CONTATOS_LIMITE[*posicao].email);//pegando o email 
    clearBuffer();
    
    *posicao = *posicao + 1; }//atualizando a posição do contato 
}