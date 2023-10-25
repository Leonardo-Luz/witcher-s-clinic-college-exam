#include "paciente.h"

#define NULL ((void *)0)
#define START 1

int qtyPatiants = 0;

Patiant* patiants       = NULL;

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
            return 1;
        }
    }    
    return 0;
}


Patiant GetPatiant(int indice)
{
    if(indice > qtyPatiants) return;

    return patiants[indice];
}


int GetQtyPatiant()
{
    return qtyPatiants;
}


