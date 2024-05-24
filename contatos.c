#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int validar_email(char *email) {
  int tam = strlen(email);
  int arroba = 0;
  int ponto = 0;

  for (int i = 0; i < tam; i++) {
      char c = email[i];

      if (c == '@') {
          if (i >= 3) {
              arroba = 1;
          }
      }
      if (c == '.') {
          if (i < tam - 3) {
              ponto = 1;
          }
      }
  }

  if (arroba && ponto) {
      printf("cadastrado!!\n");
      return 1;
  } else {
      printf("Email inválido!\n");
      return 0;
  }
}
int validar_telefone(CONTATO CONTATOS_LIMITE[], int *posicao, char *telefone) {

    for (int i = 0; i < *posicao; i++) {
        if (strcmp(telefone, CONTATOS_LIMITE[i].telefone) == 0) {
            printf("Telefone já cadastrado!\n Não pode ser cadastrado\n");
            return 0;
        }
    }
    return 1;
}
void criando_contatos(CONTATO CONTATOS_LIMITE[], int *posicao) {
  if (*posicao >= MAX_CONTATOS) {
      printf("Limite de contatos atingido.\n");
  } else {
      printf("\n\n*******CRIE SEU CONTATO*******\n");
      printf("Digite o nome do contato:\n ");
      scanf("%s", CONTATOS_LIMITE[*posicao].nome);
      clearBuffer();

      printf("Digite o sobrenome do contato:\n ");
      scanf("%s", CONTATOS_LIMITE[*posicao].sobrenome);
      clearBuffer();

      printf("Digite o telefone do contato:\n ");
      scanf("%s", CONTATOS_LIMITE[*posicao].telefone);
      clearBuffer();
      int telefone_valido = validar_telefone(CONTATOS_LIMITE, posicao, CONTATOS_LIMITE[*posicao].telefone); 

      printf("Digite o email do contato:\n ");
      scanf("%s", CONTATOS_LIMITE[*posicao].email);
      int email_valido = validar_email(CONTATOS_LIMITE[*posicao].email); 
      clearBuffer();

     if (validar_email(CONTATOS_LIMITE[*posicao].email) && validar_telefone(CONTATOS_LIMITE, posicao, CONTATOS_LIMITE[*posicao].telefone)) {
                *posicao = *posicao + 1;
                salvar(CONTATOS_LIMITE, posicao);
            }
        }
    }

void salvar(CONTATO CONTATOS_LIMITE[], int *posicao) {
  FILE *cont = fopen("contatos.bin", "wb");
  if (cont == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return;
  }

  int agen = fwrite(CONTATOS_LIMITE, sizeof(CONTATO), *posicao, cont);
  if (agen == 0) {
      printf("Erro ao salvar os contatos.\n");
      fclose(cont);
      return;
  }

  agen = fwrite(posicao, sizeof(int), 1, cont);
  if (agen == 0) {
      printf("Erro ao salvar a posição.\n");
      fclose(cont);
      return;
  }

  if (fclose(cont) != 0) {
      printf("Erro ao fechar o arquivo.\n");
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
}

void alterar_dados(CONTATO CONTATOS_LIMITE[], int *posicao) {
  
    int pos;
    printf("Digite a posição do contato que deseja alterar:\n");
    scanf("%d", &pos);
    clearBuffer();

    if (pos < 1 || pos > *posicao) {
        printf("Índice inválido.\n");
        return;
    }

    printf("\nDigite o novo nome do contato:\n");
    scanf("%s", CONTATOS_LIMITE[pos - 1].nome);
    clearBuffer();

    printf("Digite o novo sobrenome do contato:\n");
    scanf("%s", CONTATOS_LIMITE[pos - 1].sobrenome);
    clearBuffer();

    printf("Digite o novo telefone do contato:\n");
    scanf("%s", CONTATOS_LIMITE[pos - 1].telefone);
    clearBuffer();

    printf("Digite o novo email do contato:\n");
    scanf("%s", CONTATOS_LIMITE[pos - 1].email);
    clearBuffer();

    printf("Contato alterado com sucesso!\n");
    salvar(CONTATOS_LIMITE, posicao);
}
//fim
