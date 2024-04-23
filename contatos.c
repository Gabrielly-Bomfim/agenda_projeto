//contatos.c = funções 
#include <stdio.h>//inicio

void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
