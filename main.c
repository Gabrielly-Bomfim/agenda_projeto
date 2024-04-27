#include <stdio.h>
#include "contatos.h"

int main() {
    int posicao = 0; //variavel da posição 

    
    CONTATO CONTATOS_LIMITE[MAX_CONTATOS];//array 

    int num_escolhido;//variavel da opção escolhida

    do {//inicio do loop
        printf("\n***BEM-VINDO À AGENDA***\n");
        printf("1 - Cadastrar contato\n");//opções
        printf("2 - Listar contatos\n");//opções
        printf("3 - Deletar contato\n");//opções
        printf("0 - Sair\n");//opções
        scanf("%d", &num_escolhido);//verificando a opção escolhida
        clearBuffer();//limpando o buffer

        if (num_escolhido == 1) {//Se a opção for 1
            printf("---------Cadastrar contato----------\n");
            criando_contatos(CONTATOS_LIMITE, &posicao); // chamando a função da contatos.c 
          
        } else if (num_escolhido == 2) {//Se a opção for 2
            printf("*************Listar contatos*************\n");
            printf("*************Listar contatos*************\n");   
            listar(CONTATOS_LIMITE, &posicao);
          
        } else if (num_escolhido == 3) {//Se a opção for 3
            printf("************Deletar contatos*************\n");
            deletar(CONTATOS_LIMITE, &posicao);
          
        } else if (num_escolhido == 0) {//Se a opção for 0
            printf("Saindo...\n");
        } else {//Se não for nenhuma das opções 
            printf("Opção inválida.\n");
        }
    } while (num_escolhido != 0);

    return 0;
}