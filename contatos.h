
//definindo o tamanho maximo do array
#define MAX_CONTATOS 255 

typedef struct {//definindo as variaveis que vamo pedir na função
    char nome[10];
    char sobrenome[10];
    char telefone[10];
    char email[20];
} CONTATO;//definindo o struct

void criando_contatos(CONTATO[], int*);//função para criar contato, com os parametros das variavei e da posição
void salvar(CONTATO[], int*);
void deletar(CONTATO[], int*);
void clearBuffer();//chamando função limpar buffer










