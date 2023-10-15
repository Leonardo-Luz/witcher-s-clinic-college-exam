#include "clinica.h"

#define NULL ((void *)0)
#define START 1

int qtyWitchers = 0;
int qtyPotions = 0;
int qtyPatiants = 0;
int qtyTreatments = 0;

Witcher* witchers       = NULL;
Potion* potions         = NULL;
Patiant* patiants       = NULL;
Treatment* treatments   = NULL;


//register
int WitcherRegister(Witcher witcher)
{
    Witcher* witcherAllocTemp = NULL;

    if(qtyWitchers < START)
        witcherAllocTemp = (Witcher*) malloc(START * sizeof(Witcher));
    else
        witcherAllocTemp = (Witcher*) realloc( witchers , (START + qtyWitchers) * sizeof(Witcher));

    if(witcherAllocTemp == NULL)
        return 0;

    witchers = witcherAllocTemp;

    witchers[qtyWitchers] = witcher;
    qtyWitchers++;
    return 1;
}

int PotionRegister(Potion potion)
{
    Potion* potionAllocTemp = NULL;

    if(qtyPotions < START)
        potionAllocTemp = (Potion*) malloc(START * sizeof(Potion));
    else
        potionAllocTemp = (Potion*) realloc( potions , (START + qtyPotions) * sizeof(Potion));

    if(potionAllocTemp == NULL)
        return 0;

    potions = potionAllocTemp;

    potions[qtyPotions] = potion;
    qtyPotions++;
    return 1;
}

int PatiantRegister(Patiant patiant)
{
    Patiant* patiantAllocTemp = NULL;

    if(qtyPatiants < START)
        patiantAllocTemp = (Patiant*) malloc(START * sizeof(Patiant));
    else
        patiantAllocTemp = (Patiant*) realloc( patiants , (START + qtyPatiants) * sizeof(Patiant));

    if(patiantAllocTemp == NULL)
        return 0;

    patiants = patiantAllocTemp;

    patiants[qtyPatiants] = patiant;
    qtyPatiants++;
    return 1;
}

int TreatmentRegister(Treatment treatment)
{
    Treatment* treatmentAllocTemp = NULL;

    if(qtyTreatments < START)
        treatmentAllocTemp = (Treatment*) malloc(START * sizeof(Treatment));
    else
        treatmentAllocTemp = (Treatment*) realloc( treatments , (START + qtyTreatments) * sizeof(Treatment));

    if(treatmentAllocTemp == NULL)
        return 0;

    treatments = treatmentAllocTemp;

    treatments[qtyTreatments] = treatment;
    qtyTreatments++;
    return 1;
}


//remove
int WitcherRemove(int code)
{
    Witcher* witcherAllocTemp = NULL;

    int i;
    for (i = 0; i < qtyWitchers; i++)
    {
        if(witchers[i].code == code)
        {
            qtyWitchers--;

            witcherAllocTemp = (Witcher*) realloc( witchers , (START + qtyWitchers) * sizeof(Witcher));

            if(witcherAllocTemp == NULL)
            {
                qtyWitchers++;
                return 0;
            }

            witchers[i] = witchers[qtyWitchers];
            witchers = witcherAllocTemp;
        }
    }    
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
        }
    }    
}

int PatiantRemove(int code)
{
    Patiant* patiantAllocTemp = NULL;

    int i;
    for (i = 0; i < qtyPatiants; i++)
    {
        if(patiants[i].code == code)
        {
            qtyPatiants--;

            patiantAllocTemp = (Patiant*) realloc( patiants , (START + qtyPatiants) * sizeof(Patiant));

            if(patiantAllocTemp == NULL)
            {
                qtyPatiants++;
                return 0;
            }

            patiants[i] = patiants[qtyPatiants];
            patiants = patiantAllocTemp;            
        }
    }    
}

int TreatmentRemove(int code)
{
    Treatment* treatmentAllocTemp = NULL;

    int i;
    for (i = 0; i < qtyTreatments; i++)
    {
        if(treatments[i].code == code)
        {
            qtyTreatments--;

            treatmentAllocTemp = (Treatment*) realloc( treatments , (START + qtyTreatments) * sizeof(Treatment));

            if(treatmentAllocTemp == NULL)
            {
                qtyTreatments++;
                return 0;
            }

            treatments[i] = treatments[qtyTreatments];
            treatments = treatmentAllocTemp;             
        }
    }    
}


//receive
Witcher GetWitcher(int indice)
{
    if(indice > qtyWitchers) return;
    
    return witchers[indice];
}

Potion GetPotion(int indice)
{
    if(indice > qtyPotions) return;

    return potions[indice];
}
Patiant GetPatiant(int indice)
{
    if(indice > qtyPatiants) return;

    return patiants[indice];
}

Treatment GetTreatment(int indice)
{
    if(indice > qtyTreatments) return;

    return treatments[indice];
}


//qty receive
int GetQtyWitcher()
{
    return qtyWitchers;
}

int GetQtyPotion()
{
    return qtyPotions;
}

int GetQtyPatiant()
{
    return qtyPatiants;
}

int GetQtyTreatment()
{
    return qtyTreatments;
}

int TreatmentModification( Treatment treatment )
{
    int i;
    for (i = 0; i < qtyTreatments; i++)
    if(treatments[i].code == treatment.code)
    {
        treatments[i].duration = treatment.duration;
        treatments[i].dosage = treatment.dosage;

        return 1;
    }

    return 0;
}