#include "clinica.h"

#define MAX_WITCHER     3
#define MAX_POTION      3
#define MAX_PATIANT     3
#define MAX_TREATMENT   3

int qtyWitchers = 0;
int qtyPotions = 0;
int qtyPatiants = 0;
int qtyTreatments = 0;

Witcher witchers[MAX_WITCHER];
Potion potions[MAX_POTION];
Patiant patiants[MAX_PATIANT];
Treatment treatments[MAX_TREATMENT];


//register
int WitcherRegister(Witcher witcher)
{
    if(qtyWitchers >= MAX_WITCHER) return 0;

    witchers[qtyWitchers] = witcher;
    qtyWitchers++;
    return 1;
}

int PotionRegister(Potion potion)
{
    if(qtyPotions >= MAX_POTION) return 0;

    potions[qtyPotions] = potion;
    qtyPotions++;
    return 1;
}

int PatiantRegister(Patiant patiant)
{
    if(qtyPatiants >= MAX_PATIANT) return 0;

    patiants[qtyPatiants] = patiant;
    qtyPatiants++;
    return 1;
}

int TreatmentRegister(Treatment treatment)
{
    if(qtyTreatments >= MAX_TREATMENT) return 0;

    treatments[qtyTreatments] = treatment;
    qtyTreatments++;
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
            witchers[i] = witchers[qtyWitchers];
        }
    }    
}

int PotionRemove(int code)
{
    int i;
    for (i = 0; i < qtyPotions; i++)
    {
        if(potions[i].code == code)
        {
            qtyPotions--;
            potions[i] = potions[qtyPotions];
        }
    }    
}

int PatiantRemove(int code)
{
    int i;
    for (i = 0; i < qtyPatiants; i++)
    {
        if(patiants[i].code == code)
        {
            qtyPatiants--;
            patiants[i] = patiants[qtyPatiants];
        }
    }    
}

int TreatmentRemove(int code)
{
    int i;
    for (i = 0; i < qtyTreatments; i++)
    {
        if(treatments[i].code == code)
        {
            qtyTreatments--;
            treatments[i] = treatments[qtyTreatments];
        }
    }    
}


//receive
Witcher GetWitcher(int indice)
{
    if(indice >= MAX_WITCHER) return;
    
    return witchers[indice];
}

Potion GetPotion(int indice)
{
    if(indice >= MAX_POTION) return;

    return potions[indice];
}
Patiant GetPatiant(int indice)
{
    if(indice >= MAX_PATIANT) return;

    return patiants[indice];
}

Treatment GetTreatment(int indice)
{
    if(indice >= MAX_TREATMENT) return;

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