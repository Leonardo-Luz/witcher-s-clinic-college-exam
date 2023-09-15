#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "clinica.h"

int cases;

void Menu()
{
	printf("Menu: \n");
	printf("0  - Sair \n");
	printf("1  - Listar Bruxos \n");
	printf("2  - Cadastrar bruxo pelo codigo \n");
	printf("3  - Excluir bruxo pelo codigo; \n");
	printf("4  - Listar Pocoes \n");
	printf("5  - Cadastrar pocao pelo codigo \n");
	printf("6  - Excluir pocao pelo codigo \n");
	printf("7  - Listar Pacientes \n");
	printf("8  - Cadastrar paciente pelo codigo \n");
	printf("9  - Excluir paciente pelo codigo \n");
	printf("10 - Listar tratamentos do paciente \n");
	printf("11 - Listar pacientes do bruxo \n");
	printf("12 - Iniciar tratamento \n");
	printf("13 - Ampliar tratamento \n");
	printf("14 - Apagar tratamento \n \n");
	
	printf("-> ");
	scanf("%d", &cases);	
}

void WitchersList()
{
	int i;

	printf("\n\nCode - Nome - Especialidade");
	for (i = 0; i < GetQtyWitcher(); i++)
	{
		Witcher witcher = GetWitcher(i);

		printf("\n %d - %s - %s", 
			&witcher.code,
			&witcher.name,
			&witcher.especiality
		);
	}
}

void WitcherRegistration()
{
	Witcher witcher;

	printf("\nDigite o codigo do bruxo: ");
	printf("-> ");
	scanf("%d", &witcher.code);

	printf("\nDigite o nome do bruxo: ");
	printf("-> ");
	scanf(" %s", &witcher.name);

	printf("\nDigite a especialidade do bruxo: ");
	printf("-> ");
	scanf(" %s", &witcher.especiality);

	int successful = WitcherRegister(witcher);

	if(successful) printf("\nBruxo Cadastrado com sucesso!");
	else printf("\nErro no cadastro. \nTente novamente!");
}

void DeleteWitcher()
{
	int code;
	printf("\nDigite o codigo do bruxo que voce deseja deletar: ");
	printf("-> ");
	scanf("%d", &code);

	int successful = WitcherRemove(code);

	if(successful) printf("\nBruxo Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

void PotionsList()
{
	int i;

	printf("\n\nCode - Nome - Tipo");
	for (i = 0; i < GetQtyPotion(); i++)
	{
		Potion potion = GetPotion(i);

		printf("\n %d - %s - %s", 
			&potion.code,
			&potion.name,
			&potion.type
		);
	}
}

void PotionRegistration()
{
	Potion potion;

	printf("\nDigite o codigo da pocao: ");
	printf("-> ");
	scanf("%d", &potion.code);

	printf("\nDigite o nome da pocao: ");
	printf("-> ");
	scanf(" %s", &potion.name);

	printf("\nDigite o tipo da pocao: ");
	printf("-> ");
	scanf(" %s", &potion.type);

	int successful = PotionRegister(potion);

	if(successful) printf("\nPocao Cadastrada com sucesso!");
	else printf("\nErro no cadastro. \nTente novamente!");
}

void DeletePotion()
{
	int code;
	printf("\nDigite o codigo da pocao que voce deseja deletar: ");
	printf("-> ");
	scanf("%d", &code);

	int successful = PotionRemove(code);

	if(successful) printf("\nPocao Removida com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

void PatiantsList()
{
	int i;

	printf("\n\nCode - Nome - Idade - Altura");
	for (i = 0; i < GetQtyPatiant(); i++)
	{
		Patiant patiant = GetPatiant(i);

		printf("\n %d - %s - %d - %f ", 
			&patiant.code,
			&patiant.name,
			&patiant.age,
			&patiant.height			
		);
	}
	printf("\n");
}

void PatiantRegistration()
{
	Patiant patiant;

	printf("\nDigite o codigo do paciente: ");
	printf("-> ");
	scanf("%d", &patiant.code);

	printf("\nDigite o nome do paciente: ");
	printf("-> ");
	scanf(" %s", &patiant.name);

	printf("\nDigite a idade do paciente: ");
	printf("-> ");
	scanf("%d", &patiant.age);

	printf("\nDigite a altura do paciente: ");
	printf("-> ");
	scanf("%f", &patiant.height);

	int successful = PatiantRegister(patiant);

	if(successful) printf("\nPaciente Cadastrado com sucesso!");
	else printf("\nErro no cadastro. \nTente novamente!");
}

void DeletePatiant()
{
	int code;
	printf("\nDigite o codigo do paciente que voce deseja deletar: ");
	printf("-> ");
	scanf("%d", &code);

	int successful = PatiantRemove(code);

	if(successful) printf("\nPaciente Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		Menu();
		
		switch(cases)
		{
			case 1:
				WitchersList();
				break;
				
			case 2:
				WitcherRegistration();
				break;
				
			case 3:
				DeleteWitcher();		
				break;
				
			case 4:
				PotionsList();
				break;
				
			case 5:
				PotionRegistration();
				break;
				
			case 6:
				DeletePotion();
				break;
				
			case 7:
				PatiantsList();
				break;
			
			case 8:
				PatiantRegistration();
				break;
			
			case 9:
				DeletePatiant();
				break;
			
			case 10:
				// ListarTratamentos();
				break;
			
			case 11:
				// ListarPacientesDoBruxo();
				break;
			
			case 12:
				// IniciarTratamento();
				break;
				
			case 13:
				// AmpliarTratamento();
				break;
			
			case 14:
				// ApagarTratamento();
				break;
		}
	} while(cases);
	return 0;
}
