#include "catalogo.h"
#include <stdio.h>
// Função para seleção de valores
int escolherValor() {
  int escolha, valor=0;
  printf("\n"); // Adicionar notas que estão disponíveis
  printf("\nCedulas disponiveis:\n");
  for (int i = 0; i < 7; i++) {
    if (tipoCedulas[i].disponivel == 1  && tipoCedulas[i].quantidade>0)
      printf("R$%d.00  ", tipoCedulas[i].cedulas);
  }
  printf("Quanto você quer retirar?\n");
  printf("(1) R$100.00 - (2) R$250.00\n");
  printf("(3) R$500.00 - (4) Outro valor\n");
  printf("(5) Sair\n");
  printf("Escolha uma opção: ");
  int lidoComSucesso = scanf("%d", &escolha); // Declarado variavel lidoComSucesso para saber se
                             // a variavel escolha receberá um valor válido
  while (lidoComSucesso != 1 || escolha < 1 || escolha > 5) {
    printf("Opção inválida!\nDigite a opção novamente: ");
    while (getchar() != '\n'); // limpa o buffer de entrada
    lidoComSucesso = scanf("%d", &escolha);
  }
  switch (escolha) {
  case 1:
    valor = 100;
    break;
  case 2:
    valor = 250;
    break;
  case 3:
    valor = 500;
    break;
  case 4:
    printf("Qual valor você deseja?\n");
    lidoComSucesso = scanf("%d", &valor);
    while (lidoComSucesso != 1) { // Esse é o comando para impedir que o usuário coloque letras no lugar de números
      while (getchar() != '\n'); // Limpa o buffer de entrada
      printf("\nConta inválida!\nInforme novamente: ");
      lidoComSucesso = scanf("%d", &numeroDaContaEntrada);
    }
    if(valor==0)
      break;
    if (tipoCedulas[1].disponivel == 1) { // Caso a nota de R$5 esteja
                                          // disponivel
      while (lidoComSucesso != 1 || valor <= 1 || valor == 3) {
        printf("Não temos notas compatíveis para R$%d.00!\nDigite outro valor: ",valor);
        while (getchar() != '\n'); // limpa o buffer de entrada
        lidoComSucesso = scanf("%d", &valor);
        if(!valor)
         break;
      }
    } else {
      while (lidoComSucesso != 1 || valor < 1 || valor % 2 == 1) {
        printf("Não temos notas compatíveis para R$%d.00!\nDigite outro valor: ",valor);
        while (getchar() != '\n'); // limpa o buffer de entrada
        lidoComSucesso = scanf("%d", &valor);
        if(!valor)
         break;
      }
    }
    break;
    case 5:
      
    break;
    default:
      printf("\nOpção inválida!\n");
    break;
  }
  return valor;
}