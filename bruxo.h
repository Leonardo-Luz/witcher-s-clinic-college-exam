typedef struct
{
    int code;
    char name[50];
    char especiality[50];
}Witcher;

int StartWitchers();
int ShutdownWitchers();
int WitcherRegister(Witcher witcher);
int WitcherRemoveByCode(int code);
int WitcherRemoveByName(char* name);
int GetWitcherByIndice(int indice, Witcher* witcher);
int GetWitcherByCode(int code, Witcher* witcher);

int GetQtyWitcher();
int WitcherUpdate(Witcher witcher);
