#include "pocao.h"
#include <stdlib.h>
#include <string.h> //debug

int TAM_POTION = 5;
int qtyPotions = 0;

Potion* Potions = NULL;

int StartPotions()
{
    Potions = (Potion*) malloc(TAM_POTION * sizeof(Potion));

	if(Potions == NULL)
	{
		return 0;
	}

//  debug
	qtyPotions = 3;

	Potions[0].code = 1;
	strcpy(Potions[0].type, "Liquido");
	strcpy(Potions[0].name, "Red bull");
	
	Potions[1].code = 2;
	strcpy(Potions[1].type, "Pilula") ;
	strcpy(Potions[1].name, "Fanta Uva");

	Potions[2].code = 3;
	strcpy(Potions[2].type, "Erva") ;
	strcpy(Potions[2].name, "Astralopitecos Australiano");

    return 1;		
}

int ShutdownPotions()
{
	free(Potions);
	return 1;
}

//register
int PotionRegister(Potion potion)
{
    Potion* PotionAllocTemp = NULL;

    Potions[qtyPotions] = potion;
 
     qtyPotions++;
    
	if(qtyPotions == TAM_POTION)
	{
		TAM_POTION += 5;
    	PotionAllocTemp = (Potion*) realloc(Potions , TAM_POTION * sizeof(Potion));

	    if(PotionAllocTemp == NULL)
	    {
	    	qtyPotions--;
	    	TAM_POTION -= 5;
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


	if(TAM_POTION != 5 && qtyPotions < TAM_POTION -5 )
	{
		TAM_POTION -= 5;
        PotionAllocTemp = (Potion*) realloc(Potions , TAM_POTION * sizeof(Potion));	            

        if(PotionAllocTemp == NULL)
        {
            qtyPotions++;
            TAM_POTION += 5;
            return 0;
        }

        Potions = PotionAllocTemp;
	}		
    Potions[indice] = Potions[qtyPotions];
    return 1;
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
int GetPotionByIndice(int indice , Potion* potion)
{
    if(indice > qtyPotions) return 0;
    
    *potion = Potions[indice];

	return 1;
}

int GetPotionByCode(int code , Potion* potion)
{    
    int i;

    for (i = 0; i < qtyPotions; i++)
    {
        if(Potions[i].code == code)
        {
            *potion = Potions[i];
            return 1;
        }
    }    
    
    return 0;
}

//qty receive
int GetQtyPotion()
{
    return qtyPotions;
}

int PotionUpdate(Potion potion)
{
	int i;
	
	for(i = 0; i < qtyPotions; i++)
	if(Potions[i].code == potion.code)
	{
		strcpy(Potions[i].name, potion.name);
		strcpy(Potions[i].type, potion.type);
	
		return 1;
	}
	
	return 0;	
}

