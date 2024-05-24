
//definindo o tamanho maximo do array
#define MAX_CONTATOS 255 

typedef struct {//definindo as variaveis que vamo pedir na função
    char nome[10];
    char sobrenome[10];
    char telefone[10];
    char email[20];
} CONTATO;//definindo o struct

typedef struct {//definindo as variaveis que vamo pedir na função
    char nome[10];
    char sobrenome[10];
    char telefone[10];
    char email[20];
} CONT_TRABALHO;//definindo o struct
void criando_contatos(CONTATO[], int*);//função para criar contato
void salvar(CONTATO[], int*);
void deletar(CONTATO[], int*);
void carregar(CONTATO[], int*);
void trabalho(CONT_TRABALHO[], int*);
void alterar_dados(CONTATO[], int*);
void listar(CONTATO[], int*);
void deletar_trab(CONT_TRABALHO[], int*);
void clearBuffer();//chamando função limpar buffer










