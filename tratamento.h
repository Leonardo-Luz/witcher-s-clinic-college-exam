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
Treatment GetTreatmentByIndice(int indice);
Treatment GetTreatmentByCode(int code);

int GetQtyTreatment();
int TreatmentModification( Treatment treatment );
