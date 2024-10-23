#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> // " de alocação de espaço em memória
#include <locale.h> // "  " de texto por região
#include <string.h> // " responsável por cuidar das strings

int Registro() //função responsável por cadastrar usuários
{
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("você selecionou a opção - Registrar novos usuários\n\n");
	
	//inicio criação de variaveis/strings
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
	
	printf("você selecionou a opção - Consultar usuários\n\n");
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"ler"
	
	if(file == NULL)
	{
		printf("Arquivo não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("Essas são as informações registradas do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int Deletar()
{
	
	setlocale (LC_ALL, "Portuguese");
	
	printf("você selecionou a opção - Deletar usuários\n\n");
	
	char cpf[40];
	printf("Digite o cpf do usuário a ser deletado: ");
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
	int opcao=0; //definição de variavel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system ("cls"); 
	
	setlocale (LC_ALL, "Portuguese"); //definição de linguagem
	printf("###  Catório da EBAC  ###\n\n");
	printf("Escolha uma opção desejada no menu:\n\n");
	printf("\t1 - Registrar novos usuários \n");
	printf("\t2 - Consultar usuários \n");
	printf("\t3 - Deletar usuários \n\n");
	printf("Opção: "); 
	
	scanf("%d", &opcao); //guardando opção de escolha

	system("cls"); // limpando mensagens anteriores
	
	switch (opcao)
	{
		case 1:
		Registro(); //chamada de função
		break;
		
		case 2:
		Consulta();
		break;
		
		case 3:
		Deletar();
		break;
		
		default:
		printf("Opção não disponível\n");
		system ("pause");
		break;
	}
	}
}


