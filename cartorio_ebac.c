#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de alocac�o de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar de string

int registro()//fun��o criada para cadastrar os usu�rios do sistemas
{
	//inicio da de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/sting
	
	printf("Digite o CPF para cadrastar:");//coletando informa��es do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsavel por copiar os valores das string
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo,"w");// cria o arquivo e escreve
	fprintf(file,cpf);// salvo valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite um nome para ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");// criar string no arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu cargo para ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagen
	
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado: ");
   scanf("%s", cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   {
   	 printf("N�o foi possivel abrir o arquivo,N�o foi localizado!\n");
   }
   
   while(fgets(conteudo, 200, file) != NULL)
   {
   	 printf("\nEssas s�o as informa��es do usu�rio: ");
   	 printf("%s", conteudo);
   	 printf("\n\n");
   }
   
   system("pause");
   
   
   }
 

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//remove o arquivo criado
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; // definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	 
			setlocale(LC_ALL, "Portuguese"); //definindo linguagen
			
			printf("###Cart�rio da EBAC ###\n\n");//inicio do meunu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1-Registrar nomes\n");
			printf("\t2-Consultar nomes\n");
			printf("\t3-Deletar nomes\n\n");
			printf("Op��o:");//fim do menu
			
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
			 
			system("cls");//respons�vel por limpar a tela
			
			switch(opcao) //inicio da sel��o do menu
			{
				case 1:
				registro();//chamada de fun��es 
				break;
				
				case 2:
				consultar();
				break;
				
				case 3:
				deletar();
				break;
				
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			
		}

		
		}

	
	
}
