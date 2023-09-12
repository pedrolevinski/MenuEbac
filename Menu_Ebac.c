#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // bibliotea de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das strings 


int registro()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem 
	
	// In�cio de cria��o das strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o das strings
	
	printf("Digite o cpf a ser cadastrado: ");// Coletando informa��es do usu�rio
	scanf("%s", cpf); // Escaneando e armazenando as informa��es dentro da string (%s)
	
	strcpy(arquivo, cpf); // Igualando o valor da vari�vel
	
	FILE *file; // Cria o arquivo	
	file = fopen(arquivo, "w"); // Cria o arquivo - Comando (w)
	fprintf(file, cpf); // Salva o valor da vari�vel (cpf) dentro do arquivo
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Abre o aqruivo para atualiza-lo - Comando (a)
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o primeiro nome: ");
	scanf("%s", nome);
		
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // Abre o aqruivo para atualiza-lo - Comando (a)
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // Abre o aqruivo para atualiza-lo - Comando (a)
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	// Inicio da cria��o das strings
	char cpf[40];
	char conteudo[200];
	// Fim da cria��o das strings
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	while(fgets(conteudo,200,file) != NULL) // Fazendo a leitura do arquivo  
	{
		printf("\n\nEssas s�o as informa��es do cpf consultado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	if(file == NULL) 
	{
		printf("\n\nO cpf consultado n�o foi localizado! \n\n");
	}
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	// In�cio da cria��o das strings
	char cpf[40];
	// Fim da cria��o das strings
	
	{
		printf("Digte o CPF do usu�rio que deseja deletar: ");
		scanf("%s",cpf);
	}
	
	remove(cpf); // Comando remove para deletar vari�vel 
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese");
	
	   printf("### Banco de dados dos usu�rios ### \n \n");//�nicio do menu
	   printf(" - Selecione a op��o desejada: \n \n");
	   printf("\t1 - Registrar nome \n");
	   printf("\t2 - Consultar nome \n");
	   printf("\t3 - Deletar nome \n");
	   printf("\t4 - Sair do sistema \n\n");
	   printf("Op��o: " );//Fim do menu
	
	   scanf("%d", &opcao);//Armazenando as informa��es dadas pelo usu�rio
	
       system("cls"); // Comando para limpar a tela
       
       switch(opcao) // In�cio de sele��o do menu
		{
		 
		   case 1:
		   registro(); // Chamada de fun��o
		   system("pause");
		   break;
		   
		   case 2: 
		   consulta();
		   system("pause");
		   break;
		 
		   case 3: 
		   deletar();
		   system("pause");
		   break;
		   
		   case 4:
		   printf("Obrigado por escolher EBAC!\n\n");
		   system("pause");
		   return 0;
		   break;	
		   
		   default:
		   printf("Essa op��o n�o est� dispon�vel \n\n");
		   system("pause");
		   break;
			//Fim da sele��o	
		}
			
	
	}
}
