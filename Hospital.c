#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100

struct Patient
{
    int ID;
    int age;
    char name[20];
    char disease[50];
};

void addPatient(struct Patient p[], int *count);
void dispPatient(struct Patient p[], int count);
void searchPatient(struct Patient p[], int count);
void delPatient(struct Patient p[], int *count);
void updatePatient(struct Patient p[], int count);

int main()
{
    struct Patient p[MAX_PATIENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n====MENU====\n");
        printf("1.Add a Patient(max 100).\n");
        printf("2.Display all Patients.\n");
        printf("3.Search a Patient by ID.\n");
        printf("4.Delete a Patient.\n");
        printf("5.Update Patient details.\n");
        printf("6.Exit.\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            addPatient(p, &count);
            break;

        case 2:
            dispPatient(p, count);
            break;

        case 3:
            searchPatient(p, count);
            break;

        case 4:
            delPatient(p, &count);
            break;

        case 5:
            updatePatient(p, count);
            break;

        case 6:
            return 0;
            break;

        default:
            printf("Invalid Choice!!");
        }
    } while (choice != 6);
}
void addPatient(struct Patient p[], int *count)
{
    if (*count >= MAX_PATIENTS)
    {
        printf("Maximum limit reached!!");
        return;
    }
    else
    {
        printf("\n====Enter details====\n");
        printf("ID : ");
        scanf("%d", &p[*count].ID);
        getchar();

        printf("Name : ");
        fgets(p[*count].name, sizeof(p[*count].name), stdin);
        p[*count].name[strcspn(p[*count].name, "\n")] = '\0';

        printf("Age : ");
        scanf("%d", &p[*count].age);
        getchar();

        printf("Disease : ");
        fgets(p[*count].disease, sizeof(p[*count].disease), stdin);
        p[*count].disease[strcspn(p[*count].disease, "\n")] = '\0';

        (*count)++;
        printf("Patient added successfully!!");
    }
}

void dispPatient(struct Patient p[], int count)
{
    printf("\n====Patient details====\n");
    for (int i = 0; i < count; i++)
    {

        printf("Patient %d\n", i + 1);
        printf("ID : %d\n", p[i].ID);
        printf("Name : %s\n", p[i].name);
        printf("Age : %d\n", p[i].age);
        printf("Disease : %s\n", p[i].disease);
        printf("\n");
    }
}

void searchPatient(struct Patient p[], int count)
{
    int key;
    int found = 0;
    printf("\n====Search Patient====\n");
    printf("Enter Patient ID to search : ");
    scanf("%d", &key);

    for (int i = 0; i < count; i++)
    {
        if (p[i].ID == key)
        {
            printf("Patient found in the records!!\n");
            printf("ID : %d\n", p[i].ID);
            printf("Name : %s\n", p[i].name);
            printf("Age : %d\n", p[i].age);
            printf("Disease : %s\n", p[i].disease);

            found = 1;

            break;
        }
    }
    if (found == 0)
    {
        printf("Patient not found!!");
    }
}

void delPatient(struct Patient p[], int *count)
{
    int id, found = 0;
    printf("\n====Deleting a Patient====\n");
    printf("Enter patient ID to delete :");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
    {
        if (p[i].ID == id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                p[j] = p[j + 1];
            }
            (*count)--;
            printf("Patient Deleted successfully!!");
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Patient not found!!");
    }
}

void updatePatient(struct Patient p[], int count)
{
    int key, found = 0;
    printf("Enter a patient id to update :");
    scanf("%d", &key);
    getchar();
    printf("\n====Patient Update====\n");
    for (int i = 0; i < count; i++)
    {
        if (p[i].ID == key)
        {
            printf("Enter new name:");
            fgets(p[i].name, sizeof(p[i].name), stdin);
            p[i].name[strcspn(p[i].name, "\n")] = '\0';

            printf("Enter new age :");
            scanf("%d", &p[i].age);
            getchar();

            printf("Enter new disease :");
            fgets(p[i].disease, sizeof(p[i].disease), stdin);
            p[i].disease[strcspn(p[i].disease, "\n")] = '\0';

            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Patient not found!!");
    }
}
