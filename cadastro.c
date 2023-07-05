#include "catalogo.h"
#include <stdio.h>
#include <ctype.h>
// Função para cadastro do cliente
int c; // contador;

int cadastro() {
  int condicao=0,i;
  printf("\nPreencha seus dados cadastrais abaixo.\n");
  while(condicao==0){
  printf("\nSe deseja sair, digite (1)\n");
  printf("\nInforme seu nome e sobrenome: ");
  scanf(" %29[^\n]", usuario[c].nome);
  int nomeCerto = 1;
    for( i = 0; i<29; i++){
      if(usuario[c].nome[i] == '1'){
        return 0;
      }
      if(usuario[c].nome[i] == ' ')
        continue;
      if(isdigit(usuario[c].nome[i]) != 0){
        nomeCerto = 0;
        break;
      }
    }
    if(nomeCerto == 0)
      printf("\n O nome deve conter apenas letras!\n");
      condicao = 0;
    if(nomeCerto == 1)
      condicao = 1;
  }
  printf("\nDigite 'sair' para voltar para o menu principal\n");
  printf("\nInforme seu endereço: ");
  scanf(" %49[^\n]", usuario[c].endereco);
    if(usuario[c].endereco[0] == 's' && usuario[c].endereco[1] == 'a' && usuario[c].endereco[2] == 'i'&&usuario[c].endereco[3] == 'r'){
        return 0;
      }
  condicao =0;
  while(condicao==0){
    printf("\nInforme uma senha de 4 digitos númericos: ");
    for ( i = 0; i < 4; i++) {
      scanf("%1d", &usuario[c].senha[i]);
      condicao=1;
    }
    if (getchar() != '\n') {
      printf("\nSenha inválida\n");
      while (getchar() != '\n');
      condicao=0;
    }
  }
  printf("\nCadastro completo!\n");
  usuario[c].numeroDaConta = 1001 + c;
  printf("Nome: %s\nEndereço: %s\nO número da sua conta é: %d\n", usuario[c].nome,
         usuario[c].endereco, usuario[c].numeroDaConta);
  printf("Senha cadastrada: %d\n\n", usuario[c].senha[i]);
  c++;
                                                                            
}