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
  typedef struct{
    char nome [50];
    char sexo;
    int matricula;
    int cpf;
    int dia, mes, ano;
  }cads_prof;
//===========================================================================//
  typedef struct{
    char nome [50];
    char prof[50];
    int semestre;
    int cod;
  }cads_mat;
//===========================================================================//
  typedef struct{
    char nome [50];
  }lista_aluno;
//===========================================================================//
int main(void) {
  int op1=1,op2=1,i;
  cads_al aluno[TAM];
  cads_prof prof[TAM];
  cads_mat mat[TAM];

   printf("________ Projeto Escola ________\n ");
  while(op1!=0){
    printf(" [0] - Sair\n");
    printf(" [1] - Aluno\n");
    printf(" [2] - Professor\n");
    printf(" [3] - Disciplina\n");

    scanf("%d",&op1);
    
    switch (op1){
      case 0:{ 
        printf("Encerrando programa");
        break;}
      case 1:{
        printf("_____ Aluno _____\n"):
        printf(" [1] - Cadastrar\n");
        printf(" [2] - Atualizar\n");
        printf(" [3] - Excluir\n");
        printf(" [4] - Listar alunos\n");
        
        scanf("%d",&op2);
        switch(op2){
          case 1:{ 
            
          }
        }
        break;}
      case 2:{
         printf("_____ Professor _____\n");
         printf(" [0] - Sair\n");
         printf(" [1] - Cadastrar\n");
         printf(" [2] - Listar professor\n");
         printf(" [3] - Excluir\n");
        break;
      }
      case 3:{
        break;
      }
        default: printf("opção invalida\n");
    }
  }
  return 0;
}