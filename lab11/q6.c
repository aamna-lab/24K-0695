#include <stdio.h>
#include <stdlib.h>

struct Address {
    char city[50];
    int zip_code;
};

struct Employee {
    char name[50];
    int id;
    float salary;
    struct Address addr;
};
void write_data() {
    FILE *f = fopen("employee_data.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp;
    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", emp.name);
        printf("ID: ");
        scanf("%d", &emp.id);
        printf("Salary: ");
        scanf("%f", &emp.salary);
        printf("City: ");
        scanf(" %[^\n]", emp.addr.city);
        printf("Zip Code: ");
        scanf("%d", &emp.addr.zip_code);

        fwrite(&emp, sizeof(emp), 1, f);
    }
    fclose(f);
    printf("Data saved to file.\n");
}
void read_data() {
    FILE *f = fopen("employee_data.txt", "r");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Employee emp;
    printf("\nEmployee details:\n");
    while (fread(&emp, sizeof(emp), 1, f)) {
        printf("\nName: %s\n", emp.name);
        printf("ID: %d\n", emp.id);
        printf("Salary: %.2f\n", emp.salary);
        printf("City: %s\n", emp.addr.city);
        printf("Zip Code: %d\n", emp.addr.zip_code);
    }
    fclose(f);
}
int main() {
    int ch;
    do {
        printf("\n1. Write data\n");
        printf("2. Read data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                write_data();
                break;
            case 2:
                read_data();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (ch != 3);
}
