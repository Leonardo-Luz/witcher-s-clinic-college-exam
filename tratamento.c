#include "tratamento.h"
#include <stdlib.h>
#include <string.h>

int TAM_Treatment = 5;
int qtyTreatments = 0;

Treatment* Treatments = NULL;

int StartTreatments()
{
    Treatments = (Treatment*) malloc(TAM_Treatment * sizeof(Treatment));

    return 1;		
}

int ShutdownTreatments()
{
	free(Treatments);
	return 1;
}

//register
int TreatmentRegister(Treatment treatment)
{
    Treatments[qtyTreatments] = treatment;
 
     qtyTreatments++;
    
	if(qtyTreatments == TAM_Treatment)
	{
	    Treatment* TreatmentAllocTemp = NULL;

		TAM_Treatment += 5;
    	TreatmentAllocTemp = (Treatment*) realloc(Treatments , TAM_Treatment * sizeof(Treatment));

	    if(TreatmentAllocTemp == NULL)
	    {
	    	qtyTreatments--;
	    	TAM_Treatment -= 5;
	        return 0;
		}

	    Treatments = TreatmentAllocTemp;
	}
    
    return 1;
}

int TreatmentRemove(int indice)
{
    Treatment* TreatmentAllocTemp = NULL;	
	
    qtyTreatments--;

    Treatments[indice] = Treatments[qtyTreatments];

	if(TAM_Treatment != 5 && qtyTreatments < TAM_Treatment -5 )
	{
		TAM_Treatment -= 5;
        TreatmentAllocTemp = (Treatment*) realloc(Treatments , TAM_Treatment * sizeof(Treatment));	            

        if(TreatmentAllocTemp == NULL)
        {
            qtyTreatments++;
            TAM_Treatment += 5;
            return 0;
        }

        Treatments = TreatmentAllocTemp;
	}		
}

//remove
int TreatmentRemoveByCode(int code)
{
    int i;

    for (i = 0; i < qtyTreatments; i++)
    {
        if(Treatments[i].code == code)
        {
			TreatmentRemove(i);

            return 1;
        }
    }    
    
    return 0;
}

//receive
Treatment GetTreatmentByIndice(int indice)
{
    if(indice > qtyTreatments) return;
    
    return Treatments[indice];
}

Treatment GetTreatmentByCode(int code)
{
	Treatment treatment;
	treatment.code = -1;
    int i;

    for (i = 0; i < qtyTreatments; i++)
    {
        if(Treatments[i].code == code)
        {
            return Treatments[i];
        }
    }    
    
    return treatment;
}

//qty receive
int GetQtyTreatment()
{
    return qtyTreatments;
}

int TreatmentModification( Treatment treatment )
{
    int i;
    for (i = 0; i < qtyTreatments; i++)
    if(Treatments[i].code == treatment.code)
    {
        Treatments[i].duration = treatment.duration;
        Treatments[i].dosage = treatment.dosage;

        return 1;
    }

    return 0;
}
