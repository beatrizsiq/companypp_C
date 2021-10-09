#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pessoa.h" //biblioteca feita por mim

#define MAX_FUNCIONARIO 5

main(){

    int option; //opção de escolha do menu
    int contFuncionarios=0; 
    char searchBadge[5]; //para pesquisa por cpf
    int vectorDelete; // escolha do usuario - qual funcionário (vetor) irá excluir
    int funcEncontrado;
    float mediaSalFuncionarios;

    Pessoa funcionarios[MAX_FUNCIONARIO];  //vetor de funcionários do tipo struct (veio da biblioteca)

    do{
        printf("\n\n\t\tWELCOME TO PP COMPANY \n");
        printf("\n\t 1 -  New Employee");
        printf("\n\t 2 -  List all employee");
        printf("\n\t 3 -  Search for an employee by Badge");
        printf("\n\t 4 -  Delete an employee");
        printf("\n\t 5 -  Average employee salaries");
        printf("\n\t 6 -  Log out");
        printf("\n\t 7 -  System creator\n");
        printf("\n\t > ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                cadastrarFunc(funcionarios);    //função que veio da biblioteca pessoa.h
                opcaoMenu();
                break;
            case 2: 
                listarFuncionarios(funcionarios);  //função que veio da biblioteca pessoa.h
                opcaoMenu();
                break;
            case 3: 
                fflush(stdin);
                printf("\n\tBagde: ");
                fgets(searchBadge, 5, stdin);

                funcEncontrado = procurarCracha(funcionarios, searchBadge);

                if (funcEncontrado != -1)
                {
                    imprimirDadosFuncionarios(funcionarios, funcEncontrado);
                }
                else{

                    printf("\n\tEmployee not found !\n\n");
                }
                opcaoMenu();
                break;
            case 4:
                system("cls");
                printf("\n\tEmployee to be removed\n\t(Inform the employee's position on the list)\n\t>> ");
                scanf("%d", &vectorDelete);
                deleteEmployee(funcionarios, vectorDelete-1);
                opcaoMenu();
                break;
            case 5: 
                mediaSalarial(funcionarios);
                opcaoMenu();
                break;
            case 6:
                printf("\n\tThank you for using the registration system.!\t\n");
			    printf("\n\t>Press any key to exit...\n ");
			    exit(EXIT_SUCCESS);
                break;
            case 7:
                system("cls");
                printf("\n\tSystem created by Beatriz Siqueira, student of the 2nd period of the Information Systems course. ");
                printf("\n\t*sorry for the english that hasn't been studied for a long time\n");
                opcaoMenu();
                break;
            default:
                system("cls");
                printf("\n\tInvalid option!Try again.\n");
                break;
        }

    }while (option!=6);
}

void opcaoMenu(){
    int  opcMenu;

    printf("\n\t1 - Menu\t");
	printf("0 - Log out\n\n");
	printf("\t> ");
	fflush(stdin);
	scanf("%d", &opcMenu);
	switch(opcMenu){
		case 1:
            system("cls");
            return main;
			break;
		case 0:
            printf("\n\tThank you for using the registration system.!\t\n");
			printf("\n\t>Press any key to exit...\n ");
			exit(EXIT_SUCCESS);
            break;
		default:
            printf("\n\tInvalid option!!\n");
            return opcaoMenu();
	}
}