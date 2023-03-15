#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
//===========================================================================//
typedef struct {
    char nome [50];
    char sexo;
    char cpf[11];
    int matricula;
    int dia, mes, ano;
    }cads_al;
//===========================================================================//
int menu_principal();

int main(void) {
  int op1=1;
  int ListaAluno[TAM];

  while(op1!=0){

    op1= menu_principal();

    switch (op1){
      case 0:{ 
        printf("Encerrando programa");
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
          switch (opcaoAluno)
            case 0:{
              break;}
            case 1:{
              
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
void CadastroAluno (){
  
  
}