typedef struct
{
    int code;
    char name[50];
    char especiality[50];
}Witcher;

int WitcherRegister(Witcher witcher);
int WitcherRemove(int code);
Witcher GetWitcher(int indice);

int GetQtyWitcher();

