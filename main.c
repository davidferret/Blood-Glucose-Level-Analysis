#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void readData(int ID[], char name[][30], char type[], int BGL[], int *size);
void sortDataByBGL(int ID[], char name[][30], char type[], int BGL[], int size);
void displayData(int ID[], char name[][30], char type[], int BGL[], int size);
void analyzeBGL(int ID[], char name[][30], char type[], int BGL[], int size);
void exportHighRiskPatients(int ID[], char name[][30], char type[], int BGL[], int size);
void userInputBGLAnalysis();

int main(void) {
    int ID[MAXLINE], BGL[MAXLINE], size;
    char name[MAXLINE][30], type[MAXLINE];
    
    readData(ID, name, type, BGL, &size);
    sortDataByBGL(ID, name, type, BGL, size);
    displayData(ID, name, type, BGL, size);
    analyzeBGL(ID, name, type, BGL, size);
    exportHighRiskPatients(ID, name, type, BGL, size);
    userInputBGLAnalysis();
    
    return 0;
}

void readData(int ID[], char name[][30], char type[], int BGL[], int *size) {
    FILE *fp = fopen("glucose.txt", "r");
    if (fp == NULL) {
        puts("Cannot open the file.");
        return;
    }
    
    *size = 0;
    while (fscanf(fp, "%d %s %c %d\n", &ID[*size], name[*size], &type[*size], &BGL[*size]) != EOF) {
        (*size)++;
    }
    fclose(fp);
}

void sortDataByBGL(int ID[], char name[][30], char type[], int BGL[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (BGL[j] < BGL[j + 1]) {
                int tempID = ID[j];
                ID[j] = ID[j + 1];
                ID[j + 1] = tempID;
                
                char tempName[30];
                strcpy(tempName, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tempName);
                
                char tempType = type[j];
                type[j] = type[j + 1];
                type[j + 1] = tempType;
                
                int tempBGL = BGL[j];
                BGL[j] = BGL[j + 1];
                BGL[j + 1] = tempBGL;
            }
        }
    }
}

void displayData(int ID[], char name[][30], char type[], int BGL[], int size) {
    printf("%-12s%-10s%10s%10s\n", "Patient ID", "Name", "Blood Type", "BGL");
    for (int i = 0; i < size; i++) {
        printf("%-12d%-10s%10c%10d\n", ID[i], name[i], type[i], BGL[i]);
    }
}

void analyzeBGL(int ID[], char name[][30], char type[], int BGL[], int size) {
    int highCount = 0;
    for (int i = 0; i < size; i++) {
        if (BGL[i] >= 180) {
            highCount++;
        }
    }
    printf("Number of patients having BGL >= 180 mg per dL: %d\n", highCount);
    printf("Number of patients having BGL < 180 mg per dL: %d\n", size - highCount);
}

void exportHighRiskPatients(int ID[], char name[][30], char type[], int BGL[], int size) {
    FILE *fp = fopen("high_risk_patients.txt", "w");
    if (!fp) {
        puts("Cannot create the file.");
        return;
    }
    fprintf(fp, "%-12s%-10s%10s%10s\n", "Patient ID", "Name", "Blood Type", "BGL");
    for (int i = 0; i < size; i++) {
        if (BGL[i] >= 180) {
            fprintf(fp, "%-12d%-10s%10c%10d\n", ID[i], name[i], type[i], BGL[i]);
        }
    }
    fclose(fp);
    printf("High-risk patients exported to 'high_risk_patients.txt'.\n");
}

void userInputBGLAnalysis() {
    int userBGL;
    printf("\nEnter a blood glucose level for analysis: ");
    scanf("%d", &userBGL);
    
    if (userBGL < 70) {
        printf("Low blood sugar (hypoglycemia). Seek medical attention.\n");
    } else if (userBGL >= 70 && userBGL < 180) {
        printf("Normal blood sugar level.\n");
    } else {
        printf("High blood sugar (hyperglycemia). Monitor closely.\n");
    }
}
