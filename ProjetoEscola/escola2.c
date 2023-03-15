#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
#define SUCESSO -1
#define INVALIDO -2
#define LISTA_CHEIA -3

//===========================================================================//
typedef struct cads_al {
    char nome [50];
    char sexo;
    char cpf[12];
    int matricula;
    int dia, mes, ano;
    }aluno;
//===========================================================================//
int menu_principal();
int cadastro_aluno (aluno aluno[],int qtdAluno);
int main(void) {
  int opcao=1;

  int qtdAluno=0;
  aluno aluno[TAM];
  while(opcao!=0){
    int aluno [TAM];
    
    opcao= menu_principal();

    switch (opcao){
      case 0:{ 
        printf("Encerrando programa\n");
        break;}
      case 1:{
        int opcaoAluno = 1;
        while (opcaoAluno != 0){
          printf("==================== Aluno ====================\n");
          printf(" [0] - Voltar\n");
          printf(" [1] - Cadastrar Aluno\n");
          printf(" [2] - Atualizar Aluno\n");
          printf(" [3] - Excluir Aluno\n");
          printf(" [4] - Listar Aluno\n");
          scanf("%d",&opcaoAluno);
          switch (opcaoAluno){
            case 0:{
              break;
            }
            case 1:{
              int cadastro = cadastro_aluno (aluno,qtdAluno);
              if(cadastro == SUCESSO)
                qtdAluno++;
              break;
            }
          }
        }
        break;}
      case 2:{printf("==================== Professor ====================\n");
        break;}
      case 3:{printf("==================== Disciplina ====================\n");
        break;}
      default: printf("Opção Invalida\n");
      }
    }
  return 0;
}
int menu_principal(){
  int opcao;
  printf("==================== Projeto Escola ====================\n");
  printf(" [0] - Sair\n");
  printf(" [1] - Aluno\n");
  printf(" [2] - Professor\n");
  printf(" [3] - Disciplina\n");

  scanf("%d",&opcao);
  
  return opcao;
  }
int cadastro_aluno (aluno aluno[],int qtdAluno){
  printf("==================== Cadastro Aluno ====================\n");
  if (qtdAluno == TAM){
    return LISTA_CHEIA;
  }
  else {
    printf("Digite a matricula\n");
    scanf("%d",&aluno[qtdAluno].matricula);
    printf("Digite o nome\n");
    getchar();
    //char buffer[100];
    //fgets(buffer,100,stdin);
    
    fgets(aluno[qtdAluno].nome, 50, stdin); 
    size_t ln = strlen(aluno[qtdAluno].nome) - 1;
    if (aluno[qtdAluno].nome[ln] == '\n')
        aluno[qtdAluno].nome[ln] = '\0';
     printf("Digite o cpf \n");
    fgets(aluno[qtdAluno].cpf,12,stdin);
    puts(aluno[qtdAluno].cpf);
   
    return SUCESSO;
  }
}
