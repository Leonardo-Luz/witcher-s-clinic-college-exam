typedef struct
{
    int code;
    char name[50];
    int age;
    float height;
}Patiant;

int StartPatiant();
int ShutdownPatiants();
int PatiantRegister(Patiant patiant);
int PatiantRemoveByCode(int code);
int PatiantRemoveByName(char* name);
Patiant GetPatiantByIndice(int indice);


int GetQtyPatiant();
int UpdatePatiant();
