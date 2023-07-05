#include <stdio.h>
#include <string.h>
#include "catalogo.h"
//Funções do switch case 1,2,3,4
void mostrarCedulas(){
  int i;
  printf("\nMenu de cédulas atuais: \n");
  for(i=0;i<7;i++){
    if(tipoCedulas[i].disponivel==1)
    printf("\n(%d) Cédula de: R$%d.00",i+1, tipoCedulas[i].cedulas);
  }
}

void reporTudo() //Função para repor a qntd de todas as cédulas
{
  int repor;
  printf("\nQual a quantidade de cédulas que gostaria de adicionar?\n");
  int lidoComSucesso = scanf("%d", &repor);
  while(lidoComSucesso!=1){  
    while(getchar() != '\n');
    printf("\nValor inválido!\n\nInforme novamente: ");
    lidoComSucesso = scanf("%d", &repor);
  }
  for(int i=0;i<7;i++){ //Necessario para mostrar apenas cédulas habilitadas
        tipoCedulas[i].quantidade+=repor;
  }
  printf("\nAs cédulas foram depósitadas!\n");
}
void reporIndividual() //Função para repor individualmente a qntd de cédula
{
  int opcao, repor, c;
  printf("\n");
  for(int i=0;i<7;i++){//Necessario para mostrar apenas cédulas habilitadas
      printf("(%d) R$%d.00 - %d cédulas disponíveis\n\n", i, tipoCedulas[i].cedulas, tipoCedulas[i].quantidade);
  }
  printf("(7) Sair\n\n");
  printf("Escolha uma opção: ");
  int lidoComSucesso = scanf("%d", &opcao);
  while(lidoComSucesso!=1){  
    while(getchar() != '\n');
    printf("\nOpção inválida!\nInforme novamente: ");
    lidoComSucesso = scanf("%d", &opcao);
  }
  if(opcao == 7){
    return;
  }
  else if(opcao>=0 && opcao<=6){
      printf("Qual a quantidade de cédulas que gostaria de adicionar?\n");
      lidoComSucesso = scanf("%d", &repor);
      while(lidoComSucesso!=1){  
        while(getchar() != '\n');
        printf("\nValor inválido!\nInforme novamente: ");
        lidoComSucesso = scanf("%d", &repor);
      }
      tipoCedulas[opcao].quantidade+=repor;
  }
}
void disponibilidadeCedula() //Função para alterar a disponibilidade de um tipo de cédula
{ 
  int opcao /*cedulaEditar*/;
  char notaUtilizada[7][30];
  printf("Qual cédula gostaria de editar?\n\n");
  for(int i=0;i<7;i++){
    if(tipoCedulas[i].disponivel==1) //Necessario para mostrar apenas cédulas habilitadas
        strcpy(notaUtilizada[i], "\t\tStatus: Habilitado");
    else
        strcpy(notaUtilizada[i], "\t\tStatus: Desabilitado");
    printf("(%d) R$%d.00  %s\n\n", i, tipoCedulas[i].cedulas, notaUtilizada[i]);
  }
  printf("(7) Sair\n\n");
  printf("Escolha uma opção: ");
  int lidoComSucesso = scanf("%d", &opcao);
  while(lidoComSucesso!=1){  
    while(getchar() != '\n');
    printf("\nOpção inválida!\nInforme novamente: ");
    lidoComSucesso = scanf("%d", &opcao);
  }
  if(opcao == 7){
    return;
  }
  else if(opcao>=0 && opcao<=6){
    printf("\nEscolha a disponibilidade:");
    printf("\n(0) Desabilitado \t (1) Habilitado\n");
    int opcaoDisponibilidade;
    int lidoComSucesso = scanf("%d", &opcaoDisponibilidade);
    while(lidoComSucesso!=1){  
      while(getchar() != '\n');
      printf("\nOpção inválida!\n\nInforme novamente: ");
      lidoComSucesso = scanf("%d", &opcao);
    }
    switch (opcaoDisponibilidade){
      case 0:
        tipoCedulas[opcao].disponivel = 0;
        break;
      case 1:
        tipoCedulas[opcao].disponivel = 1;
        break;
      default:
        printf("\n Opção Inválida!\n");
        break;
    }
  }
  else{
    printf("\n\n\tOpção inválida!\t\n\n");
  }
}

void status()
{
  tipoCedulas[0].cedulas=2; //inicializando o valor de todas as cedulas
  tipoCedulas[1].cedulas=5;
  tipoCedulas[2].cedulas=10;
  tipoCedulas[3].cedulas=20;
  tipoCedulas[4].cedulas=50;
  tipoCedulas[5].cedulas=100;
  tipoCedulas[6].cedulas=200;
  tipoCedulas[0].disponivel=1; //Indicado que as cedulas 2,20 e 100 estão disponiveis
  tipoCedulas[3].disponivel=1;
  tipoCedulas[5].disponivel=1;
  usuario[99].numeroDaConta=1100;//Conta criada para fim de testes no código.
  strcpy(usuario[99].nome, "Luciano");
  usuario[99].saldo = 10000;
  usuario[99].senha[0] = 1;
  usuario[99].senha[1] = 1;
  usuario[99].senha[2] = 1;
  usuario[99].senha[3] = 1;
}

void quantidadeCedulas(){
  for (int i = 0; i < 7; i++) { // Inicia a quantidade de notas com 50
    if (tipoCedulas[i].disponivel == 1){
      tipoCedulas[i].quantidade = 50;
    }
  }
}

int dinheiroMaquina(){
  int totalDinheiroMaquina=0,caixaVazio=0;
  for(int i=0;i<7;i++){
    if(tipoCedulas[i].disponivel==1){
      totalDinheiroMaquina += (tipoCedulas[i].cedulas*tipoCedulas[i].quantidade);
    }
  }
  /*if(totalDinheiroMaquina==0){
    printf("Máquina não possui cédulas!\n");
    }*/
  return totalDinheiroMaquina;
}