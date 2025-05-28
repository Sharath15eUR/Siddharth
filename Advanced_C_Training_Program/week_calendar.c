#include <stdio.h>
#include <string.h>

#define MAX_DAYS 7
#define MAX_TASKS 3
#define MAX_TASK_LEN 100

// Structure to represent a day with its name and up to 3 tasks
struct Day {
    char dayName[10];
    char tasks[MAX_TASKS][MAX_TASK_LEN];
    int taskCount;
};

// Function declarations
void inputTasks(struct Day week[]);
void displayTasks(const struct Day week[]);

int main() {
    // Initialize days of the week
    struct Day week[MAX_DAYS] = {
        {"Monday", {}, 0},
        {"Tuesday", {}, 0},
        {"Wednesday", {}, 0},
        {"Thursday", {}, 0},
        {"Friday", {}, 0},
        {"Saturday", {}, 0},
        {"Sunday", {}, 0}
    };

    inputTasks(week);
    displayTasks(week);

    return 0;
}

void inputTasks(struct Day week[]) {
    int dayChoice, i;
    char task[MAX_TASK_LEN];
    char cont;

    do {
        printf("\nSelect a day to add tasks:\n");
        for (i = 0; i < MAX_DAYS; i++) {
            printf("%d. %s\n", i + 1, week[i].dayName);
        }
        printf("Enter day number (1-7): ");
        scanf("%d", &dayChoice);

        if (dayChoice < 1 || dayChoice > MAX_DAYS) {
            printf("Invalid day choice!\n");
            continue;
        }

        struct Day *selectedDay = &week[dayChoice - 1];

        if (selectedDay->taskCount >= MAX_TASKS) {
            printf("Maximum tasks already entered for %s.\n", selectedDay->dayName);
        } else {
            printf("Enter task: ");
            getchar(); // clear newline from buffer
            fgets(task, MAX_TASK_LEN, stdin);
            task[strcspn(task, "\n")] = '\0'; // remove newline

            strcpy(selectedDay->tasks[selectedDay->taskCount], task);
            selectedDay->taskCount++;
        }

        printf("Do you want to add another task? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
}

void displayTasks(const struct Day week[]) {
    printf("\n=== Weekly Task List ===\n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("%s:\n", week[i].dayName);
        if (week[i].taskCount == 0) {
            printf("  No tasks\n");
        } else {
            for (int j = 0; j < week[i].taskCount; j++) {
                printf("  - %s\n", week[i].tasks[j]);
            }
        }
    }
}
