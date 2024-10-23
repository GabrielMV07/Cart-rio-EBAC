#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // " de aloca��o de espa�o em mem�ria
#include <locale.h> // "  " de texto por regi�o
#include <string.h> // " respons�vel por cuidar das strings

int Registro() //fun��o respons�vel por cadastrar usu�rios
{
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("voc� selecionou a op��o - Registrar novos usu�rios\n\n");
	
	//inicio cria��o de variaveis/strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final
	
	printf("\nDigite o CPF a ser cadastrado: "); //coleta de dados
	scanf("%s",cpf); //referencia string
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //"escrever"
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"atualizar"
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	
	
	system("pause");
}

int Consulta()
{
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("voc� selecionou a op��o - Consultar usu�rios\n\n");
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"ler"
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("Essas s�o as informa��es registradas do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int Deletar()
{
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("voc� selecionou a op��o - Deletar usu�rios\n\n");
	
	char cpf[40];
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Registro deletado.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //defini��o de variavel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system ("cls"); 
	
	setlocale (LC_ALL, "Portuguese"); //defini��o de linguagem
	printf("###  Cat�rio da EBAC  ###\n\n");
	printf("Escolha uma op��o desejada no menu:\n\n");
	printf("\t1 - Registrar novos usu�rios \n");
	printf("\t2 - Consultar usu�rios \n");
	printf("\t3 - Deletar usu�rios \n\n");
	printf("Op��o: "); 
	
	scanf("%d", &opcao); //guardando op��o de escolha

	system("cls"); // limpando mensagens anteriores
	
	switch (opcao)
	{
		case 1:
		Registro(); //chamada de fun��o
		break;
		
		case 2:
		Consulta();
		break;
		
		case 3:
		Deletar();
		break;
		
		default:
		printf("Op��o n�o dispon�vel\n");
		system ("pause");
		break;
	}
	}
}


