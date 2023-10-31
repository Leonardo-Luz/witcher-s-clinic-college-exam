typedef struct
{
    int code;
    char name[50];
    char type[20];
}Potion;

int StartPotions();
int ShutdownPotions();
int PotionsRegister(Witcher witcher);
int PotionRemoveByCode(int code);
int PotionRemoveByName(char* name);
Potion GetPotionByIndice(int indice);

int GetQtyPotion();
int UpdatePotion();
