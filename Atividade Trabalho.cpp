#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

//DECLARA플O DE VARIAVEIS GLOBAIS E ESTRUTURAS

#define MaxTam 20


typedef int Apontador;

typedef struct EstruturaDados{
	int Codigo;
	char Nome[20];
	char Data[10];
	char Sit[10];
	double Valor;
};

typedef struct EstruturaLista{
	EstruturaDados Dados[MaxTam];
	Apontador Inicio;
	Apontador Fim;
};

//DECLARA플O DAS FUN합ES

void SettarLista(EstruturaLista &Lista){
	Lista.Inicio = 0;
	Lista.Fim = 0;
}

void InserirNaLista(EstruturaDados Aux, EstruturaLista &Lista){
	if(Lista.Fim > MaxTam){
		system("cls");
		printf("Lista Cheia\n");
	}else{
	Lista.Dados[Lista.Fim] = Aux;
	Lista.Fim++;
	}
}

int PesquisaPorCodigo(int Codigo, EstruturaLista &Lista){
	int i, Aux = -1;
	
	for(i = Lista.Inicio; i < Lista.Fim; i++){
		if(Lista.Dados[i].Codigo == Codigo)
			Aux = i;
	}
	return Aux;
}

void InserirNaPosicao(EstruturaDados Aux, EstruturaLista &Lista, Apontador Posicao){
	Lista.Dados[Posicao] = Aux;
}

void ConsultaPorPosicao(Apontador Posicao, EstruturaLista &Lista){
		printf("\n\nCodigo: %d",Lista.Dados[Posicao].Codigo);
		printf("\nNome da Conta: %s",Lista.Dados[Posicao].Nome);
		printf("\nData: %s",Lista.Dados[Posicao].Data);
		printf("\nSituacao de pagamento: %s",Lista.Dados[Posicao].Sit);
		printf("\nValor: %.2lf\n\n",Lista.Dados[Posicao].Valor);
}

void ImprimirNaTela(EstruturaLista &Lista){
	int i;
	
	for(i = Lista.Inicio; i < Lista.Fim; i++){
		printf("\n\nCodigo: %d",Lista.Dados[i].Codigo);
		printf("\nNome da Conta: %s",Lista.Dados[i].Nome);
		printf("\nData: %s",Lista.Dados[i].Data);
		printf("\nSituacao de pagamento: %s",Lista.Dados[i].Sit);
		printf("\nValor: %.2lf\n\n",Lista.Dados[i].Valor);
	}
}

// OP합ES PARA SELECIONAR

int Menu(){
	int Opcao;
	
	do{
		system("cls");	
	
	printf("Escolha uma opcao:\n\n");
	printf("1 - Inserir uma nova conta\n");
	printf("2 - Alterar pelo codigo\n");
	printf("3 - Excluir\n");
	printf("4 - Imprimir Lista Completa\n");
	printf("0 - Sair\n");
	printf("\nOpcao: ");
	scanf("%d",&Opcao);
} while(Opcao < 0 || Opcao > 4);
	
	return Opcao;
}

// FUN플O PRINCIPAL

main(){
	EstruturaDados Aux;
	EstruturaLista Lista;
	int Opcao, Codigo, Posicao;
	
	SettarLista(Lista);
	
	Opcao = Menu();
	
	while(Opcao != 0){
	switch(Opcao){
		
		// 1 - INSERIR
		case 1:
			system("cls");
			
			printf("Digite um codigo: ");
			scanf("%d",&Aux.Codigo);
				getchar();
			printf("Digite um nome: ");
				cin.getline(Aux.Nome, 20);
			printf("Digite uma data: ");
				cin.getline(Aux.Data, 10);
			printf("Digite a situacao do pagamento: ");
				cin.getline(Aux.Sit, 10);
			printf("Digite um valor: ");
			scanf("%lf",&Aux.Valor);
				
		        InserirNaLista(Aux, Lista);
				
		break;
		
		// 2 - ALTERAR PELO CODIGO
		case 2:
			system("cls");
			printf("Buscar pelo codigo: ");
				scanf("%d",&Codigo);
			
			Posicao = PesquisaPorCodigo(Codigo, Lista);
			
			if(Posicao == -1){
				printf("Nao encontrado\n");
				system("pause");
			}else{
				ConsultaPorPosicao(Posicao, Lista);
				
				printf("Digite o novo codigo: ");
			    scanf("%d",&Aux.Codigo);
					getchar();
				printf("Digite o novo nome: ");
				cin.getline(Aux.Nome, 20);
				printf("Digite uma nova data: ");
				cin.getline(Aux.Data, 10);
				printf("Digite a nova situacao de pagamento: ");
				cin.getline(Aux.Sit, 10);
				printf("Digite o novo Valor: ");
			    scanf("%lf",&Aux.Valor);
				
				InserirNaPosicao(Aux, Lista, Posicao);	
			}
		break;
		
		// 3 - EXCLUIR 
		
		
		
		// 4 - IMPRIMIR
	    case 4:
	    	system("cls");
	    	printf("\n\t\tLISTA COMPLETA\t\t\t\n");
	    	ImprimirNaTela(Lista);
	    	
	    	system("pause");
	    break;
	}
		Opcao = Menu();
	}	
}
