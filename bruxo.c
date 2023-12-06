#include "bruxo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qtyWitchers = 0;

FILE *witcherFile;

int StartWitchers()
{
	witcherFile = fopen("BruxoArq.txt", "r+b");

	if(witcherFile == NULL)
	{
		witcherFile = fopen("BruxoArq.txt", "w+b");	

		if(witcherFile == NULL)
			return 0;
	}

	fseek(witcherFile, 0, SEEK_END);
	
	qtyWitchers = ftell(witcherFile) / sizeof(Witcher);
	
	rewind(witcherFile);

    return 1;
}

int ShutdownWitchers()
{
	fclose(witcherFile);
	
	return 1;
}

int WitcherRegister(Witcher witcher)
{ 
    qtyWitchers++;

	rewind(witcherFile);

	fseek(witcherFile, 0, SEEK_END);
	
	int result;		

	result = fwrite(&witcher, sizeof(Witcher), 1 , witcherFile);
    
    if(!result)
		return 0;
    
    return 1;
}

int WitcherRemove(Witcher witcher)
{
	FILE* temp;

	temp = fopen("temp.txt", "w+b");

	if(temp == NULL)
	{
		return 0;
	}

    int i;

    Witcher tempWitcher;

	rewind(witcherFile);

    for(i = 0; i < qtyWitchers; i++)
    {
    	fread(&tempWitcher , sizeof(Witcher) , 1 , witcherFile );

    	if( tempWitcher.code != witcher.code)
    		fwrite(&tempWitcher, sizeof(Witcher), 1 , temp );
	}

	fclose(witcherFile);

	remove("BruxoArq.txt");

	fclose(temp);

	rename("temp.txt", "BruxoArq.txt");

	witcherFile = fopen("BruxoArq.txt", "r+b");

	if(witcherFile == NULL)
		return 0;

    qtyWitchers--;

    return 1;
}

int WitcherRemoveByCode(int code)
{
	Witcher temp;
	
	if(GetWitcherByCode(code, &temp) == 0)
		return 0;

	WitcherRemove(temp);

    return 1;
}

int WitcherRemoveByName(char* name)
{
	rewind(witcherFile);
	
	Witcher temp;
	
    int i;
    for (i = 0; i < qtyWitchers; i++)
    {	
   		fread(&temp, sizeof(Witcher), 1, witcherFile);
		
        if(strcmp(temp.name , name) == 0)
        {
			WitcherRemove(temp);
            return 1;
        }
    }

    return 0;
}

int GetWitcherByIndice(int indice , Witcher* witcher)
{
    if(indice >= qtyWitchers) return 0;

	rewind(witcherFile);
	
	if( indice != 0 )
		fseek(witcherFile, sizeof(Witcher)*(indice), SEEK_SET);
	
	Witcher temp;
    
	fread(&temp, sizeof(Witcher), 1, witcherFile);

	*witcher = temp;

	return 1;
}

int GetWitcherByCode(int code , Witcher* witcher)
{    
	rewind(witcherFile);

	Witcher temp;

    int i;
    for (i = 0; i < qtyWitchers; i++)
    {	
   		fread(&temp, sizeof(Witcher), 1, witcherFile);
		
        if(temp.code == code)
        {
			*witcher = temp;
            return 1;
        }
    }    
    
    return 0;
}

int GetQtyWitcher()
{
    return qtyWitchers;
}

int WitcherUpdate(Witcher witcher)
{	
	rewind(witcherFile);	
	Witcher tempWitcher;
	
	int i;
	for(i = 0; i < qtyWitchers; i++)
	{
		fread(&tempWitcher, sizeof(Witcher), 1 , witcherFile);
				
		if(tempWitcher.code == witcher.code)
		{
			fseek(witcherFile, sizeof(Witcher)*i, SEEK_SET);

			fwrite(&witcher, sizeof(Witcher), 1, witcherFile);

			return 1;		
		}
	}
	return 0;
}