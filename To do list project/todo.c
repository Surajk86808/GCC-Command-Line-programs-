#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "todo.txt"

struct Task
{
    int id;
    char title[100];
    char description[200];
    char dueDate[20];
    char priority[10];
    char status[15]; // Pending / Completed
};

// Function declarations
void menu();
void addTask();
void viewTasks();
void searchTask();
void updateTask();
void deleteTask();
void markCompleted();
void sortTasksByPriority();
void sortTasksByDueDate();
int generateID();
int priorityValue(const char *priority);
void clearScreen();

int main()
{
    menu();
    return 0;
}

// Menu function
void menu()
{
    int choice;
    do
    {
        printf("\n=====================================\n");
        printf("        TO-DO LIST MANAGEMENT         \n");
        printf("=====================================\n");
        printf("1. Add New Task\n");
        printf("2. View All Tasks\n");
        printf("3. Search Task by ID\n");
        printf("4. Update Task\n");
        printf("5. Delete Task\n");
        printf("6. Mark Task as Completed\n");
        printf("7. Sort Tasks by Priority\n");
        printf("8. Sort Tasks by Due Date\n");
        printf("9. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            searchTask();
            break;
        case 4:
            updateTask();
            break;
        case 5:
            deleteTask();
            break;
        case 6:
            markCompleted();
            break;
        case 7:
            sortTasksByPriority();
            break;
        case 8:
            sortTasksByDueDate();
            break;
        case 9:
            printf("Exiting program... Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);
}

// Add Task
void addTask()
{
    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    struct Task task;
    task.id = generateID();

    printf("Enter task title: ");
    fgets(task.title, sizeof(task.title), stdin);
    task.title[strcspn(task.title, "\n")] = '\0';

    printf("Enter description: ");
    fgets(task.description, sizeof(task.description), stdin);
    task.description[strcspn(task.description, "\n")] = '\0';

    printf("Enter due date (DD-MM-YYYY): ");
    fgets(task.dueDate, sizeof(task.dueDate), stdin);
    task.dueDate[strcspn(task.dueDate, "\n")] = '\0';

    printf("Enter priority (High/Medium/Low): ");
    fgets(task.priority, sizeof(task.priority), stdin);
    task.priority[strcspn(task.priority, "\n")] = '\0';

    strcpy(task.status, "Pending");

    fprintf(fp, "%d,%s,%s,%s,%s,%s\n", task.id, task.title, task.description, task.dueDate, task.priority, task.status);
    fclose(fp);

    printf("\n✅ Task added successfully with ID: %d\n", task.id);
}

// View All Tasks
void viewTasks()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp)
    {
        printf("No tasks found.\n");
        return;
    }

    struct Task task;
    printf("\n%-5s %-20s %-10s %-12s %-10s %-12s\n", "ID", "Title", "Priority", "Due Date", "Status", "Description");
    printf("-------------------------------------------------------------------------------\n");

    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &task.id, task.title, task.description, task.dueDate, task.priority, task.status) != EOF)
    {
        printf("%-5d %-20s %-10s %-12s %-10s %-12s\n",
               task.id, task.title, task.priority, task.dueDate, task.status, task.description);
    }
    fclose(fp);
}

// Search Task
void searchTask()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp)
    {
        printf("No data to search.\n");
        return;
    }

    int searchID, found = 0;
    printf("Enter Task ID to search: ");
    scanf("%d", &searchID);
    getchar();

    struct Task task;
    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &task.id, task.title, task.description, task.dueDate, task.priority, task.status) != EOF)
    {
        if (task.id == searchID)
        {
            printf("\nTask Found:\n");
            printf("ID: %d\nTitle: %s\nDescription: %s\nDue Date: %s\nPriority: %s\nStatus: %s\n",
                   task.id, task.title, task.description, task.dueDate, task.priority, task.status);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Task not found!\n");

    fclose(fp);
}

// Update Task
void updateTask()
{
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp)
    {
        printf("Error opening file.\n");
        return;
    }

    int updateID, found = 0;
    struct Task task;

    printf("Enter Task ID to update: ");
    scanf("%d", &updateID);
    getchar();

    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &task.id, task.title, task.description, task.dueDate, task.priority, task.status) != EOF)
    {
        if (task.id == updateID)
        {
            found = 1;
            printf("Enter new title: ");
            fgets(task.title, sizeof(task.title), stdin);
            task.title[strcspn(task.title, "\n")] = '\0';

            printf("Enter new description: ");
            fgets(task.description, sizeof(task.description), stdin);
            task.description[strcspn(task.description, "\n")] = '\0';

            printf("Enter new due date (DD-MM-YYYY): ");
            fgets(task.dueDate, sizeof(task.dueDate), stdin);
            task.dueDate[strcspn(task.dueDate, "\n")] = '\0';

            printf("Enter new priority (High/Medium/Low): ");
            fgets(task.priority, sizeof(task.priority), stdin);
            task.priority[strcspn(task.priority, "\n")] = '\0';
        }
        fprintf(temp, "%d,%s,%s,%s,%s,%s\n", task.id, task.title, task.description, task.dueDate, task.priority, task.status);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("✅ Task updated successfully!\n");
    else
        printf("❌ Task not found!\n");
}

// Delete Task
void deleteTask()
{
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp)
    {
        printf("Error opening file.\n");
        return;
    }

    int deleteID, found = 0;
    struct Task task;

    printf("Enter Task ID to delete: ");
    scanf("%d", &deleteID);

    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &task.id, task.title, task.description, task.dueDate, task.priority, task.status) != EOF)
    {
        if (task.id != deleteID)
        {
            fprintf(temp, "%d,%s,%s,%s,%s,%s\n", task.id, task.title, task.description, task.dueDate, task.priority, task.status);
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
        printf("🗑️ Task deleted successfully!\n");
    else
        printf("❌ Task not found!\n");
}

// Mark Task as Completed
void markCompleted()
{
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp)
    {
        printf("Error opening file.\n");
        return;
    }

    int markID, found = 0;
    struct Task task;

    printf("Enter Task ID to mark as completed: ");
    scanf("%d", &markID);

    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &task.id, task.title, task.description, task.dueDate, task.priority, task.status) != EOF)
    {
        if (task.id == markID)
        {
            strcpy(task.status, "Completed");
            found = 1;
        }
        fprintf(temp, "%d,%s,%s,%s,%s,%s\n", task.id, task.title, task.description, task.dueDate, task.priority, task.status);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("✅ Task marked as completed!\n");
    else
        printf("❌ Task not found!\n");
}

// Generate Unique ID
int generateID()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp)
        return 1;

    struct Task task;
    int maxID = 0;
    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &task.id, task.title, task.description, task.dueDate, task.priority, task.status) != EOF)
    {
        if (task.id > maxID)
            maxID = task.id;
    }
    fclose(fp);
    return maxID + 1;
}

// Helper to compare priority
int priorityValue(const char *priority)
{
    if (strcasecmp(priority, "High") == 0)
        return 3;
    if (strcasecmp(priority, "Medium") == 0)
        return 2;
    if (strcasecmp(priority, "Low") == 0)
        return 1;
    return 0;
}

// Sort by Priority
void sortTasksByPriority()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp)
    {
        printf("No tasks found.\n");
        return;
    }

    struct Task tasks[100];
    int count = 0;

    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &tasks[count].id, tasks[count].title, tasks[count].description,
                  tasks[count].dueDate, tasks[count].priority, tasks[count].status) != EOF)
    {
        count++;
    }
    fclose(fp);

    // Bubble sort by priority value
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (priorityValue(tasks[j].priority) < priorityValue(tasks[j + 1].priority))
            {
                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("\nTasks Sorted by Priority:\n");
    printf("%-5s %-20s %-10s %-12s %-10s %-12s\n", "ID", "Title", "Priority", "Due Date", "Status", "Description");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-5d %-20s %-10s %-12s %-10s %-12s\n",
               tasks[i].id, tasks[i].title, tasks[i].priority, tasks[i].dueDate, tasks[i].status, tasks[i].description);
    }
}

// Sort by Due Date
void sortTasksByDueDate()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp)
    {
        printf("No tasks found.\n");
        return;
    }

    struct Task tasks[100];
    int count = 0;

    while (fscanf(fp, "%d,%99[^,],%199[^,],%19[^,],%9[^,],%14[^\n]\n",
                  &tasks[count].id, tasks[count].title, tasks[count].description,
                  tasks[count].dueDate, tasks[count].priority, tasks[count].status) != EOF)
    {
        count++;
    }
    fclose(fp);

    // Sort lexicographically by due date
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(tasks[j].dueDate, tasks[j + 1].dueDate) > 0)
            {
                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("\nTasks Sorted by Due Date:\n");
    printf("%-5s %-20s %-10s %-12s %-10s %-12s\n", "ID", "Title", "Priority", "Due Date", "Status", "Description");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-5d %-20s %-10s %-12s %-10s %-12s\n",
               tasks[i].id, tasks[i].title, tasks[i].priority, tasks[i].dueDate, tasks[i].status, tasks[i].description);
    }
}
