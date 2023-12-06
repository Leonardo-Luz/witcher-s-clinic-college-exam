#include "paciente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qtyPatiants = 0;

FILE *patiantFile;

int StartPatiants()
{
	patiantFile = fopen("PacienteArq.txt", "r+b");

	if(patiantFile == NULL)
	{
		patiantFile = fopen("PacienteArq.txt", "w+b");	

		if(patiantFile == NULL)
			return 0;
	}

	fseek(patiantFile, 0, SEEK_END);
	
	qtyPatiants = ftell(patiantFile) / sizeof(Patiant);
	
	rewind(patiantFile);

    return 1;
}

int ShutdownPatiants()
{
	fclose(patiantFile);
	
	return 1;
}

int PatiantRegister(Patiant patiant)
{ 
    qtyPatiants++;

	rewind(patiantFile);

	fseek(patiantFile, 0, SEEK_END);
	
	int result;		

	result = fwrite(&patiant, sizeof(Patiant), 1 , patiantFile);
    
    if(!result)
		return 0;
    
    return 1;
}

int PatiantRemove(Patiant patiant)
{
	FILE* temp;

	temp = fopen("temp.txt", "w+b");

	if(temp == NULL)
	{
		return 0;
	}

    int i;

    Patiant tempPatiant;

	rewind(patiantFile);

    for(i = 0; i < qtyPatiants; i++)
    {
    	fread(&tempPatiant , sizeof(Patiant) , 1 , patiantFile );

    	if( tempPatiant.code != patiant.code)
    		fwrite(&tempPatiant, sizeof(Patiant), 1 , temp );
	}

	fclose(patiantFile);

	remove("PacienteArq.txt");

	fclose(temp);

	rename("temp.txt", "PacienteArq.txt");

	patiantFile = fopen("PacienteArq.txt", "r+b");

	if(patiantFile == NULL)
		return 0;

    qtyPatiants--;

    return 1;
}

int PatiantRemoveByCode(int code)
{
	Patiant temp;
	
	if(!GetPatiantByCode(code, &temp))
		return 0;

	PatiantRemove(temp);

    return 1;
}

int PatiantRemoveByName(char* name)
{
	rewind(patiantFile);
	
	Patiant temp;
	
    int i;
    for (i = 0; i < qtyPatiants; i++)
    {	
   		fread(&temp, sizeof(Patiant), 1, patiantFile);
		
        if(strcmp(temp.name , name) == 0)
        {
			PatiantRemove(temp);
            return 1;
        }
    }

    return 0;
}

int GetPatiantByIndice(int indice , Patiant* patiant)
{
    if(indice >= qtyPatiants) return 0;

	rewind(patiantFile);
	
	if( indice != 0 )
		fseek(patiantFile, sizeof(Patiant)*(indice), SEEK_SET);
	
	Patiant temp;
    
	fread(&temp, sizeof(Patiant), 1, patiantFile);

	*patiant = temp;

	return 1;
}

int GetPatiantByCode(int code , Patiant* patiant)
{    
	rewind(patiantFile);

	Patiant temp;

    int i;
    for (i = 0; i < qtyPatiants; i++)
    {	
   		fread(&temp, sizeof(Patiant), 1, patiantFile);
		
        if(temp.code == code)
        {
			*patiant = temp;
            return 1;
        }
    }    
    
    return 0;
}

int GetQtyPatiant()
{
    return qtyPatiants;
}

int PatiantUpdate(Patiant patiant)
{	
	rewind(patiantFile);	
	Patiant tempPatiant;
	
	int i;
	for(i = 0; i < qtyPatiants; i++)
	{
		fread(&tempPatiant, sizeof(Patiant), 1 , patiantFile);
				
		if(tempPatiant.code == patiant.code)
		{
			fseek(patiantFile, sizeof(Patiant)*i, SEEK_SET);

			fwrite(&patiant, sizeof(Patiant), 1, patiantFile);

			return 1;		
		}
	}
	return 0;
}