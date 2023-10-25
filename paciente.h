typedef struct
{
    int code;
    char name[50];
    int age;
    float height;
}Patiant;

int PatiantRegister(Patiant patiant);
int PatiantRemove(int code);
Patiant GetPatiant(int indice);
int GetQtyPatiant();
