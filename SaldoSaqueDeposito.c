#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
//Função para deposito
void deposito()
{
  int deposito;
  printf("Informe a quantia que você irá depositar: R$");
  int lidoComSucesso = scanf("%d", &deposito);
  while(lidoComSucesso!=1){  
    while(getchar() != '\n');
    printf("\nDepósito inválido!\nInforme novamente: ");
    lidoComSucesso = scanf("%d", &deposito);
  }
  if(deposito >= 0)
    usuario[numeroDaContaEntrada].saldo+=deposito;   
  else
    printf("\n Valor inválido! \n");
}
void saldo() //Função para verificação de saldo
{
  printf("Seu saldo é: R$%.2f\n", usuario[numeroDaContaEntrada].saldo);
}
int saqueCedulas(int valor) //Função para o calculo de notas
{ 
  if(valor==0)
    return 0;
  else if (usuario[numeroDaContaEntrada].saldo < valor) {
    printf("\nSaldo insuficiente!\n");
    return 0;
  }else if(valor > dinheiroMaquina()){
    printf("\nNotas insuficientes\n");
    return 0;
  }
  int contador=0, cedulaDisponivel[7]={0}, i, unidade, dezena;
  unidade=valor%10;//Criar dezena para valores acima de 110~
  dezena=valor%100;
  int notas[7]={0}; //Será guardado o número de notas de 100, 20 e 2, nessa sequencia.
  printf("\nVocê receberá:\n");
  usuario[numeroDaContaEntrada].saldo -= valor;
  for (i=6; i>=0 ; i--) {
    if (tipoCedulas[i].disponivel==1&&tipoCedulas[i].quantidade>0) {
      if(valor >= tipoCedulas[i].cedulas && (unidade==1||unidade==3)){
        if(dezena>10){
          if(tipoCedulas[i].cedulas==100 || tipoCedulas[i].cedulas==200){
            notas[i]=valor/tipoCedulas[i].cedulas;
            valor=valor%tipoCedulas[i].cedulas;
          }
          else if(tipoCedulas[i].cedulas!=2){
            notas[i]=valor/tipoCedulas[i].cedulas-1;
            valor=valor%tipoCedulas[i].cedulas + tipoCedulas[i].cedulas;
          }
          else{
            notas[i]=valor/tipoCedulas[i].cedulas;
            valor=valor%tipoCedulas[i].cedulas + tipoCedulas[i].cedulas;
          }
        }
        else{
          if(tipoCedulas[i].cedulas!=2)
            notas[i]=valor/tipoCedulas[i].cedulas - 1;
          else
            notas[i]=valor/tipoCedulas[i].cedulas;
          valor=valor%tipoCedulas[i].cedulas + tipoCedulas[i].cedulas;
          
        }
        tipoCedulas[i].quantidade-=notas[i];
      }
      else{
        while (valor >= tipoCedulas[i].cedulas) {  
          notas[i]++;
          valor -= tipoCedulas[i].cedulas;
          tipoCedulas[i].quantidade--;
        }
      }
      if(notas[i]!=0)
        printf("%d cédula(s) de R$%d.00\n", notas[i], tipoCedulas[i].cedulas);
    }
  }
}
