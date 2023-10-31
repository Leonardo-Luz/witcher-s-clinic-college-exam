#include "bruxo.h"
#include <stdlib.h>
#include <string.h> //debug

int TAM = 5;
int qtyWitchers = 0;

Witcher* witchers = NULL;

int StartWitchers()
{
    witchers = (Witcher*) malloc(TAM * sizeof(Witcher));

	qtyWitchers = 3;

	witchers[0].code = 1;
	strcpy(witchers[0].especiality, "Roberto") ;
	strcpy(witchers[0].name, "Carlos");
	
	witchers[1].code = 2;
	strcpy(witchers[1].especiality, "Leonardo") ;
	strcpy(witchers[1].name, "Carlos");

	witchers[2].code = 3;
	strcpy(witchers[2].especiality, "Diego") ;
	strcpy(witchers[2].name, "Carlos");

    return 1;		
}

int ShutdownWitchers()
{
	free(witchers);
	return 1;
}

//register
int WitcherRegister(Witcher witcher)
{
    Witcher* witcherAllocTemp = NULL;

    witchers[qtyWitchers] = witcher;
 
     qtyWitchers++;
    
	if(qtyWitchers == TAM)
	{
		TAM += 5;
    	witcherAllocTemp = (Witcher*) realloc(witchers , TAM * sizeof(Witcher));

	    if(witcherAllocTemp == NULL)
	    {
	    	qtyWitchers--;
	    	TAM -= 5;
	        return 0;
		}

	    witchers = witcherAllocTemp;
	}
    
    return 1;
}

int WitcherRemove(int indice)
{
    Witcher* witcherAllocTemp = NULL;	
	
    qtyWitchers--;

    witchers[indice] = witchers[qtyWitchers];

	if(TAM != 5 && qtyWitchers < TAM -5 )
	{
		TAM -= 5;
        witcherAllocTemp = (Witcher*) realloc(witchers , TAM * sizeof(Witcher));	            

        if(witcherAllocTemp == NULL)
        {
            qtyWitchers++;
            TAM += 5;
            return 0;
        }

        witchers = witcherAllocTemp;
	}		
}

//remove
int WitcherRemoveByCode(int code)
{
    int i;

    for (i = 0; i < qtyWitchers; i++)
    {
        if(witchers[i].code == code)
        {
			WitcherRemove(i);

            return 1;
        }
    }    
    
    return 0;
}

int WitcherRemoveByName(char* name)
{
    int i;

    for (i = 0; i < qtyWitchers; i++)
    {
        if(strcmp(witchers[i].name, name)== 0)
        {
        	WitcherRemove(i);
            return 1;
        }
    }    
    return 0;
}

//receive
Witcher GetWitcherByIndice(int indice)
{
    if(indice > qtyWitchers) return;
    
    return witchers[indice];
}

//qty receive
int GetQtyWitcher()
{
    return qtyWitchers;
}

int WitcherUpdate()
{
	
}

