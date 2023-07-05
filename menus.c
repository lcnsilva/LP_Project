#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>
//Função para o menu
int menu()
{
  int opcao;
  printf("\n\nEscolha uma operação: \n");
  printf("\n(1) Não sou cliente\t (2) Sou cliente\n");
  printf("\nSua opção: ");
  int lidoComSucesso =scanf("%d", &opcao);
  if(lidoComSucesso!=1){  
    while(getchar() != '\n');  
    return 0;
  }
  return opcao;
}
void menuCedulas(){
  int i;
  printf("\n-------------------------------------------------");
  printf("\n\t\t\tBem-vindo ao Banco 24hrs!\n");
  printf("\nCedulas disponíveis:\n");
  for (i = 0; i < 7; i++) {
    if (tipoCedulas[i].disponivel == 1 && tipoCedulas[i].quantidade>0)
      printf("R$%d.00  ", tipoCedulas[i].cedulas);
  }
}

int subMenu()
{
  int opcao;
  printf("\nOlá %s, seja bem-vindo!\n", usuario[numeroDaContaEntrada].nome);
  printf("\nEscolha uma operação!\n");
  printf("\n(1) Consultar Saldo\n");
  if(dinheiroMaquina()!=0)
    printf("\n(2) Saque\n");
  else
    printf("\n(2) Saque - Indisponível\n");
  printf("\n(3) Deposito\n");
  printf("\n(4) Sair\n");
  printf("\nSua opção: ");
  int lidoComSucesso = scanf("%d", &opcao);
  if(lidoComSucesso!=1){  
      while(getchar() != '\n');
      return 0;
  }
  if(opcao==2 && dinheiroMaquina()==0){
    return 9999;
  }
  return opcao;
}

int outraOperacao(int condicao){
  char repetir;
  if(condicao!=0){
    while (1){
      printf("\nGostaria de fazer outra operação? (s/n)");
      printf("\nSua opção: ");
      scanf(" %1c", &repetir);
      if(repetir == 's'){
        condicao=1;        
        break;
      }else if (repetir == 'n'){
        condicao=0;
        system("clear");
        break;
      }else {
        while(getchar()=='\n');
        printf ("\nOpção inválida.\n");
      }

        
  }
  } 
  return condicao;  
}