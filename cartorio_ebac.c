#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocacão de texto por região
#include <string.h> //biblioteca reponsável por cuidar de string

int registro()//função criada para cadastrar os usuários do sistemas
{
	//inicio da de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/sting
	
	printf("Digite o CPF para cadrastar:");//coletando informações do usuário
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
   	 printf("Não foi possivel abrir o arquivo,Não foi localizado!\n");
   }
   
   while(fgets(conteudo, 200, file) != NULL)
   {
   	 printf("\nEssas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!.\n");
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
			
			printf("###Cartório da EBAC ###\n\n");//inicio do meunu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1-Registrar nomes\n");
			printf("\t2-Consultar nomes\n");
			printf("\t3-Deletar nomes\n\n");
			printf("Opção:");//fim do menu
			
			scanf("%d", &opcao); //armazenando a escolha do usuário
			 
			system("cls");//responsável por limpar a tela
			
			switch(opcao) //inicio da selção do menu
			{
				case 1:
				registro();//chamada de funções 
				break;
				
				case 2:
				consultar();
				break;
				
				case 3:
				deletar();
				break;
				
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			
		}

		
		}

	
	
}
