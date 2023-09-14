#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAMW 3
#define TAMP 3
#define TAMPACIENTE 3
#define TAMT 3

#define TAMC 30

int cases;

int qtdWitch = 0;
char witchName[TAMW][TAMC];
char witchEspecialidade[TAMW][TAMC];
int witchTratando[TAMW];

int qtdPotion = 0;
char potionName[TAMP][TAMC];
char potionType[TAMP][TAMC];
int potionTratando[TAMP];


int qtdPaciente = 0;
char pacienteName[TAMPACIENTE][TAMC];
int pacienteIdade[TAMPACIENTE];
float pacienteAltura[TAMPACIENTE];
int pacienteTratando[TAMPACIENTE];

int qtdTratamentos = 0;
int witchTratamento[TAMT];
int potionTratamento[TAMT];
int pacienteTratamento[TAMT];
int diasTratamento[TAMT];
int dosagemTratamento[TAMT];

void ZerarArrays()
{
	for(int i = 0; i < TAMW; i++)
	{
		strcpy(witchName[i], "");
		strcpy(witchEspecialidade[i], "");
		witchTratando[i] = 0;
	}	
	for(int i = 0; i < TAMP; i++)
	{
		strcpy(potionName[i], "Pocao nao Cadastrada!");
		strcpy(potionType[i], "");		
		potionTratando[i] = 0;
	}
	for(int i = 0; i < TAMPACIENTE; i++)
	{
		strcpy(pacienteName[i], "Paciente nao Cadastrado!");
		pacienteIdade[i] = 0;
		pacienteAltura[i]  = 0;
		pacienteTratando[i] = 0;		
	}
	for(int i = 0; i < TAMT; i++)
	{
		witchTratamento[i]   = -1;
		potionTratamento[i]  = -1;
		pacienteTratamento[i] = -1;
		diasTratamento[i]    = 0;
		dosagemTratamento[i] = 0;
	}	
}

void escolhas()
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

void ListarBruxos()
{
	if(!qtdWitch)
	{
		printf("Nenhum Bruxo Cadastrado! \n \n");
		return;
	}
	
	printf("\n----------------------------------\n");
	for(int i = 0; i < TAMW; i++)
	{
		if(!strcmp(witchName[i], ""))
			printf("Bruxo %d - Bruxo Nao Cadastrado! \n", i);
		else
			printf("Bruxo %d - %s - %s \n", i, witchName[i], witchEspecialidade[i]);
	}
	printf("----------------------------------\n \n");
	
	return;
}

void CadastrarBruxo()
{
	int witchCode = 0;

	printf("Digite o codigo do Bruxo: \n");
	printf("-> ");
	scanf("%d", &witchCode);

	if(witchCode < TAMW && witchCode >= 0) // String ta entrando!
	{
		
		if(strcmp(witchEspecialidade[witchCode], "" ) > 0)
		{
			printf("Ja existe um Bruxo cadastrado neste codigo! \n");
			printf("Voltando ao menu... \n \n");		
		
			return;
		}
		
		
		printf("Digite o nome do Bruxo que voce deseja cadastrar: \n");
		printf("-> ");

		fflush(stdin);
		scanf(" %30[^\n]", &witchName[witchCode]);

		printf("Digite a especialidade deste Bruxo: \n");
		printf("-> ");
		
		fflush(stdin);
		scanf(" %30[^\n]", &witchEspecialidade[witchCode]);

		printf(" \n");

		qtdWitch++;

		return;
	}
	else
	{
		printf("codigo Invalido! \n");
		printf("Voltando ao menu... \n \n");

		return;			
	}	
}

void ExcluirBruxo()
{

	int temp = 0;
	
	if(!qtdWitch)
	{
		printf("Nenhum Bruxo Cadastrado! \n \n");
		return;
	}
	
	ListarBruxos();
	
	int witchToDelete = 0;
	printf("Qual Bruxo voce deseja excluir ? [0 - %d] \n", TAMW-1);
	printf("-> ");
	scanf("%d", &witchToDelete);
	if(witchToDelete >= TAMW || witchToDelete < 0)
	{
		printf("Valor Invalido! \n");
		printf("Voltando ao menu... \n \n");
		return;
	}
	
	for(int i = 0; i < TAMT; i++)
	{
		if(witchTratamento[i] == witchToDelete)
		{
			printf("Este Bruxo esta Tratando! \n\n");
			return;				
		}
	}
	
	if(strcmp(witchEspecialidade[witchToDelete], "") == 0)
	{
		printf("Bruxo Nao Cadastrado! \n\n");
		return;
	}
	
	strcpy(witchName[witchToDelete], "");
	strcpy(witchEspecialidade[witchToDelete], "");
		
	qtdWitch--;	

	printf("Bruxo Deletado! \n\n");

	return;	
}

void ListarPocoes()
{
	if(!qtdPotion)
	{
		printf("Nenhuma Pocao Cadastrada! \n \n");
		return;
	}
	
	printf("\n----------------------------------\n");
	
	for(int i = 0; i < TAMP; i++)
	{
		printf("Pocao %d - %s - %s \n", i, potionName[i], potionType[i]);
	}
	
	printf("----------------------------------\n \n");
	
	return;	
}

void CadastrarPocao()
{
	int potionCode = 0;

	printf("Digite o codigo da Pocao: \n");
	printf("-> ");
	scanf("%d", &potionCode);	
	
	if(potionCode < TAMW && potionCode >= 0)
	{
		
		if(strcmp(potionType[potionCode] , "" ) > 0)
		{
			printf("Ja existe uma Pocao cadastrado neste codigo! \n");
			printf("Voltando ao menu... \n \n");
			
			return;		
		}
		
		
		printf("Digite o nome da Pocao que voce deseja cadastrar: \n");
		printf("-> ");

		fflush(stdin);
		scanf(" %30[^\n]", &potionName[potionCode]);

		printf("Digite o tipo desta Pocao: \n 0 - Comprimido \n 1 - Liquido \n");
		printf("-> ");

		int potionTypeTemp = 0;
			
		scanf("%d", &potionTypeTemp);
		
		if(potionTypeTemp == 0)
			strcpy(potionType[potionCode] , "Comprimido");
		else if(potionTypeTemp == 1)
			strcpy(potionType[potionCode] , "Liquido");
		else
		{
			printf("codigo Inv�lido! \n");
			strcpy(potionName[potionCode], "");
			return;
		}
		
		qtdPotion++;
		return;
	}
	else
	{
		printf("codigo Inv�lido! \n");
		printf("Voltando ao menu... \n \n");

		return;			
	}	
}

void ExcluirPocao()
{
	if(!qtdPotion)
	{
		printf("Nenhuma Pocao Cadastrada! \n \n");
		return;
	}
	
	ListarPocoes();
	
	int potionToDelete = 0;
	printf("Qual Pocao voce deseja excluir ? [0 - %d] \n", TAMP-1);
	scanf("%d", &potionToDelete);
	if(potionToDelete >= TAMP || potionToDelete < 0)
	{
		printf("Valor Inv�lido! \n");
		printf("Voltando ao menu... \n \n");
		return;
	}
	
	for(int i = 0; i < TAMT; i++)
	{
		if(potionTratamento[i] == potionToDelete)
		{
			printf("Esta Pocao esta sendo usada em um Tratamento! \n\n");
			
			return;				
		}
	}

	if(strcmp(potionName[potionToDelete] , "") == 0)
	{
		printf("Pocao Nao Cadastrada! \n\n");
		return;
	}
	strcpy(potionName[potionToDelete], "Pocao nao Cadastrada!");
	strcpy(potionType[potionToDelete], "");
		
	qtdPotion--;
	
	printf("Pocao Deletada! \n\n");	
	return;	
}

void ListarPacientes()
{
	if(!qtdPaciente)
	{
		printf("Nenhum Paciente Cadastrado! \n \n");
		return;
	}
	
	printf("\n----------------------------------\n");
	
	for(int i = 0; i < TAMP; i++)
	{
		printf("Paciente %d - %s - %d - %.2f \n", i, pacienteName[i], pacienteIdade[i], pacienteAltura[i]);
	}
	
	printf("----------------------------------\n \n");
	
	return;	
}

void CadastrarPaciente()
{
	int pacienteCode = 0;

	printf("Digite o codigo do Paciente: \n");
	printf("-> ");
	scanf("%d", &pacienteCode);
	
	if(pacienteCode < TAMPACIENTE && pacienteCode >= 0) // String ta entrando!
	{
		
		if(pacienteIdade[pacienteCode] > 0)
		{
			printf("J� existe um Paciente cadastrado neste codigo! \n");
			printf("Voltando ao menu... \n \n");
			
			return;		
		}		
		
		printf("Digite o nome do Paciente que voc� deseja cadastrar: \n");
		printf("-> ");

		fflush(stdin);
		scanf(" %30[^\n]", &pacienteName[pacienteCode]);

		printf("Digite a idade deste Paciente: \n");
		printf("-> ");
		
		scanf("%d", &pacienteIdade[pacienteCode]);

		printf("Digite a altura deste Paciente: \n");
		printf("-> ");

		scanf("%f", &pacienteAltura[pacienteCode]);
		
		qtdPaciente++;

		return;
	}
	else
	{
		printf("codigo Inv�lido! \n");
		printf("Voltando ao menu... \n\n");

		return;			
	}	
}

void ExcluirPaciente()
{
	if(!qtdPaciente)
	{
		printf("Nenhumo Paciente Cadastrado! \n \n");
		return;
	}
	
	ListarPacientes();
	
	int pacienteToDelete = 0;
	
	printf("Qual Paciente voce deseja excluir ? [0 - %d] \n", TAMPACIENTE-1);
	printf("-> ");	
	scanf("%d", &pacienteToDelete);
	
	if(pacienteToDelete >= TAMPACIENTE || pacienteToDelete < 0)
	{
		printf("Valor Invalido! \n");
		printf("Voltando ao menu... \n\n");
		return;
	}
	
	for(int i = 0; i < TAMT; i++)
	{
		if(pacienteTratamento[i] == pacienteToDelete)
		{
			printf("Este Paciente esta Tratando! \n\n");
			return;				
		}
	}
	
	if(pacienteIdade[pacienteToDelete] == 0)
	{
		printf("Paciente nao Cadastrado! \n\n");
		return;
	}
	
	strcpy(pacienteName[pacienteToDelete], "Paciente nao Cadastrado!");
	pacienteIdade[pacienteToDelete] = 0;
	pacienteAltura[pacienteToDelete] = 0;

	qtdPaciente--;	
	
	printf("Paciente deletado! \n\n");
	return;	
}

void ListarTratamentos()
{
	int code = 0;
	if(!qtdTratamentos)
	{
		printf("Nenhum Tratamento Cadastrado! \n \n");
		return;
	}

	printf("Digite o codigo do Paciente: \n");
	printf("-> ");
	
	scanf("%d", &code);

	if(code < 0 || code >= TAMPACIENTE)
	{
		printf("Valor Invalido! \n");
		printf("Voltando ao menu... \n\n");
		return;		
	}

	for(int i = 0; i < TAMT; i++)
	{
		if(pacienteTratamento[i] == code)
		{
			printf("\n----------------------------------\n");	

			printf("%s - %s - %s - %d - %d \n", witchName[witchTratamento[i]], pacienteName[pacienteTratamento[i]], potionName[potionTratando[i]] , diasTratamento[i] , dosagemTratamento[i] );		

			printf("----------------------------------\n\n");
			return;
		}
		else if(i == TAMT -1)
		{
			printf("Este Paciente Nao possui Tratamentos! \n \n");
			return;			
		}		
	}
	
}

void ListarPacientesDoBruxo()
{
	int code = 0;
	if(!qtdWitch)
	{
		printf("Nenhum Bruxo Cadastrado! \n \n");
		return;
	}

	printf("Digite o Codigo do Bruxo: \n");
	printf("-> ");
	
	scanf("%d", &code);

	if(code < 0 || code >= TAMW)
	{
		printf("Valor Invalido! \n");
		printf("Voltando ao menu... \n\n");
		return;		
	}
	
	if(!witchTratando[code])
	{
		printf("Bruxo sem Pacientes! \n");
		printf("Voltando ao menu... \n\n");
		return;				
	}

	printf("\n----------------------------------\n");	

	for(int i = 0; i < TAMT; i++)
	{
		if(witchTratamento[i] == code)
		{
			printf("Paciente %d - %s - %d - %.2f \n", i, pacienteName[pacienteTratamento[i]], pacienteIdade[pacienteTratamento[i]], pacienteAltura[pacienteTratamento[i]]);			
		}
	}
	
	printf("----------------------------------\n\n");
	
}

void IniciarTratamento()
{
	int bruxoCode 		= 0;
	int pocaoCode 		= 0;
	int pacienteCode 	= 0;
	
	printf("Digite o Codigo do Bruxo: \n");
	printf("-> ");
	scanf("%d", &bruxoCode);
	
	if(bruxoCode >= TAMW || bruxoCode < 0)
	{
		printf("Codigo Invalido! \n");
		printf("Voltando ao menu... \n");

		return;
	}
	else if(strcmp(witchEspecialidade[bruxoCode] , "") == 0)
	{
		printf("Bruxo nao cadastrado! \n");
		printf("Voltando ao menu... \n");

		return;		
	}
	
	printf("Digite o Codigo do Paciente: \n");
	printf("-> ");
	scanf("%d", &pacienteCode);
	
	if(pacienteCode >= TAMPACIENTE || pacienteCode < 0)
	{
		printf("Codigo Invalido! \n");
		printf("Voltando ao menu... \n\n");

		return;
	}
	else if(pacienteIdade[pacienteCode] == 0)
	{
		printf("Paciente nao Cadastrado! \n");
		printf("Voltando ao menu... \n\n");

		return;		
	}
	else if(pacienteTratando[pacienteCode] > 0)
	{
		printf("Este Paciente ja esta em Tratamento! \n");
		printf("Voltando ao menu... \n\n");

		return;
	}
	

	printf("Digite o Codigo da Pocao: \n");
	printf("-> ");
	scanf("%d", &pocaoCode);
	
	if(pocaoCode >= TAMP || pocaoCode < 0)
	{
		printf("Codigo Invalido! \n");
		printf("Voltando ao menu... \n");

		return;
	}
	else if(strcmp(potionType[pocaoCode] , "") == 0)
	{
		printf("Pocao nao cadastrado! \n");
		printf("Voltando ao menu... \n");

		return;		
	}
	
	for(int i = 0; i < TAMT; i++)
	{
		if(diasTratamento[i] == 0)
		{
			printf("Digite os Dias do Tratamento: \n");
			printf("-> ");
			scanf("%d", &diasTratamento[i]);
			
			if(diasTratamento[i] == 0)
			{
				printf("Numero Invalido! \n");
				printf("Voltando ao menu... \n");
		
				return;		
			}
			
			printf("Digite a Dosagem do Tratamento: \n");
			printf("-> ");
			scanf("%d", &dosagemTratamento[i]);
			
			witchTratamento[i] 		= bruxoCode;
			potionTratamento[i] 	= pocaoCode;
			pacienteTratamento[i]	= pacienteCode;
			
			witchTratando[bruxoCode]			++;
			potionTratando[pocaoCode]	  		++;
			pacienteTratando[pacienteCode]		++;

			qtdTratamentos ++;
			
			return;
		}
	}
				
}

void AmpliarTratamento()
{
	int code = 0;
	
	if(!qtdTratamentos)
	{
		printf("Nenhumo Tratamento Cadastrado! \n \n");
		return;
	}
	else
	{
		printf("Digite o Cogido do Tratamento: \n");
		printf("-> ");
		
		scanf("%d", &code);
		
		if(code >= TAMT || code < 0)
		{
			printf("Codigo Invalido! \n\n");
			return;
		}
		
		int maisDias = 0;
		
		if((dosagemTratamento[code] == 0))
		{
			printf("Tratamento Nao Cadastrado! \n\n");
			return;
		}

		printf("Digite em quantos dias voce deseja Ampliar o Tratamento: \n");
		printf("-> ");
		scanf("%d", &maisDias);

		diasTratamento[code] += maisDias;
	}
}

void ApagarTratamento()
{
	int code = 0;
	
	if(!qtdTratamentos)
	{
		printf("Nenhumo Tratamento Cadastrado! \n \n");
		return;
	}
	else
	{
		printf("Digite o Codigo do Tratamento: \n");
		printf("-> ");
		
		scanf("%d", &code);

		if(code >= TAMT || code < 0)
		{
			printf("Codigo Invalido! \n\n");
			return;
		}
		
		if((dosagemTratamento[code] == 0))
		{
			printf("Tratamento Nao Cadastrado! \n\n");
			return;
		}
		
		diasTratamento[code] 						=	0;
		dosagemTratamento[code] 					= 	0;
		pacienteTratamento[code] 					= 	-1;
		witchTratamento[code] 						= 	-1;
		potionTratamento[code]						= 	-1;
		
		witchTratando[witchTratamento[code]]			--;
		potionTratando[potionTratamento[code]]  		--;
		pacienteTratando[pacienteTratamento[code]]		--;
		
		qtdTratamentos --;
		
		printf("Tratamento Deletado! \n\n");
		
		return;
	}
}

int main(int argc, char *argv[]) {

	int loop = 0;

	ZerarArrays();

	setlocale(LC_ALL, "Portuguese"); //Usar Virgula ao dar input em casas decimais!
	
	do
	{
		escolhas();
		
		switch(cases)
		{
			case 0:
				printf("Saindo...");
				loop++;				
				break;
				
			case 1:
				ListarBruxos();
				break;
				
			case 2:
				CadastrarBruxo();
				break;
				
			case 3:
				ExcluirBruxo();		
				break;
				
			case 4:
				ListarPocoes();
				break;
				
			case 5:
				CadastrarPocao();
				break;
				
			case 6:
				ExcluirPocao();
				break;
				
			case 7:
				ListarPacientes();
				break;
			
			case 8:
				CadastrarPaciente();
				break;
			
			case 9:
				ExcluirPaciente();
				break;
			
			case 10:
				ListarTratamentos();
				break;
			
			case 11:
				ListarPacientesDoBruxo();
				break;
			
			case 12:
				IniciarTratamento();
				break;
				
			case 13:
				AmpliarTratamento();
				break;
			
			case 14:
				ApagarTratamento();
				break;
				
			default:
				printf("Opcao invalida...Tente novamente! \n \n");
		}
	}while(!loop);

	return 0;
}
