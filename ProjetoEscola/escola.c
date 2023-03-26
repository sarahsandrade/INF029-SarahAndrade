#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 500
#define ATIVO 1
#define INEXISTENTE 2
#define INATIVO 0
#define SUCESSO -1
#define INVALIDO -2
#define LISTA_CHEIA -3
//===========================================================================//
typedef struct listagem {
  char nome[50];
  int dia, mes, ano;
} listagem;

typedef struct cads_al {
  char nome[50];
  char sexo;
  char cpf[12];
  int matricula;
  int dia, mes, ano;
} aluno;
typedef struct cads_pr {
  char nome[50];
  char sexo;
  char cpf[12];
  int matricula;
  int dia, mes, ano;
} professor;
typedef struct cads_dis {
  char nome [50];
  int professor;
  int semestre;
  int codigo;
  int alunos [50];
  int contAluno;
} disciplina;
//===========================================================================//
int menu_principal();
int cadastro_aluno(aluno aluno[], int qtdAluno);
int validacao_nascimento(int dia, int mes, int ano);
int listagemMenu();
void listarNomes_aluno (aluno listaAluno[],int qtdAluno);
void listarDatas_aluno (aluno listaAluno[],int qtdAluno);
int excluirAluno (aluno listaAluno[],int qtdAluno);
int atualizarAluno (aluno listaAluno[],int qtdAluno);
int cadastro_Professor(professor listaProfessor[], int qtdProf);
void listarDatas_Professor(professor listaProfessor[],int qtdProf);
void listarNomes_Professor(professor listaProfessor[],int qtdProf);
int excluirProfessor (professor listaProfessor[],int qtdProf);
int atualizarProfessor (professor listaProfessor[],int qtdProf);
void lista(aluno listaAluno[],int qtdAluno,professor listaProfessor[], int qtdprof);
int cadastro_disciplina (disciplina listaDisciplina[], int qtdDisc,professor listaProfessor[], int qtdProf);
int excluirDisciplina (disciplina listaDisciplina[],int qtdDisc);
int atualizarDisciplina (disciplina listaDisciplina[], int qtdDisc,professor listaProfessor[], int qtdProf);
int menuDisciplina ();
void listar_disciplinas(disciplina listaDisciplina[],int qtdDisc);
void listar_1disciplina(disciplina listaDisciplina[],int qtdDisc);
void listar_40disciplina(disciplina listaDisciplina[],int qtdDisc);
int disciplina_cadsAluno(disciplina listaDisciplina[],int qtdDisc,aluno listaAluno[],int qtdAluno);
void listarAlunos_disciplina(disciplina listaDisciplina[],int qtdDisc,aluno listaAluno[],int qtdAluno);
//===========================================================================//
int main(void) {
  int opcaoMenu = 1;
  int qtdAluno = 0;
  int qtdDisc = 0;
  int qtdProf = 0;
  
  aluno listaAluno[TAM] = {0};
  professor listaProfessor[TAM]= {0};
  disciplina listaDisciplina[TAM] = {0};
  while (opcaoMenu != 0) {

    opcaoMenu = menu_principal();

    switch (opcaoMenu) {
    case 0: {
      printf("Encerrando programa\n");
      break;
    }
    case 1: {
      int opcaoAluno = 1;
      while (opcaoAluno != 0) {
        printf("==================== Aluno ====================\n");
        printf(" [0] - Voltar\n");
        printf(" [1] - Cadastrar Aluno\n");
        printf(" [2] - Atualizar Aluno\n");
        printf(" [3] - Excluir Aluno\n");
        printf(" [4] - Listar Aluno\n");
        scanf("%d", &opcaoAluno);
        switch (opcaoAluno) {
        case 0:
          break;
        case 1: {
          int cadastro = cadastro_aluno(listaAluno, qtdAluno);
          if (cadastro == SUCESSO) {
            qtdAluno++;
            printf("Cadastro feito com sucesso \n");

          } else {
            printf("Cadastro Invalido \n");
          }
          break;
        }
        case 2: {
          int atualiza = atualizarAluno (listaAluno,qtdAluno);
          if(atualiza == SUCESSO){
            printf("Aluno atualizado com sucesso\n");
          }
          else{
            printf("Matricula Inexistente\n");
          }
          break;
        }
        case 3: {
          int excluir = excluirAluno (listaAluno,qtdAluno);
          if(excluir == SUCESSO){
            qtdAluno--;
            printf("Aluno excluido com sucesso\n");
          }
          else{
            printf("Matricula Inexistente\n");
          }
          break;
        }
        case 4: {
          int opcao = listagemMenu();
          switch (opcao) {
          case 0:
            break;
          case 1: {
            for (int i = 0; i < qtdAluno; i++) {
              printf("Matricula: %d\n", listaAluno[i].matricula);
            }
            break;
          }
          case 2: {
            char sexo;
            printf(" [M] - Masculino\n");
            printf(" [F] - Feminino\n");
            getchar();
            scanf("%c", &sexo);
            for (int i= 0; i < qtdAluno; i++) {
              if (listaAluno[i].sexo == sexo){
                puts(listaAluno[i].nome);
              }
            }
            break;
          }
          case 3: {
            listarNomes_aluno (listaAluno,qtdAluno);
            break;
          }
          case 4: {
            listarDatas_aluno (listaAluno, qtdAluno);
            break;
          }
          case 5: {
            int mes;
            printf("Digite o mes: ");
            scanf("%d", &mes);
            printf("============== Aniversariantes do mes ===============\n");
            int i;
            for (i = 0; i < qtdAluno; i++) {
              if (listaAluno[i].mes == mes) {
                  printf("%d/%d: ", listaAluno[i].dia, listaAluno[i].mes);
                  puts(listaAluno[i].nome);
              }
            }
            break;
          }
          default: printf("Opção Invalida\n");
          }
          break;
        }
        }
      }
      break;
    }
    case 2: {
      int opcaoProfessor = 1;
      while(opcaoProfessor != 0){
      printf("==================== Professor ====================\n");
      printf(" [0] - Voltar\n");
      printf(" [1] - Cadastrar Professor\n");
      printf(" [2] - Excluir Professor\n");
      printf(" [3] - Atualizar Professor\n");
      printf(" [4] - Listar Professor\n");
      scanf("%d",&opcaoProfessor);
      switch (opcaoProfessor){
      case 0 : break;
      case 1:{
        int cadastro =cadastro_Professor(listaProfessor, qtdProf);
        if (cadastro == SUCESSO) {
          qtdProf++;
          printf("Cadastro feito com sucesso \n");
          puts(listaProfessor[qtdProf].nome);
        }
        else{
          printf("Cadastro Invalido \n");
        }
        break;
      }
      case 2:{
        int excluir = excluirProfessor (listaProfessor,qtdProf);
        if(excluir == SUCESSO){
            qtdAluno--;
            printf("Professor excluido com sucesso\n");
          }
          else{
            printf("Matricula Inexistente\n");
          }
        break;
      }
      case 3:{
        int atualiza = atualizarProfessor (listaProfessor,qtdProf);
        if(atualiza == SUCESSO){
          printf("Professor atualizado com sucesso\n");
        }
        else{
          printf("Matricula Inexistente\n");
        }
        break;
      }  
      case 4:{
        int opcao = listagemMenu ();
        switch (opcao) {
          case 0: break;
          case 1: {
            for (int i = 0; i < qtdProf; i++) {
              printf("Matricula: %d\n", listaProfessor[i].matricula);
            }
            break;
          }
          case 2: {
            char sexo;
            printf(" [M] - Masculino\n");
            printf(" [F] - Feminino\n");
            getchar();
            scanf("%c", &sexo);
            for (int i= 0; i < qtdProf; i++) {
              if (listaProfessor[i].sexo == sexo){
                puts(listaProfessor[i].nome);
              }
            }
            break;
          }
          case 3: {
            listarNomes_Professor (listaProfessor,qtdProf);
            break;
          }
          case 4: {
            listarDatas_Professor (listaProfessor, qtdProf);
            break;
          }
          case 5:{
            int mes;
            printf("Digite o mes: ");
            scanf("%d", &mes);
            printf("============== Aniversariantes do mes ===============\n");
            int i;
            for (i = 0; i < qtdProf; i++) {
              if (listaProfessor[i].mes == mes) {
                  printf("%d/%d: ", listaProfessor[i].dia, listaProfessor[i].mes);
                  puts(listaProfessor[i].nome);
              }
            }
            break;
          }
          default: printf("Opção Invalida\n");
          }
          break;
        
        
      }
      }
     }
      break;
  }
    case 3: {
      int opcaodisciplina = 1;
      while(opcaodisciplina != 0){
      printf("==================== Disciplina ====================\n");
      printf(" [0] - Voltar\n");
      printf(" [1] - Cadastrar Disciplina\n");
      printf(" [2] - Excluir Disciplina\n");
      printf(" [3] - Atualizar Disciplina\n");
      printf(" [4] - Listar\n");
      printf(" [5] - Matricular Aluno\n");
      scanf("%d",&opcaodisciplina);

      switch (opcaodisciplina) {
        case 1:{
        int retorno = cadastro_disciplina (listaDisciplina,qtdDisc,listaProfessor,qtdProf);
        if (retorno == SUCESSO) {
            qtdDisc++;
            printf("Cadastro feito com sucesso \n");

          } else {
            printf("Cadastro Invalido \n");
          }
        break;
        }
        case 2:{
          int excluir = excluirDisciplina (listaDisciplina,qtdDisc);
        if(excluir == SUCESSO){
            qtdAluno--;
            printf("Disciplina excluida com sucesso\n");
          }
          else if(excluir == INEXISTENTE){
            printf("Codigo Inexistente\n");
          }
          else if(excluir == INVALIDO){
            printf("Codigo Invalido\n");
          }
          break;}
        case 3:{
          int atualiza =atualizarDisciplina (listaDisciplina, qtdDisc, listaProfessor,qtdProf);
          if(atualiza == SUCESSO){
          printf("Disciplina atualizado com sucesso\n");
        }
        else{
          printf("Codigo Inexistente\n");
        }
          break;}
        case 4:{
          int retorno = menuDisciplina ();
          switch(retorno){
            case 0:break;
            case 1:{
              listar_1disciplina(listaDisciplina,qtdDisc);
              break;}
            case 2:{
              listar_disciplinas(listaDisciplina,qtdDisc);
              break;}
            case 3:{
              listar_40disciplina(listaDisciplina, qtdDisc);
              break;}
            default: printf("Opção Invalida\n");
          }
          break;}
        case 5:{
          int retorno = disciplina_cadsAluno(listaDisciplina,qtdDisc,listaAluno,qtdAluno);
          if(retorno == SUCESSO){
            printf("Matricula feita com sucesso");
          }
          else {printf("Matricula ou codigo Invalido");}
          break;}
        default: printf("Opção Invalida");
      }
      }
      break;
    }
      case 5:{
        lista(listaAluno,qtdAluno,listaProfessor,qtdProf);
      }
    default: printf("Opção Invalida\n");
      }
    }
  return 0;
}

//===========================================================================//

int menu_principal() {
  int opcao;
  printf("==================== Projeto Escola ====================\n");
  printf(" [0] - Sair\n");
  printf(" [1] - Aluno\n");
  printf(" [2] - Professor\n");
  printf(" [3] - Disciplina\n");
  printf("[4] - Encontrar Aluno/Professor\n");

  scanf("%d", &opcao);

  return opcao;
}

//===========================================================================//

int cadastro_aluno(aluno listaAluno[], int qtdAluno) {
  aluno alunoTemp;
  printf("==================== Cadastro Aluno ====================\n");
  if (qtdAluno == TAM)
    return LISTA_CHEIA;

  printf("Digite a matricula\n");
  scanf("%d", &alunoTemp.matricula); 
  printf("Digite o nome\n");
  if (alunoTemp.matricula <= 0)
    return INVALIDO;

  getchar();
  // char buffer[100];
  // fgets(buffer,100,stdin);

  fgets(alunoTemp.nome, 50, stdin);
  size_t ln = strlen(alunoTemp.nome) - 1;
  if (alunoTemp.nome[ln] == '\n')
    alunoTemp.nome[ln] = '\0';

  printf("Digite o cpf \n");
  fgets(alunoTemp.cpf, 12, stdin);
  char buffer[100];

  for (int i = 0; i < 11; i++) {
    if (alunoTemp.cpf[i] < '0' || alunoTemp.cpf[i] > '9')
      return INVALIDO;
  }

  getchar();

  printf("Informe o sexo \n");

  printf("[0] - Masculino\n");
  printf("[1] - Feminino\n");
  int sexo;
  scanf("%d", &sexo);
  switch (sexo) {
  case 0: {
    alunoTemp.sexo = 'M';
    break;
  }
  case 1: {
    alunoTemp.sexo = 'F';
    break;
  }
  default:
    return INVALIDO;
  }
  printf("Data de nascimento\n");

  printf("Digite o ano:");
  scanf("%d", &alunoTemp.ano);

  printf("Digite o mes: ");
  scanf("%d", &alunoTemp.mes);

  printf("Digite o dia: ");
  scanf("%d", &alunoTemp.dia);

  int retorno =
      validacao_nascimento(alunoTemp.dia, alunoTemp.mes, alunoTemp.ano);
  if (retorno == INVALIDO) return INVALIDO;
  
  listaAluno[qtdAluno] = alunoTemp;
  return SUCESSO;
}

//===========================================================================//
int validacao_nascimento(int dia, int mes, int ano) {

  if ((dia < 1 || dia > 31) || (mes < 1 && mes > 12)) {
    return INVALIDO;
  }

  if (dia == 31) {
    if ((mes >= 1 && mes <= 7 && mes % 2 == 0) ||
        (mes >= 8 && mes <= 12 && mes % 2 != 0)) {

      return INVALIDO;
      // meses pares do mes 1 ao mes 7 e impares do 8 ao 12 tem  menos que 31
      // dias
    }
  }
  if (dia == 29 && mes % 4 != 0) {
    return INVALIDO;
    // ano bissextos são divisiveis por 4
  }

  return SUCESSO;
}
//===========================================================================//
int listagemMenu() {
  int opcao;
  printf(" [0] - Sair\n");
  printf(" [1] - Matricula\n");
  printf(" [2] - Listar por sexo\n");
  printf(" [3] - Listar por nome\n");
  printf(" [4] - Listar por data de nascimento\n");
  printf(" [5] - Aniversariantes\n");

  scanf("%d", &opcao);
  return opcao;
}
//===========================================================================//
void listarNomes_aluno (aluno listaAluno[],int qtdAluno){
  listagem lsAluno[TAM];
  int i;
  char menor [50];
  for(i=0;i< qtdAluno;i++){
     strncpy(lsAluno[i].nome, listaAluno[i].nome, 50);
  }
   for(i=0;i< qtdAluno-1;i++){
    strncpy(menor, lsAluno[i].nome, 50);
    int posicao = i;
    for(int j = i+1;j< qtdAluno;j++){
      if(strcmp(lsAluno[j].nome,lsAluno[i].nome) < 0){
        strncpy(menor, lsAluno[j].nome, 50);
        posicao=j;
      }
    }
    strncpy(lsAluno[posicao].nome, lsAluno[i].nome, 50);
    strncpy(lsAluno[i].nome, menor, 50);
   }
   for(i=0;i< qtdAluno;i++){
      puts(lsAluno[i].nome);
     }
  
}
//===========================================================================//
void listarDatas_aluno (aluno listaAluno[],int qtdAluno){
  listagem lsAluno[TAM];
  int i,menorD,menorM,menorA;
  char aux [50];
  for(i=0;i< qtdAluno;i++){
     strncpy(lsAluno[i].nome, listaAluno[i].nome, 50);
     lsAluno[i].dia = listaAluno[i].dia;
     lsAluno[i].mes = listaAluno[i].mes;
     lsAluno[i].ano = listaAluno[i].ano;
  }  
  for(i=0;i <qtdAluno -1; i++){
     menorD = lsAluno[i].dia;
     menorM = lsAluno[i].mes;
     menorA = lsAluno[i].ano;
     strncpy(aux, lsAluno[i].nome, 50);
     int posicao = i;
     for(int j = i+1;j< qtdAluno;j++){
       if(menorA < lsAluno[j].ano ){
        menorD = lsAluno[j].dia;
        menorM = lsAluno[j].mes;
        menorA = lsAluno[j].ano;
        strncpy(aux, lsAluno[j].nome, 50);
        posicao = j;
       }
       if(menorA == lsAluno[i].ano ){
         if(menorM < lsAluno[j].mes || (menorM == lsAluno[j].mes && menorD > lsAluno[j].dia)){
          posicao = j;
          menorD = lsAluno[j].dia;
          menorM = lsAluno[j].mes;
          menorA = lsAluno[j].ano;
          strncpy(aux, lsAluno[j].nome, 50);
          posicao = j;
          }
       }
        lsAluno[posicao].dia = lsAluno[i].dia;
        lsAluno[i].dia = menorD;

        lsAluno[posicao].mes = lsAluno[i].mes;
        lsAluno[i].mes = menorM;

        lsAluno[posicao].ano = lsAluno[i].ano;
        lsAluno[i].ano = menorA;

        strncpy(lsAluno[posicao].nome, lsAluno[i].nome, 50);
        strncpy(lsAluno[i].nome,aux, 50);
     }
  }
   for(i=0;i <qtdAluno; i++){
     printf("%d/%d/%d: ",lsAluno[i].dia, lsAluno[i].mes, lsAluno[i].ano);
     puts(lsAluno[i].nome);
   }
}
//===========================================================================//
int excluirAluno (aluno listaAluno[],int qtdAluno){
  int achou = 0;
  int i;
  printf("==================== Excluir Aluno ====================\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d",&matricula);
  for(i = 0; i < qtdAluno; i ++){
    if(listaAluno[i].matricula == matricula){
      achou = 1;
      break;
    }
  }
  if(achou == 0) return INEXISTENTE;

  else if(achou == 1){
    for(int j= i ; j < qtdAluno;j++){
      listaAluno[j].matricula = listaAluno[j+1].matricula;
      listaAluno[j].sexo = listaAluno[j+1].sexo;
      listaAluno[j].dia = listaAluno[j+1].dia; 
      listaAluno[j].mes = listaAluno[j+1].mes;
      listaAluno[j].ano = listaAluno[j+1].ano;
      strncpy(listaAluno[j].nome,listaAluno[j +1].nome, 50);
      strncpy(listaAluno[j].cpf,listaAluno[j +1].cpf, 12);
    }
    return SUCESSO;
  }
}
//===========================================================================//
int atualizarAluno (aluno listaAluno[],int qtdAluno){
  aluno atualizaAluno;
  int achou = 0;
  int i;
  printf("==================== Atualizar Aluno ====================\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d",&matricula);
  for(i = 0; i < qtdAluno; i ++){
    if(listaAluno[i].matricula == matricula){
      achou = 1;
      break;
    }
  }
  if(achou == 0) return INEXISTENTE;

  else if(achou == 1){
    printf("Digite a nova matricula\n");
    scanf("%d", &atualizaAluno.matricula); 
    if (atualizaAluno.matricula <= 0) return INVALIDO;

    char buffer [100];
    fgets(buffer, 100, stdin);
    printf("Digite o nome\n");
    fgets(atualizaAluno.nome, 50, stdin);
    size_t ln = strlen(atualizaAluno.nome) - 1;
    if (atualizaAluno.nome[ln] == '\n')
      atualizaAluno.nome[ln] = '\0';

    printf("Informe o sexo \n");

    printf("[0] - Masculino\n");
    printf("[1] - Feminino\n");
    int sexo;
    scanf("%d", &sexo);
    switch (sexo) {
    case 0: {
      atualizaAluno.sexo = 'M';
      break;
    }
    case 1: {
      atualizaAluno.sexo = 'F';
      break;
    }
    default:
      return INVALIDO;
    }
    printf("Data de nascimento\n");
  
    printf("Digite o ano:");
    scanf("%d", &atualizaAluno.ano);
  
    printf("Digite o mes: ");
    scanf("%d", &atualizaAluno.mes);
  
    printf("Digite o dia: ");
    scanf("%d", &atualizaAluno.dia);
  
    int retorno = validacao_nascimento(atualizaAluno.dia, atualizaAluno.mes, atualizaAluno.ano);
    if (retorno == INVALIDO) return INVALIDO;
  
    strncpy(atualizaAluno.cpf,listaAluno[i].cpf, 12);
    listaAluno[i] = atualizaAluno;
    return SUCESSO;
  }
}
//===========================================================================//

int cadastro_Professor(professor listaProfessor[], int qtdProf) {
  professor professorTemp;
  printf("==================== Cadastro Professor ====================\n");
  if (qtdProf == TAM)
    return LISTA_CHEIA;

  printf("Digite a matricula\n");
  scanf("%d", &professorTemp.matricula); 
  printf("Digite o nome\n");
  if (professorTemp.matricula <= 0)
    return INVALIDO;

  getchar();
  // char buffer[100];
  // fgets(buffer,100,stdin);

  fgets(professorTemp.nome, 50, stdin);
  size_t ln = strlen(professorTemp.nome) - 1;
  if (professorTemp.nome[ln] == '\n')
    professorTemp.nome[ln] = '\0';

  printf("Digite o cpf \n");
  fgets(professorTemp.cpf, 12, stdin);
  char buffer[100];

  for (int i = 0; i < 11; i++) {
    if (professorTemp.cpf[i] < '0' || professorTemp.cpf[i] > '9')
      return INVALIDO;
  }

  getchar();

  printf("Informe o sexo \n");

  printf("[0] - Masculino\n");
  printf("[1] - Feminino\n");
  int sexo;
  scanf("%d", &sexo);
  switch (sexo) {
  case 0: {
    professorTemp.sexo = 'M';
    break;
  }
  case 1: {
    professorTemp.sexo = 'F';
    break;
  }
  default:
    return INVALIDO;
  }
  printf("Data de nascimento\n");

  printf("Digite o ano:");
  scanf("%d", &professorTemp.ano);

  printf("Digite o mes: ");
  scanf("%d", &professorTemp.mes);

  printf("Digite o dia: ");
  scanf("%d", &professorTemp.dia);

  int retorno = validacao_nascimento(professorTemp.dia, professorTemp.mes, professorTemp.ano);
  if (retorno == INVALIDO){ 
    return INVALIDO;}
  listaProfessor[qtdProf] = professorTemp;
  return SUCESSO;
}
//===========================================================================//
int excluirProfessor (professor listaProfessor[],int qtdProf){
  int achou = 0;
  int i;
  printf("==================== Excluir Professor ====================\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d",&matricula);
  for(i = 0; i < qtdProf; i ++){
    if(listaProfessor[i].matricula == matricula){
      achou = 1;
      break;
    }
  }
  if(achou == 0) return INEXISTENTE;

  else if(achou == 1){
    for(int j= i ; j < qtdProf;j++){
      listaProfessor[j].matricula = listaProfessor[j+1].matricula;
      listaProfessor[j].sexo = listaProfessor[j+1].sexo;
      listaProfessor[j].dia = listaProfessor[j+1].dia; 
      listaProfessor[j].mes = listaProfessor[j+1].mes;
      listaProfessor[j].ano = listaProfessor[j+1].ano;
      strncpy(listaProfessor[j].nome,listaProfessor[j +1].nome, 50);
      strncpy(listaProfessor[j].cpf,listaProfessor[j +1].cpf, 12);
    }
    return SUCESSO;
  }
}
//===========================================================================//

int atualizarProfessor (professor listaProfessor[],int qtdProf){
  professor atualizaProfessor;
  int achou = 0;
  int i;
  printf("==================== Atualizar Professor ====================\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d",&matricula);
  for(i = 0; i < qtdProf; i ++){
    if(listaProfessor[i].matricula == matricula){
      achou = 1;
      break;
    }
  }
  if(achou == 0) return INEXISTENTE;

  else if(achou == 1){
    printf("Digite a nova matricula\n");
    scanf("%d", &atualizaProfessor.matricula); 
    if (atualizaProfessor.matricula <= 0) return INVALIDO;

    char buffer [100];
    fgets(buffer, 100, stdin);
    printf("Digite o nome\n");
    fgets(atualizaProfessor.nome, 50, stdin);
    size_t ln = strlen(atualizaProfessor.nome) - 1;
    if (atualizaProfessor.nome[ln] == '\n')
      atualizaProfessor.nome[ln] = '\0';

    printf("Informe o sexo \n");

    printf("[0] - Masculino\n");
    printf("[1] - Feminino\n");
    int sexo;
    scanf("%d", &sexo);
    switch (sexo) {
    case 0: {
      atualizaProfessor.sexo = 'M';
      break;
    }
    case 1: {
      atualizaProfessor.sexo = 'F';
      break;
    }
    default:
      return INVALIDO;
    }
    printf("Data de nascimento\n");
  
    printf("Digite o ano:");
    scanf("%d", &atualizaProfessor.ano);
  
    printf("Digite o mes: ");
    scanf("%d", &atualizaProfessor.mes);
  
    printf("Digite o dia: ");
    scanf("%d", &atualizaProfessor.dia);
  
    int retorno = validacao_nascimento(atualizaProfessor.dia, atualizaProfessor.mes, atualizaProfessor.ano);
    if (retorno == INVALIDO) return INVALIDO;
  
    strncpy(atualizaProfessor.cpf,listaProfessor[i].cpf, 12);
    listaProfessor [i] = atualizaProfessor;
    return SUCESSO;
  }
}
//===========================================================================//
void listarDatas_Professor(professor listaProfessor[],int qtdProf){
  listagem lsProf[TAM];
  int i,menorD,menorM,menorA;
  char aux [50];
  for(i=0;i< qtdProf;i++){
     strncpy(lsProf[i].nome, listaProfessor[i].nome, 50);
     lsProf[i].dia = listaProfessor[i].dia;
     lsProf[i].mes = listaProfessor[i].mes;
     lsProf[i].ano = listaProfessor[i].ano;
  }  
  for(i=0;i <qtdProf -1; i++){
     menorD = lsProf[i].dia;
     menorM = lsProf[i].mes;
     menorA = lsProf[i].ano;
     strncpy(aux, lsProf[i].nome, 50);
     int posicao = i;
     for(int j = i+1;j< qtdProf;j++){
       if(menorA < lsProf[j].ano ){
        menorD = lsProf[j].dia;
        menorM = lsProf[j].mes;
        menorA = lsProf[j].ano;
        strncpy(aux, lsProf[j].nome, 50);
        posicao = j;
       }
       if(menorA == lsProf[i].ano ){
         if(menorM <lsProf[j].mes || (menorM == lsProf[j].mes && menorD > lsProf[j].dia)){
          posicao = j;
          menorD = lsProf[j].dia;
          menorM = lsProf[j].mes;
          menorA = lsProf[j].ano;
          strncpy(aux, lsProf[j].nome, 50);
          posicao = j;
          }
       }
        lsProf[posicao].dia = lsProf[i].dia;
        lsProf[i].dia = menorD;

        lsProf[posicao].mes = lsProf[i].mes;
        lsProf[i].mes = menorM;

        lsProf[posicao].ano = lsProf[i].ano;
        lsProf[i].ano = menorA;

        strncpy(lsProf[posicao].nome,lsProf[i].nome, 50);
        strncpy(lsProf[i].nome,aux, 50);
     }
  }
   for(i=0;i <qtdProf; i++){
     printf("%d/%d/%d: ",lsProf[i].dia, lsProf[i].mes,lsProf[i].ano);
     puts(lsProf[i].nome);
   }
}
//===========================================================================//

void listarNomes_Professor(professor listaProfessor[],int qtdProf){
  listagem lsprofessor[TAM];
  int i;
  char menor [50];
  for(i=0;i< qtdProf;i++){
    strncpy(lsprofessor[i].nome, listaProfessor[i].nome, 50);
    }

   for(i=0;i< qtdProf-1;i++){
    strncpy(menor, lsprofessor[i].nome, 50);
    int posicao = i;
    for(int j = i+1;j< qtdProf;j++){
      if(strcmp(lsprofessor[j].nome,lsprofessor[i].nome) < 0){
        strncpy(menor, lsprofessor[j].nome, 50);
        posicao=j;
      }
    }
    strncpy(lsprofessor[posicao].nome, lsprofessor[i].nome, 50);
    strncpy(lsprofessor[i].nome, menor, 50);
   }
   for(i=0;i< qtdProf;i++){
      puts(lsprofessor[i].nome);
   }
  
}
//===========================================================================//
void lista(aluno listaAluno[],int qtdAluno,professor listaProfessor[], int qtdProf){
  listagem listaGeral[TAM*2];
  int qtdGeral = qtdAluno + qtdProf;
  for(int i=0;i < qtdGeral;i++){
    for(int j=0;j < qtdProf;j++){
      strncpy (listaGeral[i].nome, listaProfessor[j].nome, 50);
    }
     for(int j=0;j < qtdProf;j++){
      strncpy (listaGeral[i].nome, listaProfessor[j].nome, 50);
    }
  }
  char busca [4];
  printf("Digite as 3 letras para serem pesquisada");
  fgets(busca,4,stdin);
  for(int i=0;i < qtdGeral; i ++){
     int cont = 0;
     for(int j=0;j < 3;j++){
        for(int z=0;listaGeral[i].nome[z] !='\0';z++){
          if(listaGeral[i].nome[z] == busca[j]) cont ++;
        }
      }
      if(cont == 3){
          puts(listaGeral[i].nome);
      }
  }
}
//===========================================================================//
int cadastro_disciplina (disciplina listaDisciplina[], int qtdDisc,professor listaProfessor[], int qtdProf){
   disciplina disciplinaTemp;
  printf("==================== Cadastro Disciplina ====================\n");
  if (qtdDisc == TAM)
    return LISTA_CHEIA;

  printf("Digite o codigo da disciplina\n");
  scanf("%d", &disciplinaTemp.codigo); 
  if (disciplinaTemp.codigo <= 0) return INVALIDO;
  
  printf("Digite o nome\n");
  getchar();
  // char buffer[100];
  // fgets(buffer,100,stdin);

  fgets(disciplinaTemp.nome, 50, stdin);
  size_t ln = strlen(disciplinaTemp.nome) - 1;
  if (disciplinaTemp.nome[ln] == '\n')
    disciplinaTemp.nome[ln] = '\0';

  printf("Digite a matricula do professor \n");
  int i;
  int achou =0;
  scanf("%d",&disciplinaTemp.professor);

  for (i = 0; i < qtdProf; i++) {
    if (listaProfessor[i].matricula == disciplinaTemp.professor)
      achou ++;
      break;
  }
  if(achou == 0) return INEXISTENTE;
  getchar();

  printf("Informe o semestre \n");
  scanf("%d", &disciplinaTemp.semestre);
  
  strncpy (listaDisciplina [qtdDisc].nome, disciplinaTemp.nome, 50);
  listaDisciplina [qtdDisc].professor = disciplinaTemp.professor;
  listaDisciplina [qtdDisc].semestre = disciplinaTemp.semestre;
  listaDisciplina [qtdDisc].codigo = disciplinaTemp.codigo;
  return SUCESSO;
}
//===========================================================================//
int excluirDisciplina (disciplina listaDisciplina[],int qtdDisc){
  int achou = 0;
  int i;
  printf("==================== Excluir Disciplina ====================\n");
  printf("Digite o codigo da disciplina\n");
  int codigo;
  scanf("%d",&codigo);
  for(i = 0; i < qtdDisc; i ++){
    if(listaDisciplina[i].codigo == codigo){
      achou = 1;
      break;
    }
  }
  if(achou == 0) return INEXISTENTE;


  else if(achou == 1){
    for(int j= i ; j < qtdDisc;j++){
      listaDisciplina[j].codigo = listaDisciplina[j+1].codigo;
      listaDisciplina[j].professor = listaDisciplina[j+1].professor;
      listaDisciplina[j].semestre =listaDisciplina[j+1].semestre; 
      listaDisciplina[j].contAluno = listaDisciplina[j+1].contAluno;
      for(i=0; i < listaDisciplina[j].contAluno;i++){
        listaDisciplina[j].alunos[i] = listaDisciplina[j+1].alunos[i];
      }
      strncpy (listaDisciplina[j].nome,listaDisciplina[j +1].nome, 50);
    }
    return SUCESSO;
  }
}
//===========================================================================//
int atualizarDisciplina (disciplina listaDisciplina[], int qtdDisc,professor listaProfessor[], int qtdProf){
  disciplina disciplinaTemp;
  int achou = 0;
  int i;
  printf("==================== Atualizar Disciplina ====================\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d",&matricula);
  for(i = 0; i < qtdDisc; i ++){
    if(listaDisciplina[i].codigo == matricula){
      achou = 1;
      break;
    }
  }
  if(achou == 0) return INEXISTENTE;

  else if(achou == 1){
    printf("Digite o novo codigo da disciplina\n");
  scanf("%d", &disciplinaTemp.codigo); 
  if (disciplinaTemp.codigo <= 0) return INVALIDO;
  
  printf("Digite o nome\n");
  getchar();
  // char buffer[100];
  // fgets(buffer,100,stdin);

  fgets(disciplinaTemp.nome, 50, stdin);
  size_t ln = strlen(disciplinaTemp.nome) - 1;
  if (disciplinaTemp.nome[ln] == '\n')
    disciplinaTemp.nome[ln] = '\0';

  printf("Digite a matricula do professor \n");
  int i;
  int achou =0;
  scanf("%d",&disciplinaTemp.professor);

  for (i = 0; i < qtdProf; i++) {
    if (listaProfessor[i].matricula == disciplinaTemp.professor)
      achou ++;
      break;
  }
  if(achou == 0) return INEXISTENTE;
  getchar();

  printf("Informe o semestre \n");
  scanf("%d", &disciplinaTemp.semestre);
  
  strncpy(listaDisciplina [i].nome, disciplinaTemp.nome, 50);
  listaDisciplina [i].professor = disciplinaTemp.professor;
  listaDisciplina [i].semestre = disciplinaTemp.semestre;
  listaDisciplina [i].codigo = disciplinaTemp.codigo;
  return SUCESSO;
  }
}
//===========================================================================//
int menuDisciplina () {
  int opcao;
  printf("==================== Listar Disciplina ====================\n");
  printf(" [0] - Sair\n");
  printf(" [1] - Listar uma disciplina\n");
  printf(" [2] - Listar todas as disciplinas\n");
  printf(" [3] - Listar disciplinas com mais de 40 alunos\n");
  scanf("%d",&opcao);

}
//===========================================================================//
void listar_disciplinas(disciplina listaDisciplina[],int qtdDisc){
  for(int i=0;i < qtdDisc;i++){
    puts(listaDisciplina[i].nome);
    printf("Professor:%d\n",listaDisciplina[i].professor);
    printf("Semestre:%d\n",listaDisciplina[i].semestre);
    printf("Codigo: %d\n\n",listaDisciplina[i].codigo);
  }
}
//===========================================================================//
void listar_1disciplina(disciplina listaDisciplina[],int qtdDisc){
  int cod,i,achou=0;
  printf("Digite o codigo da disciplina");
  scanf("%d",&cod);
  for(i=0;i < qtdDisc;i++){
    if(listaDisciplina[i].codigo == cod){
      achou ++;
      break;
    }
  }
  if(achou == 0) printf("Disciplina Inexistente");
  else if(achou == 1){
    puts(listaDisciplina[i].nome);
    printf("Professor:%d\n",listaDisciplina[i].professor);
    printf("Semestre:%d\n",listaDisciplina[i].semestre);
    printf("Codigo: %d\n",listaDisciplina[i].codigo);
    for(int j=0;j < listaDisciplina[i].contAluno;j++){
      printf("%d\n",listaDisciplina[i].alunos[j]);
    }
  }
}
//===========================================================================//
void listar_40disciplina(disciplina listaDisciplina[],int qtdDisc){
  for(int i=0;i < qtdDisc;i++){
    if(listaDisciplina[i].contAluno > 40){
      printf("%d\n",listaDisciplina[i].codigo);
    }
  }
}
//===========================================================================//
int disciplina_cadsAluno(disciplina listaDisciplina[],int qtdDisc,aluno listaAluno[],int qtdAluno){
  int achouD = 0;
  int achouA = 0;
  printf("Digite o codigo da Disciplina");
  int cod;
  int i;
  int j;
  
  scanf("%d",&cod);
  for(i=0;i < qtdDisc;i++){
    if( listaDisciplina[i].codigo == cod){
      achouD ++;
      break;
    }
  }
  if(achouD == 0) return INVALIDO;
  else if(achouD == 1){
    printf("Digite a matricula do Aluno");
    int mat;
    scanf("%d",&mat);
    for(j=0;j < qtdAluno;j++){
      if(listaAluno[j].matricula == mat){
        achouA ++;
        break;
      }
    }
    if(achouA == 0) return INVALIDO;
    else if(achouA == 1){
      listaDisciplina[qtdDisc].alunos[listaDisciplina[qtdDisc].contAluno] = mat;
      listaDisciplina[qtdDisc].contAluno ++;
      return SUCESSO;
    }
  }
}
//===========================================================================//
void listarAlunos_disciplina(disciplina listaDisciplina[],int qtdDisc,aluno listaAluno[],int qtdAluno){
  int matriculas=0;
  for(int i=0;i < qtdAluno;i++){
    for(int j=0; j < qtdDisc; j++){
      for(int k=0; k < listaDisciplina[qtdDisc].contAluno; k++){
        if(listaAluno[qtdAluno].matricula == listaDisciplina[qtdDisc].alunos[listaDisciplina[qtdDisc].contAluno] )
          matriculas++;
      }
    }
    if(matriculas < 3) printf("%d",listaAluno[qtdAluno].matricula);
  }
  
}