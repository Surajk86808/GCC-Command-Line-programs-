#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.txt"

struct Item
{
    int id;
    char name[50];
    int quantity;
    float price;
};

void addItem();
void viewItems();
void searchItem();
void updateItem();
void deleteItem();
int generateID();

void menu()
{
    int choice;

    do
    {
        printf("\n");
        printf("=====================================\n");
        printf("     INVENTORY MANAGEMENT SYSTEM     \n");
        printf("=====================================\n");
        printf("1. Add Item\n");
        printf("2. View All Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice)
        {
        case 1:
            addItem();
            break;
        case 2:
            viewItems();
            break;
        case 3:
            searchItem();
            break;
        case 4:
            updateItem();
            break;
        case 5:
            deleteItem();
            break;
        case 6:
            printf("Exiting program... Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

void addItem()
{
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    struct Item item;
    item.id = generateID();

    printf("Enter item name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; // remove newline

    printf("Enter quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter price: ");
    scanf("%f", &item.price);

    fprintf(fp, "%d,%s,%d,%.2f\n", item.id, item.name, item.quantity, item.price);
    fclose(fp);

    printf(" Item added successfully with ID: %d\n", item.id);
}

void viewItems()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("No items found. File does not exist yet.\n");
        return;
    }

    struct Item item;
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) != EOF)
    {
        printf("%-5d %-20s %-10d %-10.2f\n", item.id, item.name, item.quantity, item.price);
    }

    fclose(fp);
}

void searchItem()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("No data to search.\n");
        return;
    }

    int searchID, found = 0;
    printf("Enter Item ID to search: ");
    scanf("%d", &searchID);

    struct Item item;
    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) != EOF)
    {
        if (item.id == searchID)
        {
            printf("\nItem found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", item.id, item.name, item.quantity, item.price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf(" Item not found!\n");

    fclose(fp);
}

void updateItem()
{
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    int updateID, found = 0;
    struct Item item;

    printf("Enter Item ID to update: ");
    scanf("%d", &updateID);
    getchar();

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) != EOF)
    {
        if (item.id == updateID)
        {
            found = 1;
            printf("Enter new name: ");
            fgets(item.name, sizeof(item.name), stdin);
            item.name[strcspn(item.name, "\n")] = '\0';

            printf("Enter new quantity: ");
            scanf("%d", &item.quantity);
            printf("Enter new price: ");
            scanf("%f", &item.price);
        }
        fprintf(temp, "%d,%s,%d,%.2f\n", item.id, item.name, item.quantity, item.price);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf(" Item updated successfully!\n");
    else
        printf(" Item not found!\n");
}

void deleteItem()
{
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    int deleteID, found = 0;
    struct Item item;

    printf("Enter Item ID to delete: ");
    scanf("%d", &deleteID);

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) != EOF)
    {
        if (item.id != deleteID)
        {
            fprintf(temp, "%d,%s,%d,%.2f\n", item.id, item.name, item.quantity, item.price);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf(" Item deleted successfully!\n");
    else
        printf(" Item not found!\n");
}

int generateID()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
        return 1;

    struct Item item;
    int maxID = 0;
    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) != EOF)
    {
        if (item.id > maxID)
            maxID = item.id;
    }
    fclose(fp);
    return maxID + 1;
}

int main()
{
    menu();
    return 0;
}
