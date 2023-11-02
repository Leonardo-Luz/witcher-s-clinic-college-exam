#include "paciente.h"
#include <stdlib.h>
#include <string.h> //debug

int TAM_PATIANT = 5;
int qtyPatiants = 0;

Patiant* Patiants = NULL;

int StartPatiants()
{
    Patiants = (Patiant*) malloc(TAM_PATIANT * sizeof(Patiant));

//  debug
//	qtyPatiants = 3;
//
//	Patiants[0].code = 1;
//    Patiants[0].age = 999;
//    Patiants[0].height = 111.80;    
//	strcpy(Patiants[0].name, "Carlos");
//	
//	Patiants[1].code = 2;
//    Patiants[1].age = 23;
//    Patiants[1].height = 1.20;    
//	strcpy(Patiants[1].name, "Diego");
//
//	Patiants[2].code = 3;
//    Patiants[2].age = 21;
//    Patiants[2].height = 1.90;    
//	strcpy(Patiants[2].name, "Leonardo");

    return 1;		
}

int ShutdownPatiants()
{
	free(Patiants);
	return 1;
}

//register
int PatiantRegister(Patiant patiant)
{
    Patiant* PatiantAllocTemp = NULL;

    Patiants[qtyPatiants] = patiant;
 
     qtyPatiants++;
    
	if(qtyPatiants == TAM_PATIANT)
	{
		TAM_PATIANT += 5;
    	PatiantAllocTemp = (Patiant*) realloc(Patiants , TAM_PATIANT * sizeof(Patiant));

	    if(PatiantAllocTemp == NULL)
	    {
	    	qtyPatiants--;
	    	TAM_PATIANT -= 5;
	        return 0;
		}

	    Patiants = PatiantAllocTemp;
	}
    
    return 1;
}

int PatiantRemove(int indice)
{
    Patiant* PatiantAllocTemp = NULL;	
	
    qtyPatiants--;

    Patiants[indice] = Patiants[qtyPatiants];

	if(TAM_PATIANT != 5 && qtyPatiants < TAM_PATIANT -5 )
	{
		TAM_PATIANT -= 5;
        PatiantAllocTemp = (Patiant*) realloc(Patiants , TAM_PATIANT * sizeof(Patiant));	            

        if(PatiantAllocTemp == NULL)
        {
            qtyPatiants++;
            TAM_PATIANT += 5;
            return 0;
        }

        Patiants = PatiantAllocTemp;
	}		
}

//remove
int PatiantRemoveByCode(int code)
{
    int i;

    for (i = 0; i < qtyPatiants; i++)
    {
        if(Patiants[i].code == code)
        {
			PatiantRemove(i);

            return 1;
        }
    }    
    
    return 0;
}

int PatiantRemoveByName(char* name)
{
    int i;

    for (i = 0; i < qtyPatiants; i++)
    {
        if(strcmp(Patiants[i].name, name)== 0)
        {
        	PatiantRemove(i);
            return 1;
        }
    }    
    return 0;
}

//receive
Patiant GetPatiantByIndice(int indice)
{
    if(indice > qtyPatiants) return;
    
    return Patiants[indice];
}

Patiant GetPatiantByCode(int code)
{    
	Patiant patiant;
	patiant.code = -1;

    int i;

    for (i = 0; i < qtyPatiants; i++)
    {
        if(Patiants[i].code == code)
        {
            return Patiants[i];
        }
    }    
    
    return patiant;
}

//qty receive
int GetQtyPatiant()
{
    return qtyPatiants;
}

int PatiantUpdate(Patiant patiant)
{
	int i;
	
	for(i = 0; i < qtyPatiants; i++)
	if(Patiants[i].code == patiant.code)
	{
		strcpy(Patiants[i].name, patiant.name);
		Patiants[i].height = patiant.height;
		Patiants[i].age = patiant.age;
	
		return 1;
	}
	
	return 0;	
}

