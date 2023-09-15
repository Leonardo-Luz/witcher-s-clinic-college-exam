typedef struct
{
    int code;
    char name[50];
    char especiality[50];
}Witcher;

typedef struct
{
    int code;
    char name[50];
    char type[20];
}Potion;

typedef struct
{
    int code;
    char name[50];
    int age;
    float height;
}Patiant;

typedef struct
{
    int code;
    int witcherCode;
    int potionCode;
    int patiantCode;
    int duration;
    int dosage;
}Treatment;

int WitcherRegister(Witcher witcher);
int PotionRegister(Potion potion);
int PatiantRegister(Patiant patiant);
int TreatmentRegister(Treatment treatment);

int WitcherRemove(int code);
int PotionRemove(int code);
int PatiantRemove(int code);
int TreatmentRemove(int code);

Witcher GetWitcher(int indice);
Potion GetPotion(int indice);
Patiant GetPatiant(int indice);
Treatment GetTreatment(int indice);

int GetQtyWitcher();
int GetQtyPotion();
int GetQtyPatiant();
int GetQtyTreatment();
