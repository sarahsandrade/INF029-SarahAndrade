#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
#define SUCESSO -1
#define INVALIDO -2
#define LISTA_CHEIA -3
//===========================================================================//
typedef struct listagem {
  char nome [50];
  char sexo;
  int dia, mes, ano;
}listagem;

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
int validacao_nascimento(int dia, int mes, int ano);
int listagemMenu ();
//===========================================================================//
int main(void) {
  int opcaoMenu=1;
  int qtdAluno=0;
  aluno listaAluno[TAM] = {0}; // mudei aqui
  
  while(opcaoMenu!=0){
    
    opcaoMenu= menu_principal();

    switch (opcaoMenu){
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
            case 0:break;
            case 1:{
              int cadastro = cadastro_aluno (listaAluno, qtdAluno);
              if(cadastro == SUCESSO){
                qtdAluno++;
                printf("Matricula feita com sucesso \n");

              }
              else{
                printf("Matricula Invalida \n");
              }
              break;
            }
            case 2: {
              break;
              }
            case 3: {
              break;
            }
            case 4: {
              int opcao = listagemMenu ();
              switch (opcao){
                case 0:break;
                case 1:{
                  for(int i =0; i< qtdAluno;i++) { 
                  printf("Matricula: %d\n",listaAluno[i].matricula);
                }
                  break;}
                case 2:{
                  char  sexo;
                  printf(" [M] - Masculino\n");
                  printf(" [F] - Feminino\n");
                  scanf("%c",&sexo);
                  int i;
                 for(i=0;i< qtdAluno;i++){
                  if(listaAluno[i].sexo == sexo)
                    puts(listaAluno[i].nome);}
                break;}
                case 3:{
                  break;}
                case 4:{
                  break;}
                case 5:{
                  int mes;
                  printf("Digite o mes: ");
                  scanf("%d",&mes);
                  printf("============== Aniversariantes do mes ===============\n");
                  int i;
                  for(i = 0;i< qtdAluno;i++){
                    if(listaAluno[i].mes == mes){
                      printf("%d/%d: ",listaAluno[i].dia, listaAluno[i].mes);
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
        break;}
      case 2:{
        printf("==================== Professor ====================\n");
        printf(" [0] - Voltar\n");
        printf(" [1] - Cadastrar Aluno\n");
        printf(" [2] - Atualizar Aluno\n");
        printf(" [3] - Excluir Aluno\n");
        printf(" [4] - Listar Aluno\n");
        break;}
      case 3:{printf("==================== Disciplina ====================\n");
        break;}
      default: printf("Opção Invalida\n");
      }
    }
    return 0;
  }
 


//===========================================================================//

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

//===========================================================================//

int cadastro_aluno (aluno listaAluno[],int qtdAluno){
  int constante_cadastro;
  aluno alunoTemp;
  printf("==================== Cadastro Aluno ====================\n");
  if (qtdAluno == TAM)
    return LISTA_CHEIA;
  
   printf("Digite a matricula\n");
   scanf("%d",&alunoTemp.matricula);// tirar a parte de digitar matricula
  printf("Digite o nome\n");
  if(alunoTemp.matricula<=0)
    return INVALIDO;
      
    getchar();
      //char buffer[100];
      //fgets(buffer,100,stdin);
    
    fgets(alunoTemp.nome, 50, stdin);
    size_t ln = strlen(alunoTemp.nome) - 1;
    if (alunoTemp.nome[ln] == '\n')
        alunoTemp.nome[ln] = '\0';
        
    printf("Digite o cpf \n");
    fgets(alunoTemp.cpf,12,stdin);
    char buffer[100];
      
    for(int i=0 ;i < 11; i++){
      if (alunoTemp.cpf[i] < '0' || alunoTemp.cpf[i] > '9' )
      return INVALIDO;}
  
    getchar();
  
    printf("Informe o sexo \n");
  
    printf("[0] - Masculino\n");
    printf("[1] - Feminino\n");
    int sexo;
    scanf("%d",&sexo);
    switch (sexo){
      case 0:{
        alunoTemp.sexo = 'M';
        break;}
      case 1:{
        alunoTemp.sexo = 'F';
        break;}
      default: return INVALIDO;
    }
    printf("Data de nascimento\n");
  
    printf("Digite o ano:");
    scanf("%d",&alunoTemp.ano);
  
    printf("Digite o mes: ");
    scanf("%d",&alunoTemp.mes);
  
    printf("Digite o dia: ");
    scanf("%d",&alunoTemp.dia);
        
    int retorno = validacao_nascimento(alunoTemp.dia, alunoTemp.mes, alunoTemp.ano);
    if(retorno == INVALIDO) return INVALIDO;
        
    listaAluno[qtdAluno] = alunoTemp;
    return SUCESSO;
  }

//===========================================================================//
int validacao_nascimento(int dia, int mes, int ano){
  
  if((dia < 1 || dia > 31) || (mes < 1 && mes > 12 )){
    return INVALIDO;}

 if (dia == 31){
    if((mes >= 1 && mes <= 7 && mes % 2 == 0) || (mes >= 8 && mes <= 12 && mes % 2 != 0)) {
 
  return INVALIDO;
      //meses pares do mes 1 ao mes 7 e impares do 8 ao 12 tem  menos que 31 dias 
    }
  }
  if(dia == 29 && mes %4 != 0 ){
    return INVALIDO;
    //ano bissextos são divisiveis por 4
  }
  
  return SUCESSO;
}
//===========================================================================//
int listagemMenu (){
int opcao;
  printf(" [0] - Sair\n");
  printf(" [1] - Matricula\n");
  printf(" [2] - Listar por sexo\n");
  printf(" [3] - Listar por nome\n");
  printf(" [4] - por data de nascimento\n");
  printf(" [5] - Aniversariantes\n");

  scanf("%d",&opcao);
    return opcao;
    // aqui nao retorna opcao

}