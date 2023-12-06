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
int GetPotionByIndice(int indice, Potion* potion);
int GetPotionByCode(int code, Potion* potion);

int GetQtyPotion();
int PotionUpdate(Potion potion);
