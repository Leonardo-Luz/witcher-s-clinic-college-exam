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
	printf("\n0  - Voltar");
	printf("\n1  - Listar");
	printf("\n2  - Cadastrar");
	printf("\n3  - Alterar");
	printf("\n4  - Excluir por Codigo");
	printf("\n5  - Excluir por Nome");
	
	printf("\n-> ");
}

void MenuTratamento()
{
	printf("\nMenu: ");
	printf("\n0  - Voltar");
	printf("\n1  - Listar tratamentos do paciente");
	printf("\n2  - Listar tratamentos do bruxo");
	printf("\n3  - Iniciar tratamento");
	printf("\n4  - Ampliar tratamento");
	printf("\n5  - Excluir tratamento");
			
	printf("\n-> ");
}

void Start()
{
	if(StartWitchers() != 1 || StartPatiants() != 1 || StartPotions() != 1 || StartTreatments() != 1)
	{
		printf("\nErro ao allocar a memoria!");
	}
}

void End()
{
	ShutdownWitchers();
	ShutdownPatiants();
	ShutdownPotions();
	ShutdownTreatments();
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
		Witcher witcher;
		if(!GetWitcherByIndice(i, &witcher))
		{
			printf("Indice Invalido");
			return;
		}

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
	
	if(witcher.code < 0 || GetWitcherByCode(witcher.code , &witcher) == 1)
	{
		printf("\nCodigo invalido!");
		return;
	}

	printf("\nDigite o nome do bruxo: ");
	printf("-> ");
	scanf(" %[^\n]s", &witcher.name);
	
	printf("\nDigite a especialidade do bruxo: ");
	printf("-> ");
	scanf(" %[^\n]s", &witcher.especiality);

	int successful = WitcherRegister(witcher);

	if(successful) printf("\nBruxo Cadastrado com sucesso!");
	else printf("\nErro no cadastro. \nTente novamente!");
}

int witcherIsTreating( int code )
{
	int i;
	
	Treatment treatment;
	
	for(i = 0; i < GetQtyTreatment(); i++)
	{
		if(GetTreatmentByIndice(i , &treatment) == 0)
		{
			printf("\nIndice invalido");
			return 0;
		}
		
		if(treatment.witcherCode == code)
			return 1;
	}
	
	return 0;
}

void DeleteWitcherCode()
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

	if(witcherIsTreating( code ) == 1)
	{
		printf("\nBruxo esta sendo usada em um tratamento!");
		return;
	}
	
	int successful = WitcherRemoveByCode(code);

	if(successful) printf("\nBruxo Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

int witcherNameIsTreating( char* name )
{
	int i;
	
	Treatment treatment;
	Witcher witcher;
	
	for(i = 0; i < GetQtyTreatment(); i++)
	{
		if(GetTreatmentByIndice(i , &treatment) == 0)
		{
			printf("\nIndice invalido");
			return 0;
		}
	
		if(GetWitcherByCode(treatment.witcherCode , &witcher) == 0)
		{
			printf("\nCodigo invalido");
			return 0;
		}
		
		if(strcmp(witcher.name, name) == 0)
			return 1;
	}
	
	return 0;
}

void DeleteWitcherName()
{	
	if(GetQtyWitcher() == 0)
	{
		printf("\nSem Bruxo!");
		return;
	}
	
	
	char name[100];
	printf("\nDigite o nome do bruxo que voce deseja deletar: ");
	printf("-> ");
	scanf(" %[^\n]s", &name);

	if(witcherNameIsTreating( name ) == 1)
	{
		printf("\nBruxo esta sendo usada em um tratamento!");
		return;
	}
	
	int successful = WitcherRemoveByName(name);

	if(successful) printf("\nBruxo Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

void WitcherUpd()
{
	if(GetQtyWitcher() == 0)
	{
		printf("\nSem Bruxo!");
		return;
	}
	
	Witcher witcher;

	printf("\nDigite o codigo do bruxo que deseja atualizar: ");
	printf("-> ");
	scanf("%d", &witcher.code);

	if(GetWitcherByCode(witcher.code, &witcher) == 0)
	{
		printf("\nCodigo invalido!");
		return;
	}

	printf("\nDigite o nome do bruxo: ");
	printf("-> ");
	scanf(" %[^\n]s", &witcher.name);
	
	printf("\nDigite a especialidade do bruxo: ");
	printf("-> ");
	scanf(" %[^\n]s", &witcher.especiality);

	int successful = WitcherUpdate(witcher);

	if(successful) printf("\nBruxo Atualizado com sucesso!");
	else printf("\nErro na atualizacao. \nTente novamente!");
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
		Potion potion;
		
		if(GetPotionByIndice(i , &potion) == 0)
		{
			printf("\nIndice invalido!");
			return;
		}

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
	
	if(potion.code < 0 || GetPotionByCode(potion.code, &potion) == 1)
	{
		printf("\nCodigo invalido!");
		return;
	}

	printf("\nDigite o nome da pocao: ");
	printf("-> ");
	scanf(" %[^\n]s", &potion.name);

	printf("\nDigite o tipo da pocao: ");
	printf("-> ");
	scanf(" %[^\n]s", &potion.type);

	int successful = PotionRegister(potion);

	if(successful) printf("\nPocao Cadastrada com sucesso!");
	else printf("\nErro no cadastro. \nTente novamente!");
}

int potionIsTreating( int code )
{
	int i;
	
	Treatment treatment;
	
	for(i = 0; i < GetQtyTreatment(); i++)
	{
		if(GetTreatmentByIndice(i , &treatment) == 0)
		{
			printf("\nIndice invalido");
			return 0;
		}
		
		if(code == treatment.potionCode)
			return 1;
	}
	
	return 0;
}

void DeletePotionCode()
{
	int code;
	printf("\nDigite o codigo da pocao que voce deseja deletar: ");
	printf("-> ");
	scanf("%d", &code);
	
	if(potionIsTreating(code) == 1)
	{
		printf("\nPocao esta sendo usada em um tratamento!");
		return;
	}

	int successful = PotionRemoveByCode(code);

	if(successful) printf("\nPocao Removida com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

int potionNameIsTreating( char* name )
{
	int i;
	
	Treatment treatment;
	Potion potion;
	
	for(i = 0; i < GetQtyTreatment(); i++)
	{
		if(GetTreatmentByIndice(i , &treatment) == 0)
		{
			printf("\nIndice invalido");
			return 0;
		}
	
		if(GetPotionByCode(treatment.potionCode , &potion) == 0)
		{
			printf("\nCodigo invalido");
			return 0;
		}
		
		if(strcmp(potion.name, name) == 0)
			return 1;
	}
	
	return 0;
}

void DeletePotionName()
{
	char name[100];
	printf("\nDigite o nome da pocao que voce deseja deletar: ");
	printf("-> ");
	scanf(" %[^\n]s", &name);

	if(potionNameIsTreating( name ) == 1)
	{
		printf("\nPocao esta sendo usada em um tratamento!");
		return;
	}

	int successful = PotionRemoveByName(name);

	if(successful) printf("\nPocao Removida com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

void PotionUpd()
{
	if(GetQtyPotion() == 0)
	{
		printf("\nSem pocao!");
		return;
	}
	
	Potion potion;

	printf("\nDigite o codigo da pocao que deseja atualizar: ");
	printf("-> ");
	scanf("%d", &potion.code);

	if(GetPotionByCode(potion.code , &potion) == 0)
	{
		printf("\nCodigo invalido!");
		return;
	}

	printf("\nDigite o nome da pocao: ");
	printf("-> ");
	scanf(" %[^\n]s", &potion.name);
	
	printf("\nDigite a tipo da pocao: ");
	printf("-> ");
	scanf(" %[^\n]s", &potion.type);

	int successful = PotionUpdate(potion);

	if(successful) printf("\nPocao Atualizada com sucesso!");
	else printf("\nErro na atualizacao. \nTente novamente!");
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
		Patiant patiant;
		
		if(GetPatiantByIndice(i , &patiant) == 0)
		{
			printf("\nIndice invalido");
			return;
		}

		printf("\n %d - %s - %d - %.2f ", 
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

	if(patiant.code < 0 || GetPatiantByCode(patiant.code , &patiant) == 1)
	{
		printf("\nCodigo invalido!");
		return;
	}

	printf("\nDigite o nome do paciente: ");
	printf("-> ");
	scanf(" %[^\n]s", &patiant.name);

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

int PatiantIsTreating( int code )
{
	int i;
	
	Treatment treatment;
	
	for(i = 0; i < GetQtyTreatment(); i++)
	{
		if(GetTreatmentByIndice(i , &treatment) == 0)
		{
			printf("\nIndice invalido");
			return 0;
		}

		
		if(treatment.patiantCode == code)
			return 1;
	}
	
	return 0;
}

void DeletePatiantCode()
{
	int code;
	printf("\nDigite o codigo do paciente que voce deseja deletar: ");
	printf("-> ");
	scanf("%d", &code);
	
	if(PatiantIsTreating( code ) == 1)
	{
		printf("\nPaciente esta sendo usada em um tratamento!");
		return;
	}

	int successful = PatiantRemoveByCode(code);

	if(successful) printf("\nPaciente Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

int patiantNameIsTreating( char* name )
{
	int i;
	
	Treatment treatment;
	Patiant patiant;
	
	for(i = 0; i < GetQtyTreatment(); i++)
	{
		if(GetTreatmentByIndice(i , &treatment) == 0)
		{
			printf("\nIndice invalido");
			return 0;
		}
	
		if(GetPatiantByCode(treatment.patiantCode , &patiant) == 0)
		{
			printf("\nCodigo invalido");
			return 0;
		}
		
		if(strcmp(patiant.name, name) == 0)
			return 1;
	}
	
	return 0;
}

void DeletePatiantName()
{
	if(GetQtyPatiant() == 0)
	{
		printf("\nNenhum Paciente Cadastrado");
		return;
	}
	
	
	char name[100];
	printf("\nDigite o nome do paciente que voce deseja deletar: ");
	printf("-> ");
	scanf(" %[^\n]s", &name);

	if(patiantNameIsTreating( name ) == 1)
	{
		printf("\nPaciente esta sendo usada em um tratamento!");
		return;
	}

	int successful = PatiantRemoveByName(name);

	if(successful) printf("\nPaciente Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

void PatiantUpd()
{
	if(GetQtyPatiant() == 0)
	{
		printf("\nSem Paciente!");
		return;
	}
	
	Patiant patiant;

	printf("\nDigite o codigo do paciente: ");
	printf("-> ");
	scanf("%d", &patiant.code);

	if(GetPatiantByCode(patiant.code , &patiant) == 0)
	{
		printf("\nCodigo invalido!");
		return;
	}

	printf("\nDigite o nome do paciente: ");
	printf("-> ");
	scanf(" %[^\n]s", &patiant.name);

	printf("\nDigite a idade do paciente: ");
	printf("-> ");
	scanf("%d", &patiant.age);

	printf("\nDigite a altura do paciente: ");
	printf("-> ");
	scanf("%f", &patiant.height);

	int successful = PatiantUpdate(patiant);

	if(successful) printf("\nPaciente Atualizado com sucesso!");
	else printf("\nErro na atualizacao. \nTente novamente!");
}

void TreatmentListPacient()
{
	int i;

	if(GetQtyTreatment() == 0)
	{
		printf("\nSem Tratamentos!");
		return;
	}
	
	int code;
	
	printf("\nDigite o codigo do paciente");
	printf("\n-> ");
	scanf("%d", &code);
	
	Patiant patiant;
	
	if(GetPatiantByCode(code , &patiant) == 0)
	{
		printf("Indice invalido");
	}
	
	if(patiant.code != code || code < 0)
	{
		printf("Codigo invalido! \n");
		return;	
	}
	
	for (i = 0; i < GetQtyTreatment(); i++)
	{
		Treatment treatment;
		
		if(GetTreatmentByIndice(i , &treatment) == 0 )
		{
			printf("\nIndice invalido");
			return;
		}
				
		if(patiant.code == treatment.patiantCode)
		{
			break;
		}
		
		if(i == GetQtyTreatment() - 1)
		{
			printf("\nPaciente sem tratamento!");
			return;
		}
	}	
	
	printf("\n\nCode - Nome Bruxo - Nome Pocao - Nome Paciente - Duracao - Dosagem ");
	for (i = 0; i < GetQtyTreatment(); i++)
	{
		Treatment treatment;
		
		if(GetTreatmentByIndice(i , &treatment) == 0 )
		{
			printf("\nIndice invalido");
			return;
		}

		Witcher witcher;
		
		if(GetWitcherByCode(treatment.witcherCode , &witcher) == 0 )
		{
			printf("\nCodigo invalido");
			return;
		}
		
		Potion potion;
		
		if(GetPotionByCode(treatment.potionCode , &potion) == 0 )
		{
			printf("\nCodigo invalido");
			return;
		}

		Patiant patiant;
		
		if(GetPatiantByCode(treatment.patiantCode , &patiant) == 0 )
		{
			printf("\nCodigo invalido");
			return;
		}				
		
		if(treatment.witcherCode == code)
		printf("\n %d - %s - %s - %s - %d - %d ", 
			treatment.code,
			witcher.name,
			potion.name,
			patiant.name,
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

	Witcher witcher;
	
	if(GetWitcherByCode(code, &witcher) == 0)
	{
		printf("Codigo invalido! \n");
		return;	
	}
	
	for (i = 0; i < GetQtyTreatment(); i++)
	{
		Treatment treatment;
		
		if(GetTreatmentByIndice(i , &treatment) == 0 )
		{
			printf("\nIndice invalido");
			return;
		}
				
		if(witcher.code == treatment.witcherCode)
		{
			break;
		}
		
		if(i == GetQtyTreatment() - 1)
		{
			printf("\nbruxo sem tratamento!");
			return;
		}
	}

	printf("\n\nCode - Nome Bruxo - Nome Pocao - Nome Paciente - Duracao - Dosagem ");
	for (i = 0; i < GetQtyTreatment(); i++)
	{
		Treatment treatment;
		
		if(GetTreatmentByIndice(i , &treatment) == 0 )
		{
			printf("\nIndice invalido");
			return;
		}
		
		Potion potion;
		
		if(GetPotionByCode(treatment.potionCode , &potion) == 0 )
		{
			printf("\nCodigo invalido");
			return;
		}

		Patiant patiant;
		
		if(GetPatiantByCode(treatment.patiantCode , &patiant) == 0 )
		{
			printf("\nCodigo invalido");
			return;
		}				
		
		if(treatment.witcherCode == code)
		printf("\n %d - %s - %s - %s - %d - %d ", 
			treatment.code,
			witcher.name,
			potion.name,
			patiant.name,
			treatment.duration,
			treatment.dosage			
		);
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

	Treatment treatment;

	printf("Digite o codigo do tratamento: \n");
	printf("-> ");
	scanf("%d", &treatment.code);

	if(treatment.code < 0 || GetTreatmentByCode(treatment.code, &treatment) == 1)
	{
		printf("\nCodigo invalido!");
		return;
	}

	WitchersList();	
	printf("\n\nDigite o codigo do bruxo: \n");
	printf("-> ");
	scanf("%d", &treatment.witcherCode);

	Witcher witcher;

	if(GetWitcherByCode(treatment.witcherCode , &witcher) == 0)
	{
		printf("Codigo invalido! \n");
		return;	
	}

	PotionsList();
	printf("\n\nDigite o codigo da pocao: \n");
	printf("-> ");
	scanf("%d", &treatment.potionCode);

	Potion potion;
	
	if(GetPotionByCode(treatment.potionCode , &potion) == 0)
	{
		printf("Codigo invalido! \n");
		return;	
	}
	
	if(potion.code != treatment.potionCode)
	{
		printf("Codigo invalido! \n");
		return;	
	}

	PatiantsList();
	printf("\nDigite o codigo do paciente: \n");
	printf("-> ");
	scanf("%d", &treatment.patiantCode);

	Patiant patiant;
	
	if(GetPatiantByCode(treatment.patiantCode , &patiant) == 0)
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
	if(GetQtyTreatment() == 0)
	{
		printf("\nSem Tratamentos!");
		return;
	}

	int code;

	printf("\nDigite o codigo do tratamento:");
	printf("\n-> ");
	scanf("%d", &code);

	Treatment treatment;
	
	if(GetTreatmentByCode(code , &treatment) == 0)
	{
		printf("Codigo invalido! \n");
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
	if(GetQtyTreatment() == 0)
	{
		printf("\nSem Tratamentos!");
		return;
	}
	
	int code;
	printf("\nDigite o codigo do Tratamento que voce deseja deletar: ");
	printf("\n-> ");
	scanf(" %d", &code);

	int successful = TreatmentRemoveByCode(code);

	if(successful) printf("\nTratamento Removido com sucesso!");
	else printf("\nErro na remocao. \nTente novamente!");
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
	Start();
	
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
							WitcherUpd();
							break;
						case 4:
							DeleteWitcherCode();
							break;
						case 5:
							DeleteWitcherName();
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
							PotionUpd();
							break;
						case 4:
							DeletePotionCode();
							break;
						case 5:
							DeletePotionName();
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
							PatiantUpd();
							break;
						case 4:
							DeletePatiantCode();
							break;
						case 5:
							DeletePatiantName();
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
							TreatmentListPacient();
							break;
						case 2:
							WitcherPatiantsList();
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
	
	End();
	
	return 0;
}
