#include <stdio.h> //blibioteca de comunicação com o usúario
#include <stdlib.h> //blibioteca de alocação de escpaço em memória
#include <string.h> //blibioteca responsavel por cuidar das string
#include <locale.h>
int registro()
{
	
	//inicio das variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis
    
    printf("Digite o CPF para registro: "); //coletando informação do usuario
    scanf("%s",cpf); //%s refere-se a strings
    
    strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
    
    FILE*file; //cria arquivo
    file = fopen(arquivo,"w"); //abre o arquivo (o "w" significa write=escrever)
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //abre o arquivo
    fprintf(file,","); //salva a variável
    fclose(file); //fecha o arquivo
    
    printf("nome: "); //cria a opção para colocar o nome
    scanf("%s",nome); //scanf é para buscar dentro do arquivo a variavel nome
    
    file = fopen(arquivo,"a"); //abre o arquivo
    fprintf(file,nome); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("sobrenome: "); //cria a opção para colocar o sobrenome
    scanf("%s",sobrenome); //busca dentro do arquivo a variavel sobrenome
    
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome); //salva o valor da variável
    fclose(file);
    
    file = fopen(arquivo,"a"); 
    fprintf(file,",");
    fclose(file);
    
    printf("cargo: "); // cria a opção para colocar o cargo
    scanf("%s",cargo); //busca dentro do arquivo a variavel cargo
    
    file = fopen(arquivo,"a"); //abre o arquivo
    fprintf(file,cargo); //salva o valor da variável
    fclose(file);
    
    system("pause");
}

int consulta()
{
	 
	
 
 	//inicio das variáveis/string
    char cpf[40]; 
    char conteudo[200];
    //final da criação de variáveis

    printf("Digite o CPF a ser consultado: "); //criando a opção para colocar o cpf
    scanf("%s", cpf); //abrindo o arquivo e consultando a variabel cpf

    FILE *file; //abre a o arquivo (já criado la no registro)
    file = fopen (cpf, "r");//lê o arquivo (a letra "r" significa read=ler)

    if(file == NULL) // se o arquivo for igual a nulo
 {
 	printf("\nNão foi possível abrir o arquivo, não localizado!\n"); //vai aparecer essa mensagem
 } 
 
    while (fgets(conteudo, 200, file) != NULL) // while = enquanto
{	
    printf("Essas são as informações do usuário: ");
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
		printf("nenhum usuário encontrado no sistema!");
		system ("pause");
	}
}

int main() //entrada inicial do sistema
{
      setlocale(LC_ALL, "Portuguese"); //definindo a gramática Portugues Brasil
      
	int opcao=0;
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("CLS");
    
	    for(laco=1;laco=1;)
	  {
   
        printf("###Dados dos Alunos EBAC###\n \n"); //inicio do menu
        printf("escolha a sua opção no menu!:\n \n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("opção: "); //fim do menu
   
        scanf("%d",&opcao); //armazenando a escolha do cliente
   
        system("CLS"); //inicio da seleção
   
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
   	
   	    case 4:
   	    printf("Obrigado por utilizar o sistema! :)\n");
   	    return 0;
   	    break;
   	
   	    default:
   	    printf("Essa opção não esta disponivel:(\n");
   	    system("pause");
   	    break;
       }
       
    }
} 
   else
   printf("Senha incorreta!");
        
}

