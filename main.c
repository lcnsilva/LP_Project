/******************************************************************************

*******************************************************************************/
#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>

cedulas tipoCedulas[7];
cliente usuario[100];
int numeroDaContaEntrada;

int main() {
  int condicao;
  status();
  quantidadeCedulas();
  while (1) { 
    condicao = 0;
    menuCedulas();
    dinheiroMaquina();
     // Condicao para verificação de conta, se, no caso
    switch (menu()) {
    case 1:
      cadastro();
      break;
    case 2:
      condicao = souCliente();
      break;
    default:
      printf("\nOpção inválida!\n");
    }
    while (condicao == 2) {
      system("clear");
      manutencao();
      break;
    }
    while (condicao == 1){
      system("clear");
      switch (subMenu()) {
      case 1:
        saldo();
        break;
      case 2:        
        saqueCedulas(escolherValor());
        break;
      case 3:  
        deposito();
        break;
      case 4:
        condicao=0;
        break;
      case 9999:
        printf("\nFUNÇÃO DE SAQUE INDISPONÍVEL\n");
        break;
      default:
        printf("Opção inválida!\n");
        
        break;  
      }
      condicao=outraOperacao(condicao);
    }
  }
  return 0;
}
