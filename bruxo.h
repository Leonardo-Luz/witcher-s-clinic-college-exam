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
Witcher GetWitcherByIndice(int indice);

int GetQtyWitcher();
int UpdateWitcher();
