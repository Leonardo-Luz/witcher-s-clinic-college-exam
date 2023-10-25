typedef struct
{
    int code;
    int witcherCode;
    int potionCode;
    int patiantCode;
    int duration;
    int dosage;
}Treatment;

int TreatmentRegister(Treatment treatment);
int TreatmentRemove(int code);
Treatment GetTreatment(int indice);
int GetQtyTreatment();
int TreatmentModification( Treatment treatment );
