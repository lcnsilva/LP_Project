#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Função para verificação de conta

int souCliente() {
  int senhaDaContaEntrada[4], senhaCorreta, senhaMantenedor, condicao;
  printf("\nInforme o número da conta: ");
  int lidoComSucesso = scanf("%d",&numeroDaContaEntrada); // Declarado variavel lidoComSucesso para saber se a variavel escolha receberá um valor válido  
  while (lidoComSucesso != 1) { // Esse é o comando para impedir que o usuário coloque letras no lugar de números
    while (getchar() != '\n'); // Limpa o buffer de entrada
    printf("\nConta inválida!\nInforme novamente: ");
    lidoComSucesso = scanf("%d", &numeroDaContaEntrada);
  }
  for (int i = 0; i < 100; i++) {
    if (numeroDaContaEntrada == 1000) {
      printf("Informe sua senha: ");
      scanf("%d", &senhaMantenedor);
      if (senhaMantenedor == 123456)
        return 2;
      else {
        printf("Senha inválida\n");
        return 0;
      }
    } else if (numeroDaContaEntrada==usuario[i].numeroDaConta)
    {
      while (1) {
        printf("\nInforme sua senha: ");
        for (int j = 0; j < 4; j++) {
          scanf("%1d", &senhaDaContaEntrada[j]);
        }
        while (getchar() != '\n');
        for (int j = 0; j < 4; j++) {
          if (senhaDaContaEntrada[j] == usuario[i].senha[j]) {
            senhaCorreta = 1;
            continue;
          } else {
            printf("\nSenha inválida!\n");
            return 0;
          }
        }
        if (senhaCorreta == 1) {
          numeroDaContaEntrada -= 1001;
          return 1;
        }
      }
    }
    else{
      condicao=1;
    } 
  }
  if(condicao==1){
      printf("\nConta inválida\n");
      return 0;
    }
}