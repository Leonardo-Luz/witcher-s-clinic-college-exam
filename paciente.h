typedef struct
{
    int code;
    char name[50];
    int age;
    float height;
}Patiant;

int StartPatiants();
int ShutdownPatiants();
int PatiantRegister(Patiant patiant);
int PatiantRemoveByCode(int code);
int PatiantRemoveByName(char* name);
int GetPatiantByIndice(int indice , Patiant* patiant);
int GetPatiantByCode(int code , Patiant* patiant);

int GetQtyPatiant();
int PatiantUpdate(Patiant patiant);
