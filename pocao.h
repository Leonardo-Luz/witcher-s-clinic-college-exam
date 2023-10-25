typedef struct
{
    int code;
    char name[50];
    char type[20];
}Potion;

int PotionRegister(Potion potion);
int PotionRemove(int code);
Potion GetPotion(int indice); 
int GetQtyPotion();


