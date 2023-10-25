#include "pocao.h"

#define NULL ((void *)0)
#define START 1

int qtyPotions = 0;

Potion* potions = NULL;

int PotionRegister(Potion potion)
{
    Potion* potionAllocTemp = NULL;

    if(potions == NULL)
        potionAllocTemp = (Potion*) malloc(START * sizeof(Potion));
    else
        potionAllocTemp = (Potion*) realloc( potions , (START + qtyPotions) * sizeof(Potion));

    if(potionAllocTemp == NULL)
        return 0;

    potions = potionAllocTemp;

    potions[qtyPotions] = potion;
    qtyPotions++;
    free(potionAllocTemp);
    return 1;
}

int PotionRemove(int code)
{
    Potion* potionAllocTemp = NULL;

    int i;
    for (i = 0; i < qtyPotions; i++)
    {
        if(potions[i].code == code)
        {
            qtyPotions--;

            potionAllocTemp = (Potion*) realloc( potions , (START + qtyPotions) * sizeof(Potion));

            if(potionAllocTemp == NULL)
            {
                qtyPotions++;
                return 0;
            }

            potions[i] = potions[qtyPotions];
            potions = potionAllocTemp;
            free(potionAllocTemp);
            return 1;            
        }
    }    
    return 0;
}

Potion GetPotion(int indice)
{
    if(indice > qtyPotions) return;

    return potions[indice];
}

int GetQtyPotion()
{
    return qtyPotions;
}

