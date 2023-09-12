#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // bibliotea de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsável por cuidar das strings 


int registro()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem 
	
	// Início de criação das strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação das strings
	
	printf("Digite o cpf a ser cadastrado: ");// Coletando informações do usuário
	scanf("%s", cpf); // Escaneando e armazenando as informações dentro da string (%s)
	
	strcpy(arquivo, cpf); // Igualando o valor da variável
	
	FILE *file; // Cria o arquivo	
	file = fopen(arquivo, "w"); // Cria o arquivo - Comando (w)
	fprintf(file, cpf); // Salva o valor da variável (cpf) dentro do arquivo
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
	
	// Inicio da criação das strings
	char cpf[40];
	char conteudo[200];
	// Fim da criação das strings
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	while(fgets(conteudo,200,file) != NULL) // Fazendo a leitura do arquivo  
	{
		printf("\n\nEssas são as informações do cpf consultado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	if(file == NULL) 
	{
		printf("\n\nO cpf consultado não foi localizado! \n\n");
	}
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	// Início da criação das strings
	char cpf[40];
	// Fim da criação das strings
	
	{
		printf("Digte o CPF do usuário que deseja deletar: ");
		scanf("%s",cpf);
	}
	
	remove(cpf); // Comando remove para deletar variável 
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese");
	
	   printf("### Banco de dados dos usuários ### \n \n");//Ínicio do menu
	   printf(" - Selecione a opção desejada: \n \n");
	   printf("\t1 - Registrar nome \n");
	   printf("\t2 - Consultar nome \n");
	   printf("\t3 - Deletar nome \n");
	   printf("\t4 - Sair do sistema \n\n");
	   printf("Opção: " );//Fim do menu
	
	   scanf("%d", &opcao);//Armazenando as informações dadas pelo usuário
	
       system("cls"); // Comando para limpar a tela
       
       switch(opcao) // Início de seleção do menu
		{
		 
		   case 1:
		   registro(); // Chamada de função
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
		   printf("Essa opção não está disponível \n\n");
		   system("pause");
		   break;
			//Fim da seleção	
		}
			
	
	}
}
