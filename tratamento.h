typedef struct
{
    int code;
    int witcherCode;
    int potionCode;
    int patiantCode;
    int duration;
    int dosage;
}Treatment;


int StartTreatments();
int ShutdownTreatments();
int TreatmentRegister(Treatment witcher);
int TreatmentRemoveByCode(int code);
int GetTreatmentByIndice(int indice, Treatment* treatment );
int GetTreatmentByCode(int code , Treatment* treatment );

int GetQtyTreatment();
int TreatmentModification( Treatment treatment );
