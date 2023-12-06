#include "pocao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qtyPotions = 0;

FILE *potionFile;

int StartPotions()
{
	potionFile = fopen("PocaoArq.txt", "r+b");

	if(potionFile == NULL)
	{
		potionFile = fopen("PocaoArq.txt", "w+b");	

		if(potionFile == NULL)
			return 0;
	}

	fseek(potionFile, 0, SEEK_END);
	
	qtyPotions = ftell(potionFile) / sizeof(Potion);
	
	rewind(potionFile);

    return 1;
}

int ShutdownPotions()
{
	fclose(potionFile);
	
	return 1;
}

int PotionRegister(Potion potion)
{ 
    qtyPotions++;

	rewind(potionFile);

	fseek(potionFile, 0, SEEK_END);
	
	int result;		

	result = fwrite(&potion, sizeof(Potion), 1 , potionFile);
    
    if(!result)
		return 0;
    
    return 1;
}

int PotionRemove(Potion potion)
{
	FILE* temp;

	temp = fopen("temp.txt", "w+b");

	if(temp == NULL)
	{
		return 0;
	}

    int i;

    Potion tempPotion;

	rewind(potionFile);

    for(i = 0; i < qtyPotions; i++)
    {
    	fread(&tempPotion , sizeof(Potion) , 1 , potionFile );

    	if( tempPotion.code != potion.code)
    		fwrite(&tempPotion, sizeof(Potion), 1 , temp );
	}

	fclose(potionFile);

	remove("PocaoArq.txt");

	fclose(temp);

	rename("temp.txt", "PocaoArq.txt");

	potionFile = fopen("PocaoArq.txt", "r+b");

	if(potionFile == NULL)
		return 0;

    qtyPotions--;

    return 1;
}

int PotionRemoveByCode(int code)
{
	Potion temp;
	
	if(!GetPotionByCode(code, &temp))
		return 0;

	PotionRemove(temp);

    return 1;
}

int PotionRemoveByName(char* name)
{
	rewind(potionFile);
	
	Potion temp;
	
    int i;
    for (i = 0; i < qtyPotions; i++)
    {	
   		fread(&temp, sizeof(Potion), 1, potionFile);
		
        if(strcmp(temp.name , name) == 0)
        {
			PotionRemove(temp);
            return 1;
        }
    }

    return 0;
}

int GetPotionByIndice(int indice , Potion* potion)
{
    if(indice >= qtyPotions) return 0;

	rewind(potionFile);
	
	if( indice != 0 )
		fseek(potionFile, sizeof(Potion)*(indice), SEEK_SET);
	
	Potion temp;
    
	fread(&temp, sizeof(Potion), 1, potionFile);

	*potion = temp;

	return 1;
}

int GetPotionByCode(int code , Potion* potion)
{    
	rewind(potionFile);

	Potion temp;

    int i;
    for (i = 0; i < qtyPotions; i++)
    {	
   		fread(&temp, sizeof(Potion), 1, potionFile);
		
        if(temp.code == code)
        {
			*potion = temp;
            return 1;
        }
    }    
    
    return 0;
}

int GetQtyPotion()
{
    return qtyPotions;
}

int PotionUpdate(Potion potion)
{	
	rewind(potionFile);	
	Potion tempPotion;
	
	int i;
	for(i = 0; i < qtyPotions; i++)
	{
		fread(&tempPotion, sizeof(Potion), 1 , potionFile);
				
		if(tempPotion.code == potion.code)
		{
			fseek(potionFile, sizeof(Potion)*i, SEEK_SET);

			fwrite(&potion, sizeof(Potion), 1, potionFile);

			return 1;		
		}
	}
	return 0;
}