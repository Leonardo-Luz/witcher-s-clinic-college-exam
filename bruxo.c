#include "bruxo.h"
#include <stdlib.h>

#define NULL ((void *)0)

int TAM = 5;
int qtyWitchers = 0;

Witcher* witchers = NULL;

int StartWitchers()
{
    Witcher* witcherAllocTemp = NULL;

    if(witchers == NULL)
        witcherAllocTemp = (Witcher*) malloc(TAM * sizeof(Witcher));
	
    if(witcherAllocTemp == NULL)
    {
        return 0;
	}
	
    witchers = witcherAllocTemp;
    free(witcherAllocTemp);
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
	if(qtyWitchers == TAM)
	{
	    Witcher* witcherAllocTemp = NULL;

		TAM += 5;
    	witcherAllocTemp = (Witcher*) realloc( witchers , TAM * sizeof(Witcher) );

	    if(witcherAllocTemp == NULL)
	    {
	        return 0;
		}
		else
		{
		    witchers = witcherAllocTemp;
		    free(witcherAllocTemp);		
		}
	}


    witchers[qtyWitchers] = witcher;
    qtyWitchers++;
    
    return 1;
}

//remove
int WitcherRemove(int code)
{
    int i;
    for (i = 0; i < qtyWitchers; i++)
    {
        if(witchers[i].code == code)
        {
            qtyWitchers--;

        	if(TAM != 5 && TAM - qtyWitchers < TAM * 0.4)
        	{
			    Witcher* witcherAllocTemp = NULL;

				TAM -= 5;
	            witcherAllocTemp = (Witcher*) realloc(witchers , TAM * sizeof(Witcher));
       		
			}


            if(witcherAllocTemp == NULL)
            {
                qtyWitchers++;
                return 0;
            }

            witchers[i] = witchers[qtyWitchers];
            witchers = witcherAllocTemp;
            free(witcherAllocTemp);
            return 1;
        }
    }    
    return 0;
}

//receive
Witcher GetWitcher(int indice)
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

