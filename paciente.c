#include "bruxo.h"
#include <stdlib.h>
#include <string.h> //debug

int TAM = 5;
int qtyPatiants = 0;

Patiant* Patiants = NULL;

int StartPatiants()
{
    Patiants = (Patiant*) malloc(TAM * sizeof(Patiant));

	qtyPatiants = 3;

	Patiants[0].code = 1;
	strcpy(Patiants[0].especiality, "Roberto") ;
	strcpy(Patiants[0].name, "Carlos");
	
	Patiants[1].code = 2;
	strcpy(Patiants[1].especiality, "Leonardo") ;
	strcpy(Patiants[1].name, "Carlos");

	Patiants[2].code = 3;
	strcpy(Patiants[2].especiality, "Diego") ;
	strcpy(Patiants[2].name, "Carlos");

    return 1;		
}

int ShutdownPatiants()
{
	free(Patiants);
	return 1;
}

//register
int PatiantRegister(Patiant Patiant)
{
    Patiant* PatiantAllocTemp = NULL;

    Patiants[qtyPatiants] = Patiant;
 
     qtyPatiants++;
    
	if(qtyPatiants == TAM)
	{
		TAM += 5;
    	PatiantAllocTemp = (Patiant*) realloc(Patiants , TAM * sizeof(Patiant));

	    if(PatiantAllocTemp == NULL)
	    {
	    	qtyPatiants--;
	    	TAM -= 5;
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

	if(TAM != 5 && qtyPatiants < TAM -5 )
	{
		TAM -= 5;
        PatiantAllocTemp = (Patiant*) realloc(Patiants , TAM * sizeof(Patiant));	            

        if(PatiantAllocTemp == NULL)
        {
            qtyPatiants++;
            TAM += 5;
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

//qty receive
int GetQtyPatiant()
{
    return qtyPatiants;
}

int PatiantUpdate()
{
	
}

