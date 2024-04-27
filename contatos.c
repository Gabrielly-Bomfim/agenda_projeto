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
    salvar( CONTATOS_LIMITE, *posicao);

  
}


void salvar(CONTATO CONTATOS_LIMITE[], int *posicao){//função salvar os contatos
  FILE *cont = fopen("contatos.bin", "wb");//abrindo o arquivo
      if(cont == 0){//verificando se existe
        printf("--------Erro ---------\n");
        return;
      }
  
      int agen = fwrite(CONTATOS_LIMITE, sizeof(CONTATO), posicao, cont);//escrevendo o contato
      if (agen == 0) {//erro ao salvar 
          printf("---------Erro: Salvar-------\n");
          fclose(cont);
          return;
      }
     
      agen = fwrite(&posicao, sizeof(int), 1, cont);//escrevendo a posição
      if (agen == 0) {//vendo se foi salva
          printf("---------Erro: Salvar-------\n");
          fclose(cont);
          return;
      }
      if(fclose(cont) != 0 ){//verificando o erro ao fechar
        printf("---------Erro: Fechar-------\n");  
        return;
      }
}

void deletar(CONTATO CONTATOS_LIMITE[], int *posicao){//funçao deletar 
  
  printf("**********Deletar contato**********\n");
  
  if(*posicao == 0){//verificando se tem contatos salvos
      printf("-------------Não há contatos salvos-------------\n");
      return;//retornando erro
    }
  //verificando o numero a ser deletado 
  int numero;
  printf("Qual o numero que vai ser deletado:");
  scanf("%d", &numero);//pegando o numero telefonico
  //limando o buffer
  clearBuffer();
  if(numero<*posicao || numero <0){//verificando se o numero é invalido
    printf("-------------Numero invalido-------------\n");
    return;//retornando erros 
  }
  
  for(int n = numero; n >= *posicao - 1; n++){//percorrendo o array
    strcpy(CONTATOS_LIMITE[n].nome, CONTATOS_LIMITE[n+1].nome);//deletando o nome 
    strcpy(CONTATOS_LIMITE[n].sobrenome, CONTATOS_LIMITE[n+1].sobrenome);//deletando o sobrenome
    strcpy(CONTATOS_LIMITE[n].telefone, CONTATOS_LIMITE[n+1].telefone);//deletando o telefone
    strcpy(CONTATOS_LIMITE[n].email, CONTATOS_LIMITE[n+1].email);
    
  }
  *posicao = *posicao - 1;
  carregar(CONTATOS_LIMITE, *posicao);
  
  
}

void carregar(CONTATO CONTATOS_LIMITE[], int *posicao){
  FILE *cont = fopen("contatos.bin", "rb");
  if (cont == NULL){
    printf("--------ERRO--------");
    return;
  }
  
  int agen = fread(CONTATOS_LIMITE, MAX_CONTATOS, sizeof(CONTATO), cont); 
  if (agen < MAX_CONTATOS){
    printf("--------ERRO--------");
    fclose(cont);
    return;
  }

  agen = fread(posicao, sizeof(int), 1, cont);

  if(agen < 1){
    printf("---Erro ao ler---");
    fclose(cont);
  }
  if(fclose(cont)){
    printf("----erro ao fechaar-----");
  }
}

