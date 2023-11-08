#include "bruxo.h"
#include <stdlib.h>
#include <string.h> //debug

int TAM_WITCHER = 5;
int qtyWitchers = 0;

Witcher* witchers = NULL;

int StartWitchers()
{
	
    witchers = (Witcher*) malloc(TAM_WITCHER * sizeof(Witcher));

	if(witchers == NULL)
	{
		return 0;
	}

//  debug
	qtyWitchers = 3;

	witchers[0].code = 1;
	strcpy(witchers[0].especiality, "Roberto") ;
	strcpy(witchers[0].name, "a");
	
	witchers[1].code = 2;
	strcpy(witchers[1].especiality, "Leonardo") ;
	strcpy(witchers[1].name, "b");

	witchers[2].code = 3;
	strcpy(witchers[2].especiality, "Diego") ;
	strcpy(witchers[2].name, "c");

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
    
	if(qtyWitchers == TAM_WITCHER)
	{
		TAM_WITCHER += 5;
    	witcherAllocTemp = (Witcher*) realloc(witchers , TAM_WITCHER * sizeof(Witcher));

	    if(witcherAllocTemp == NULL)
	    {
	    	qtyWitchers--;
	    	TAM_WITCHER -= 5;
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

	if(TAM_WITCHER != 5 && qtyWitchers < TAM_WITCHER -5 )
	{
		TAM_WITCHER -= 5;
        witcherAllocTemp = (Witcher*) realloc(witchers , TAM_WITCHER * sizeof(Witcher));	            

        if(witcherAllocTemp == NULL)
        {
            qtyWitchers++;
            TAM_WITCHER += 5;
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
int GetWitcherByIndice(int indice , Witcher* witcher)
{
    if(indice > qtyWitchers) return 0;
    
	*witcher = witchers[indice];
	
	return 1;
}

int GetWitcherByCode(int code , Witcher* witcher)
{    
    int i;
    for (i = 0; i < qtyWitchers; i++)
    {
        if(witchers[i].code == code)
        {
            *witcher = witchers[i];
            return 1;
        }
    }    
    
    return 0;
}


//qty receive
int GetQtyWitcher()
{
    return qtyWitchers;
}

int WitcherUpdate(Witcher witcher)
{
	int i;
	
	for(i = 0; i < qtyWitchers; i++)
	if(witchers[i].code == witcher.code)
	{
		strcpy(witchers[i].especiality, witcher.especiality);
		strcpy(witchers[i].name, witcher.name);
	
		return 1;
	}
	
	return 0;
}



