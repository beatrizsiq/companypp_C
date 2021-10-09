#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EMPLOYEE 5
#define SIZE 200
int quantidadeFuncionarios = 0;


// struct dos itens necessarios para o cadastro do funcionário

typedef struct Pessoa
{
    char nome[30];
    int idade;
    float salario;
	char rua[SIZE];
	char bairro[SIZE];
	char cidade[SIZE];
	char cpf[20];
	int numeroCasa;
    char cracha[5];

} Pessoa;

// função para o cadastro do funcionario
void cadastrarFunc(Pessoa *funcionarios) //parametro do tipo struct (pessoa), passando como parametro uma referencia de funcionários\t
{ 
    if (quantidadeFuncionarios < MAX_EMPLOYEE) // condição, caso a qnt ainda seja menor que o max de fun, faz o cadastro
    {   
        FILE *ponteiroFunc;
	    ponteiroFunc = fopen("funcionarios.html", "a");

        system("cls");
        fprintf(ponteiroFunc, "%s", "<html><body> <br>");
        fprintf(ponteiroFunc, "\t---EMPLOYEE---\n");

        printf("\n\t\tEMPLOYEE REGISTRATION\n");
        printf("\n\t >> Full Name: ");
        fflush(stdin);                      // limpa o buffer
        fgets(funcionarios[quantidadeFuncionarios].nome, 30, stdin);
        fprintf(ponteiroFunc, "\nFull Name = %s\n", funcionarios[quantidadeFuncionarios].nome);

        printf("\n\t >> Age: ");
        fflush(stdin);
        scanf("%d", &funcionarios[quantidadeFuncionarios].idade);
        fprintf(ponteiroFunc, "Age = %d\n", funcionarios[quantidadeFuncionarios].idade);
        
        printf("\n\t >> CPF: ");
        fflush(stdin);
        fgets(funcionarios[quantidadeFuncionarios].cpf, 11, stdin);
        fprintf(ponteiroFunc, "CPF = %s; \n", funcionarios[quantidadeFuncionarios].cpf);

        printf("\n\t >> Bagde: ");
        fflush(stdin);
        fgets(funcionarios[quantidadeFuncionarios].cracha, 5, stdin);
        fprintf(ponteiroFunc, "Bagde = %s; \n", funcionarios[quantidadeFuncionarios].cracha);

        printf("\n\t >> Salary: $");
        fflush(stdin);
        scanf("%f", &funcionarios[quantidadeFuncionarios].salario);
        fprintf(ponteiroFunc, "Salary = $%.2f\n; ", funcionarios[quantidadeFuncionarios].salario);


        printf("\n\t >> Address (Street, Avenue...): ");
        fflush(stdin);
        fgets(funcionarios[quantidadeFuncionarios].rua, SIZE, stdin);
        fprintf(ponteiroFunc, "Street = %s\n; ", funcionarios[quantidadeFuncionarios].rua);


        printf("\n\t >> Neighborhood: ");
        fflush(stdin);
        fgets(funcionarios[quantidadeFuncionarios].bairro, SIZE, stdin);
        fprintf(ponteiroFunc, "Neighborhood = %s\n; ", funcionarios[quantidadeFuncionarios].bairro);

        printf("\n\t >> House Number: ");
        fflush(stdin);
        scanf("%d", &funcionarios[quantidadeFuncionarios].numeroCasa);
        fprintf(ponteiroFunc, "House number = %d\n; ", funcionarios[quantidadeFuncionarios].numeroCasa);

        printf("\n\t >> City: ");
        fflush(stdin);
        fgets(funcionarios[quantidadeFuncionarios].cidade, SIZE, stdin);
        fprintf(ponteiroFunc, "City = %s\n; ", funcionarios[quantidadeFuncionarios].cidade);

        quantidadeFuncionarios++;
        fprintf(ponteiroFunc, "%s", "</body></html> <br>");
        fclose(ponteiroFunc);

        printf("\n\tSuccessful Registered Employee!");
        
    }
    else{
        printf("\n\tThe registeer is full\n\n"); //Max fun está cheio
    }
}

void imprimirDadosFuncionarios(Pessoa *funcionarios, int posicaoFun) // func para imprimir os dados do funcionario
{                                                                      // parametros: funcionarios do main e posição dele 

    printf("\n\t----------- Employee %d -----------\n", posicaoFun + 1);

    printf("\n\tName - %s ", funcionarios[posicaoFun].nome, "\n");
    printf("\n\tAge - %d ", funcionarios[posicaoFun].idade, "\n");
    printf("\n\tCPF - %s ", funcionarios[posicaoFun].cpf, "\n");
    printf("\n\tBadge - %s ", funcionarios[posicaoFun].cracha, "\n");
    printf("\n\tStreet - %s ", funcionarios[posicaoFun].rua);
    printf("\n\tNeighborhood - %s ", funcionarios[posicaoFun].bairro);
    printf("\n\tHouse number - %d ", funcionarios[posicaoFun].numeroCasa);
    printf("\n\tCity - %s ", funcionarios[posicaoFun].cidade);
    printf("\n\tSalary: $%.2f ", funcionarios[posicaoFun].salario, "\n" );

    printf("\n\t----------------------------------\n\n");
}

void listarFuncionarios(Pessoa *funcionarios) //func para listar os funcionarios
{

    int i;

    system("cls");

    if(quantidadeFuncionarios > 0){
        printf("\n\t\t\tEMPLOYEE LIST\n\n");
        for (i = 0; i < quantidadeFuncionarios; i++)
        {
            imprimirDadosFuncionarios(funcionarios, i); //chamando a função para imprimir os dados do
        }
    }
    else{
        printf("\n\tThere are no registered employees!\n");
    }
}

int procurarCracha(Pessoa *funcionarios, char cracha[5])
{

    int i, funcionarioEncontrado = -1;

    for (i = 0; i < quantidadeFuncionarios; i++)
    {
        if (strcmp(cracha, funcionarios[i].cracha) == 0)
        {
            funcionarioEncontrado = i;
        }
    }

    return funcionarioEncontrado;
}

void deleteEmployee(Pessoa *funcionarios, int optionEmp)
{
    int i;
    if (optionEmp < quantidadeFuncionarios)
    {
        for (i = optionEmp; i < quantidadeFuncionarios - 1; i++)
        {

            funcionarios[i] = funcionarios[i + 1];
        }
        quantidadeFuncionarios--;
        printf("\n\tSuccessful Deletion!\n\n");

        if (quantidadeFuncionarios >= 1){
            printf("\n\n\t---------New Employee List--------\n");

            for (i = 0; i < quantidadeFuncionarios; i++)
            {
                imprimirDadosFuncionarios(funcionarios, i);
            }
        }
        else{
            printf("\n\tThere are no employees on the list. Register new employees!\n");
        }
    }
    else{

        printf("\n\tCould not complete the deletion.\n\tERROR[021] There is no employee occupying this position!\n");
    }
}

void mediaSalarial(Pessoa *funcionarios){

    int i;
    float soma = 0, media = 0; 
    if (quantidadeFuncionarios>=1){
        for(i = 0; i<quantidadeFuncionarios; i++)
        {
            soma += funcionarios[i].salario;
        }

        media = soma/quantidadeFuncionarios;
        printf("\n\tAverage wage: $%.2f\n", media);

    }
    if (quantidadeFuncionarios <= 0){
        printf("\n\tThere are no registered employees!Register new employees.\n");
    }
}