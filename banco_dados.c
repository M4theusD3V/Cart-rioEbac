#include <stdio.h> //blibioteca de comunica��o com o us�ario
#include <stdlib.h> //blibioteca de aloca��o de escpa�o em mem�ria
#include <locale.h> //blibioteca de aloca��o de texto por regi�o
#include <string.h> //blibioteca responsavel por cuidar das strings
int registro()
{
	 setlocale(LC_ALL, "Portuguese_Brazil");
	
	
	//inicio das vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis
    
    printf("Digite o CPF para registro: "); //coletando informa��o do usuario
    scanf("%s",cpf); //%s refere-se a strings
    
    strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
    
    FILE*file; //cria arquivo
    file = fopen(arquivo,"w"); //abre o arquivo (o "w" significa write=escrever)
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //abre o arquivo
    fprintf(file,","); //salva a vari�vel
    fclose(file); //fecha o arquivo
    
    printf("nome: "); //cria a op��o para colocar o nome
    scanf("%s",nome); //scanf � para buscar dentro do arquivo a variavel nome
    
    file = fopen(arquivo,"a"); //abre o arquivo
    fprintf(file,nome); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("sobrenome: "); //cria a op��o para colocar o sobrenome
    scanf("%s",sobrenome); //busca dentro do arquivo a variavel sobrenome
    
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome); //salva o valor da vari�vel
    fclose(file);
    
    file = fopen(arquivo,"a"); 
    fprintf(file,",");
    fclose(file);
    
    printf("cargo: "); // cria a op��o para colocar o cargo
    scanf("%s",cargo); //busca dentro do arquivo a variavel cargo
    
    file = fopen(arquivo,"a"); //abre o arquivo
    fprintf(file,cargo); //salva o valor da vari�vel
    fclose(file);
    
    system("pause");
}

int consulta()
{
	 //setando a gram�tica portuguesa no programa
 
 	//inicio das vari�veis/string
    char cpf[40]; 
    char conteudo[200];
    //final da cria��o de vari�veis

    printf("Digite o CPF a ser consultado: "); //criando a op��o para colocar o cpf
    scanf("%s", cpf); //abrindo o arquivo e consultando a variabel cpf

    FILE *file; //abre a o arquivo (j� criado la no registro)
    file = fopen (cpf, "r");//l� o arquivo (a letra "r" significa read=ler)

    if(file == NULL) // se o arquivo for igual a nulo
 {
 	printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n"); //vai aparecer essa mensagem
 } 
 
    while (fgets(conteudo, 200, file) != NULL) // while = enquanto
{	
    printf("Essas s�o as informa��es do usu�rio: ");
    printf("%s", conteudo);
    printf("\n\n");
}

    system("pause"); 
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("nenhum usu�rio encontrado no sistema!");
		system ("pause");
	}
}

int main() //entrada inicial do sistema
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
   system("CLS");
	
   setlocale(LC_ALL, "Portuguese"); //definindo a gram�tica Portugues Brasil
   
   printf("###Dados dos Alunos EBAC###\n \n"); //inicio do menu
   printf("escolha a sua op��o no menu!:\n \n");
   printf("\t1 - Registrar nomes\n");
   printf("\t2 - Consultar nomes\n");
   printf("\t3 - Deletar nomes\n\n");
   printf("op��o: "); //fim do menu
   
   scanf("%d",&opcao); //armazenando a escolha do cliente
   
   system("CLS"); //inicio da sele��o
   
   switch(opcao)
   {
   	case 1:
   	registro();
   	break;
   	  
   	case 2:
   	consulta();
   	break;
   	
   	case 3:
  	deletar();
   	break;
   	
   	default:
   	printf("Essa op��o n�o esta disponivel:(\n");
   	system("pause");
   	break;
   }
   
}
}
