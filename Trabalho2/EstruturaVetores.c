#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int *vetorPrincipal[TAM];
int qtd[TAM] = {0};//posição ocupada
int tam[TAM];//tamanho do array
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    posicao --;
  
    if(posicao < 0 || posicao > 9){
      return  POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao] != NULL){
      return JA_TEM_ESTRUTURA_AUXILIAR;  
    }
    if(tamanho < 1){
      return TAMANHO_INVALIDO;
    }
    vetorPrincipal[posicao] = malloc(tamanho * sizeof(int));
  
    if(!vetorPrincipal[posicao]){
      return SEM_ESPACO_DE_MEMORIA; 
    }
    tam[posicao]=tamanho;
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;
  posicao --;
  if (posicao < 0 || posicao > 9)
  {
      return POSICAO_INVALIDA;
  }
  if(vetorPrincipal[posicao]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  if(tam[posicao]==qtd[posicao]){
    return SEM_ESPACO;
  }
  int pos = qtd[posicao];
  qtd[posicao] ++;
  vetorPrincipal[posicao][pos] = valor;              
  return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{     
  posicao--;
  if(posicao>9 || posicao<0){
    return POSICAO_INVALIDA;
  }
  if(vetorPrincipal[posicao]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  if( qtd[posicao]==0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  qtd[posicao]--;
  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    posicao --;
    int pos = qtd[posicao];
    if(posicao>9 || posicao<0){
      return POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao]==NULL){
      return SEM_ESTRUTURA_AUXILIAR;
    }
    if( qtd[posicao]==0){
      return ESTRUTURA_AUXILIAR_VAZIA;
    }
    int achou = 0;
    int i;
    for(i = 0;i<pos;i++)
    {
      if(vetorPrincipal[posicao][i] == valor)
      {
        achou += 1;
        break;
      }
    }
    if(achou == 0)
    {
      return NUMERO_INEXISTENTE;
    }
    qtd[posicao]--;
    for(int j= i+1;j<pos;j++)
    {
      vetorPrincipal[posicao][j-1]=vetorPrincipal[posicao][j];
        
    }
  return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  posicao--;
  if(posicao < 0 || posicao > 9)
  {
    return POSICAO_INVALIDA;
  }
  if(vetorPrincipal[posicao] == NULL)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  int pos = qtd[posicao];
  for(int i=0;i<pos;i++){
    vetorAux[i] = vetorPrincipal[posicao][i];
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  posicao--;
  if(posicao< 0 || posicao > 9){
    return POSICAO_INVALIDA;
  }
  if(vetorPrincipal[posicao]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  int pos = qtd[posicao];
  for(int i=0;i<pos;i++){
    vetorAux[i] = vetorPrincipal[posicao][i];
  }
  for(int i=1;i<pos;i++){
    int aux= vetorAux[i];
    int j= i-1;
    while(j>=0 && vetorAux[j]>aux){
      vetorAux[j+1] = vetorAux[j];
      j = j-1;
    }
    vetorAux[j+1]=aux;
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int vazio =0;
  for(int i=0;i<10;i++){
    if(qtd[i] != 0){
      vazio +=1;
    }
  }
  if(vazio == 0){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  int k =0;
  for (int i = 0; i< 10;i++){
    int pos = qtd[i];
    for(int j = 0;j<pos;j ++){
      vetorAux[k++] = vetorPrincipal[i][j];
    }
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

  int vazio =0;
  for(int i=0;i<10;i++){
    if(qtd[i] != 0){
      vazio +=1;
    }
  }
  if(vazio == 0){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  int k =0;
  for (int i = 0; i< 10;i++){
    int pos = qtd[i];
    for(int j = 0;j<pos;j ++){
      vetorAux[k++] = vetorPrincipal[i][j];
    }
  }
  for(int i=1;i<k;i++){
    int aux= vetorAux[i];
    int j= i-1;
    while(j>=0 && vetorAux[j]>aux){
      vetorAux[j+1] = vetorAux[j];
      j = j-1;
    }
    vetorAux[j+1]=aux;
  }
  
  return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  posicao--;
  if(posicao <0 || posicao >9){
    return POSICAO_INVALIDA;
  }
  if(vetorPrincipal[posicao]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  int tamanho = tam[posicao];
  tamanho += novoTamanho;
  if(tamanho <=0){
    return NOVO_TAMANHO_INVALIDO;
  }
  vetorPrincipal[posicao] = realloc(vetorPrincipal[posicao],tamanho * sizeof(int));
  if(!vetorPrincipal[posicao]){
      return SEM_ESPACO_DE_MEMORIA; 
    }
  tam[posicao] = tamanho;
  if(tamanho< qtd[posicao]){
    qtd[posicao]= tamanho;
  }
  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao --;
    int pos = qtd[posicao];
    if(posicao<0 || posicao>9){
      return POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao]==NULL){
      return SEM_ESTRUTURA_AUXILIAR;
    }
    if(qtd[posicao]==0){
      
      return ESTRUTURA_AUXILIAR_VAZIA;
    }
    return pos;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
  int vetorAux[20];
  if(getDadosDeTodasEstruturasAuxiliares(vetorAux) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
    return NULL ;  
  }
  int tamLs=0;
  for(int i = 0; i<10;i++){
    tamLs+= qtd[i];
  }
  No *inicio = malloc(sizeof(No));
  No *nodo = inicio;
  nodo->prox = NULL;
  for(int i = 0; i<10;i++){
    No *novo= malloc(sizeof(No));
    novo->conteudo = vetorAux[i];
    novo->prox = NULL;
    nodo->prox = novo;
    nodo = novo;
  }
  return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No *atual = inicio->prox;
  int i=0;
  while(atual != NULL){
    vetorAux[i]=atual->conteudo;
    i++;
    atual=atual->prox;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  No *atual = (*inicio)->prox;
  No *anterior = (*inicio)->prox;
   while(atual != NULL){
     atual = atual->prox;
     free(anterior);
     anterior = atual;
   }
  *inicio=NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
  for(int i = 0; i< TAM; i++)
  {
    vetorPrincipal[i] = NULL;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
  for(int i=0; i<10;i++){
    free(vetorPrincipal[i]);
  }
}
