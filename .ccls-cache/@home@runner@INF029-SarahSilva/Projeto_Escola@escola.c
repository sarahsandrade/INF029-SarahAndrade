#include <stdio.h>
#include <string.h>
#define TAM 5
int main(void) {

  typedef struct {
    char nome[50];
    char sexo;
    int dia, mes, ano;
    int matricula;
    int cpf;

  } alunos;
  struct prof {
    char nome[50];
    char sexo;
    int dia, mes, ano;
    int matricula;
    int cpf;
  };

  struct matr {
    char nome[50];
    char prof[50];
    int semes;
    int cod;
  };
  alunos aluno[TAM];
  aluno[0].dia = 3;
  printf("%d", aluno[0].dia);

  return 0;
}