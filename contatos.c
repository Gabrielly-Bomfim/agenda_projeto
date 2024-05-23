#include <stdio.h>
#include "contatos.h"//incluindo o contatos.h

void clearBuffer() {//função para limpar a quebra de linha e o fim do contato
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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

void deletar(CONTATO CONTATOS_LIMITE[], int *posicao){
    //apagar clientes
      if(*posicao == 0){
          printf("-------------Não há contatos salvos-------------\n");
          return;
        }

      int telefone;
      printf("Digite o telefone do cliente: ");
      scanf("%d", &telefone);

       clearBuffer();
      if(telefone<*posicao || telefone <0){
        printf("ERRO\n");
        return;
    }
    
      for (int n = telefone; n < *posicao - 1; n++) {
          strcpy(CONTATOS_LIMITE[n].nome, CONTATOS_LIMITE[n+1].nome);
          strcpy(CONTATOS_LIMITE[n].sobrenome, CONTATOS_LIMITE[n+1].sobrenome);
          strcpy(CONTATOS_LIMITE[n].telefone, CONTATOS_LIMITE[n+1].telefone);
          strcpy(CONTATOS_LIMITE[n].email, CONTATOS_LIMITE[n+1].email);
         
      }

      (*posicao)--;
      *posicao = *posicao - 1;
    FILE *arquivo = fopen("contatos.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;}
    fclose(arquivo);
}

void listar(CONTATO CONTATOS_LIMITE[], int *posicao){//FUNÇÃO LISTAR 
  if(*posicao == 0){//verificando se a posição é 0 
    printf("-------------ERRO-------------\n"); 
    return;//retornando erro 
  } for(int i=0; i<*posicao; i++){//percorrendo o array
        printf("\nNome: %s\n", CONTATOS_LIMITE[i].nome);//listando o nome     
        printf("Sobrenome: %s\n", CONTATOS_LIMITE[i].sobrenome); //listando o sobrenome 
    printf("Telefone: %s\n", CONTATOS_LIMITE[i].telefone);//listando o telefone 
    printf("Email: %s\n", CONTATOS_LIMITE[i].email);//listando o email
    printf("------------------------------------------------"); } 
}//fim
