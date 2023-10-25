#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "clinica.h"

void MenuInicial()
{
	printf("\nMenu: ");
	printf("\n0  - Sair");
	printf("\n1  - Bruxo");
	printf("\n2  - Pocao");
	printf("\n3  - Paciente");
	printf("\n4  - Tratamento");
	
	printf("\n-> ");
}

void MenuAvancado()
{
	printf("\nMenu: ");
	printf("\n0  - Sair");
	printf("\n1  - Listar");
	printf("\n2  - Cadastrar");
	printf("\n3  - Alterar");
	printf("\n4  - Excluir");
	
	printf("\n-> ");
}

void MenuTratamento()
{
	printf("\nMenu: ");
	printf("\n0  - Sair");
	printf("\n1  - Listar tratamentos do paciente");
	printf("\n2  - Listar tratamentos do bruxo");
	printf("\n3  - Iniciar tratamento");
	printf("\n4  - Ampliar tratamento");
	printf("\n6  - Excluir tratamento");
			
	printf("\n-> ");
}

void WitchersList()
{
	int i;

	if(GetQtyWitcher() == 0)
	{
		printf("\nSem Bruxo!");
		return;
	}

	printf("\n\nCode - Nome - Especialidade");
	for (i = 0; i < GetQtyWitcher(); i++)
	{
		Witcher witcher = GetWitcher(i);

		printf("\n %d - %s - %s", 
			witcher.code,
			witcher.name,
			witcher.especiality
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
	if(GetQtyWitcher() == 0)
	{
		printf("\nSem Bruxo!");
		return;
	}	
	
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

	if(GetQtyPotion() == 0)
	{
		printf("\nSem Pocao!");
		return;
	}

	printf("\n\nCode - Nome - Tipo");
	for (i = 0; i < GetQtyPotion(); i++)
	{
		Potion potion = GetPotion(i);

		printf("\n %d - %s - %s", 
			potion.code,
			potion.name,
			potion.type
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

	if(GetQtyPatiant() == 0)
	{
		printf("\nSem Pacientes!");
		return;
	}

	printf("\n\nCode - Nome - Idade - Altura");
	for (i = 0; i < GetQtyPatiant(); i++)
	{
		Patiant patiant = GetPatiant(i);

		printf("\n %d - %s - %d - %f ", 
			patiant.code,
			patiant.name,
			patiant.age,
			patiant.height			
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

void TreatmentList()
{
	int i;

	if(GetQtyTreatment() == 0)
	{
		printf("\nSem Tratamentos!");
		return;
	}

	printf("\n\nCode - Code Bruxo - Code Pocao - Code Paciente - Duracao - Dosagem ");
	for (i = 0; i < GetQtyTreatment(); i++)
	{
		Treatment treatment = GetTreatment(i);

		printf("\n %d - %d - %d - %d - %d - %d ", 
			treatment.code,
			treatment.witcherCode,
			treatment.potionCode,
			treatment.patiantCode,
			treatment.duration,
			treatment.dosage			
		);
	}
	printf("\n");
}

void WitcherPatiantsList()
{
	int i;
	int code;

	if(GetQtyTreatment() == 0)
	{
		printf("\nSem Tratamentos!");
		return;
	}

	printf("Digite o codigo do bruxo: \n");
	printf("-> ");
	scanf("%d", &code);


	printf("\n\nCode - Nome - Idade - Altura");

	for(i = 0; i < GetQtyWitcher(); i++)
	{
		if(GetTreatment(i).witcherCode == code)
		for (i = 0; i < GetQtyPatiant(); i++)
		{
			Patiant patiant = GetPatiant(i);

			if(GetTreatment(i).patiantCode == patiant.code)
				printf("\n %d - %s - %d - %f ", 
					&patiant.code,
					&patiant.name,
					&patiant.age,
					&patiant.height			
				);
		}
	}
	printf("\n");
}

void TreatmentRegistration()
{
	if(!GetQtyPatiant() || !GetQtyPotion() || !GetQtyWitcher())
	{
		printf("Incapaz de registrar tratamento! \n");
		return;
	}

	int i;
	Treatment treatment;

	printf("Digite o codigo do tratamento: \n");
	printf("-> ");
	scanf("%d", &treatment.code);


	printf("Digite o codigo do bruxo: \n");
	printf("-> ");
	scanf("%d", &treatment.witcherCode);

	for(i = 0; i < GetQtyWitcher(); i++)	
	if(GetWitcher(i).code == treatment.witcherCode)
	{
		break;
	}
	else if(i == GetQtyWitcher() - 1)
	{
		printf("Codigo invalido! \n");
		return;	
	}

	printf("Digite o codigo da pocao: \n");
	printf("-> ");
	scanf("%d", &treatment.potionCode);

	for(i = 0; i < GetQtyPotion(); i++)	
	if(GetPotion(i).code == treatment.potionCode)
	{
		break;
	}
	else if(i == GetQtyPotion() - 1)
	{
		printf("Codigo invalido! \n");
		return;	
	}

	printf("Digite o codigo do paciente: \n");
	printf("-> ");
	scanf("%d", &treatment.patiantCode);

	for(i = 0; i < GetQtyPatiant(); i++)	
	if(GetPatiant(i).code == treatment.patiantCode)
	{
		break;
	}
	else if(i == GetQtyPatiant() - 1)
	{
		printf("Codigo invalido! \n");
		return;	
	}

	printf("Digite a duracao: \n");
	printf("-> ");
	scanf("%d", &treatment.duration);

	printf("Digite a dosagem: \n");
	printf("-> ");
	scanf("%d", &treatment.dosage);

	int successful = TreatmentRegister(treatment);

	if(successful) printf("\nTratamento Cadastrado com sucesso!");
	else printf("\nErro no cadastro. \nTente novamente!");
}

void TreatmentApliation()
{
	int code;

	printf("\nDigite o codigo do tratamento:");
	printf("\n-> ");
	scanf("%d", &code);

	Treatment treatment;
	
	int i;
	for(i = 0; i < GetQtyTreatment(); i++)	
	if(GetTreatment(i).code == code)
	{		
		treatment = GetTreatment(i);
		break;
	}
	else if(i == GetQtyTreatment() - 1)
	{
		printf("\nCodigo invalido!");
		return;	
	}

	printf("\nDigite a nova duracao:");
	printf("\n-> ");
	scanf("%d", &treatment.duration);

	printf("\nDigite a nova dosagem:");
	printf("\n-> ");
	scanf("%d", &treatment.dosage);

	int successful = TreatmentModification(treatment);

	if(successful) printf("\nTratamento Ampliado com sucesso!");
	else printf("\nErro no amplio. \nTente novamente!");

}

void DeleteTreatment()
{
	int code;
	printf("\nDigite o codigo do Tratamento que voce deseja deletar: ");
	printf("-> ");
	scanf("%d", &code);

	int successful = TreatmentRemove(code);

	if(successful) printf("\nTratamento Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
	int cases;
	
	do
	{
		MenuInicial();
		scanf("%d", &cases);	
		
		switch(cases)
		{
			case 1:
				do
				{
					MenuAvancado();
					scanf("%d", &cases);

					switch(cases)
					{
						case 1:
							WitchersList();
							break;
						case 2:
							WitcherRegistration();
							break;
						case 3:
							break;
						case 4:
							DeleteWitcher();
							break;
					}
				}while(cases);	
				
				cases = -1;
				break;
			case 2:
				do
				{
					MenuAvancado();
					scanf("%d", &cases);	
					
					switch(cases)
					{
						case 1:
							PotionsList();
							break;
						case 2:
							PotionRegistration();
							break;
						case 3:
							break;
						case 4:
							DeletePotion();
							break;
					}			
				}while(cases);	
				cases = -1;

				break;
			case 3:
				do
				{
					MenuAvancado();		
					scanf("%d", &cases);	
					switch(cases)
					{
						case 1:
							PatiantsList();
							break;
						case 2:
							PatiantRegistration();
							break;
						case 3:
							break;
						case 4:
							DeleteTreatment();
							break;
					}									
				}while(cases);
				
				cases = -1;
				break;
			case 4:
				do
				{
					MenuTratamento();
					scanf("%d", &cases);	
					switch(cases)
					{
						case 1:
							TreatmentList();
							break;
						case 2:
							break;
						case 3:
							TreatmentRegistration();
							break;
						case 4:
							TreatmentApliation();
							break;
						case 5:
							DeleteTreatment();
							break;
					}									
				}while(cases);

				cases = -1;
				break;
		}
	} while(cases);
	
	return 0;
}

