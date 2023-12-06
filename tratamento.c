#include "tratamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qtyTreatments = 0;

FILE *treatmentFile;

int StartTreatments()
{
	treatmentFile = fopen("TratamentoArq.txt", "r+b");

	if(treatmentFile == NULL)
	{
		treatmentFile = fopen("TratamentoArq.txt", "w+b");	

		if(treatmentFile == NULL)
			return 0;
	}

	fseek(treatmentFile, 0, SEEK_END);
	
	qtyTreatments = ftell(treatmentFile) / sizeof(Treatment);
	
	rewind(treatmentFile);

    return 1;
}

int ShutdownTreatments()
{
	fclose(treatmentFile);
	
	return 1;
}

int TreatmentRegister(Treatment treatment)
{ 
    qtyTreatments++;

	rewind(treatmentFile);

	fseek(treatmentFile, 0, SEEK_END);
	
	int result;		

	result = fwrite(&treatment, sizeof(Treatment), 1 , treatmentFile);
    
    if(!result)
		return 0;
    
    return 1;
}

int TreatmentRemove(Treatment treatment)
{
	FILE* temp;

	temp = fopen("temp.txt", "w+b");

	if(temp == NULL)
	{
		return 0;
	}

    int i;

    Treatment tempTreatment;

	rewind(treatmentFile);

    for(i = 0; i < qtyTreatments; i++)
    {
    	fread(&tempTreatment , sizeof(Treatment) , 1 , treatmentFile );

    	if( tempTreatment.code != treatment.code)
    		fwrite(&tempTreatment, sizeof(Treatment), 1 , temp );
	}

	fclose(treatmentFile);

	remove("TratamentoArq.txt");

	fclose(temp);

	rename("temp.txt", "TratamentoArq.txt");

	treatmentFile = fopen("TratamentoArq.txt", "r+b");

	if(treatmentFile == NULL)
		return 0;

    qtyTreatments--;

    return 1;
}

int TreatmentRemoveByCode(int code)
{
	Treatment temp;
	
	if(!GetTreatmentByCode(code, &temp))
		return 0;

	TreatmentRemove(temp);

    return 1;
}

int GetTreatmentByIndice(int indice , Treatment* treatment)
{
    if(indice >= qtyTreatments) return 0;

	rewind(treatmentFile);
	
	if( indice != 0 )
		fseek(treatmentFile, sizeof(Treatment)*(indice), SEEK_SET);
	
	Treatment temp;
    
	fread(&temp, sizeof(Treatment), 1, treatmentFile);

	*treatment = temp;

	return 1;
}

int GetTreatmentByCode(int code , Treatment* treatment)
{    
	rewind(treatmentFile);

	Treatment temp;

    int i;
    for (i = 0; i < qtyTreatments; i++)
    {	
   		fread(&temp, sizeof(Treatment), 1, treatmentFile);
		
        if(temp.code == code)
        {
			*treatment = temp;
            return 1;
        }
    }    
    
    return 0;
}

int GetQtyTreatment()
{
    return qtyTreatments;
}

int TreatmentModification( Treatment treatment )
{
	rewind(treatmentFile);

	Treatment temp;
	
    int i;
    for (i = 0; i < qtyTreatments; i++)
    {
		fread(&temp, sizeof(Treatment), 1, treatmentFile);

	    if(treatment.code == temp.code)
	    {
	        temp.duration = treatment.duration;
			temp.dosage = treatment.dosage;

			fseek(treatmentFile, sizeof(Treatment)*i, SEEK_SET);
			
			fwrite(&temp, sizeof(Treatment), 1, treatmentFile);

	        return 1;
	    }
	}

    return 0;
}