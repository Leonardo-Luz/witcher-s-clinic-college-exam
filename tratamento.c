#include "tratamento.h"

#define NULL ((void *)0)
#define START 1

int qtyTreatments = 0;

Treatment* treatments   = NULL;

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
            return 1;
        }
    }    
    return 0;
}


Treatment GetTreatment(int indice)
{
    if(indice > qtyTreatments) return;

    return treatments[indice];
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
