#include "bruxo.h"
#include <stdlib.h>
#include <string.h> //debug

int TAM = 5;
int qtyPotions = 0;

Potion* Potions = NULL;

int StartPotions()
{
    Potions = (Potion*) malloc(TAM * sizeof(Potion));

	qtyPotions = 3;

	Potions[0].code = 1;
	strcpy(Potions[0].especiality, "Roberto") ;
	strcpy(Potions[0].name, "Carlos");
	
	Potions[1].code = 2;
	strcpy(Potions[1].especiality, "Leonardo") ;
	strcpy(Potions[1].name, "Carlos");

	Potions[2].code = 3;
	strcpy(Potions[2].especiality, "Diego") ;
	strcpy(Potions[2].name, "Carlos");

    return 1;		
}

int ShutdownPotions()
{
	free(Potions);
	return 1;
}

//register
int PotionRegister(Potion Potion)
{
    Potion* PotionAllocTemp = NULL;

    Potions[qtyPotions] = Potion;
 
     qtyPotions++;
    
	if(qtyPotions == TAM)
	{
		TAM += 5;
    	PotionAllocTemp = (Potion*) realloc(Potions , TAM * sizeof(Potion));

	    if(PotionAllocTemp == NULL)
	    {
	    	qtyPotions--;
	    	TAM -= 5;
	        return 0;
		}

	    Potions = PotionAllocTemp;
	}
    
    return 1;
}

int PotionRemove(int indice)
{
    Potion* PotionAllocTemp = NULL;	
	
    qtyPotions--;

    Potions[indice] = Potions[qtyPotions];

	if(TAM != 5 && qtyPotions < TAM -5 )
	{
		TAM -= 5;
        PotionAllocTemp = (Potion*) realloc(Potions , TAM * sizeof(Potion));	            

        if(PotionAllocTemp == NULL)
        {
            qtyPotions++;
            TAM += 5;
            return 0;
        }

        Potions = PotionAllocTemp;
	}		
}

//remove
int PotionRemoveByCode(int code)
{
    int i;

    for (i = 0; i < qtyPotions; i++)
    {
        if(Potions[i].code == code)
        {
			PotionRemove(i);

            return 1;
        }
    }    
    
    return 0;
}

int PotionRemoveByName(char* name)
{
    int i;

    for (i = 0; i < qtyPotions; i++)
    {
        if(strcmp(Potions[i].name, name)== 0)
        {
        	PotionRemove(i);
            return 1;
        }
    }    
    return 0;
}

//receive
Potion GetPotionByIndice(int indice)
{
    if(indice > qtyPotions) return;
    
    return Potions[indice];
}

//qty receive
int GetQtyPotion()
{
    return qtyPotions;
}

int PotionUpdate()
{
	
}

