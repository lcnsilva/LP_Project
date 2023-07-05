void reporTudo();
void reporIndividual();
void disponibilidadeCedula();
int escolherValor();
int saqueCedulas();
void status();
void manutencao();
int cadastro();
int menu();
int subMenu();
void deposito();
int souCliente();
void saldo();
void menuCedulas();
int outraOperacao();
void quantidadeCedulas();
int dinheiroMaquina();

typedef struct{
    int cedulas;
    int quantidade;
    int disponivel;
}cedulas;
typedef struct{
    int numeroDaConta;
    char nome[30], endereco[50];
    float saldo;
    int senha[4];
}cliente;
extern cedulas tipoCedulas[7];
extern cliente usuario[100];
extern int numeroDaContaEntrada;
