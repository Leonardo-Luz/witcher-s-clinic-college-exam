typedef struct
{
    int code;
    char name[50];
    char type[20];
}Potion;

int StartPotions();
int ShutdownPotions();
int PotionRegister(Potion witcher);
int PotionRemoveByCode(int code);
int PotionRemoveByName(char* name);
Potion GetPotionByIndice(int indice);
Potion GetPotionByCode(int code);

int GetQtyPotion();
int PotionUpdate(Potion potion);
