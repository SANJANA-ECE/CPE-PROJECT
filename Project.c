#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to accept player details
void acceptDetails(const char *game) {
    FILE *file;
    char name[50], flatNo[20], mobile[15];
    int age;

    printf("Enter player's name: ");
    scanf("%s", name);

    printf("Enter player's age: ");
    scanf("%d", &age);

    printf("Enter player's flat number: ");
    scanf("%s", flatNo);

    printf("Enter player's mobile number: ");
    scanf("%s", mobile);

    // Open file based on the selected game
    file = fopen(game, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write player details to the file
    fprintf(file, "Name: %s, Age: %d, Flat No: %s, Mobile: %s\n", name, age, flatNo, mobile);
    fclose(file);
}

// Function to display entries for a specific game
void displayEntries(const char *game) {
    FILE *file;
    char line[100];

    // Open file based on the selected game
    file = fopen(game, "r");
    if (file == NULL) {
        printf("No entries found for this game yet!\n");
        return;
    }

    printf("Entries for %s:\n", game);

    // Read and display entries
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    int choice;
    char games[][20] = {"Chess.txt", "Carom.txt", "Badminton.txt", "Tennis.txt"};

    while (1) {
        printf("\nOptions:\n");
        printf("1. Player\n2. Organizer\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            int gameChoice;

            printf("\nSelect your game:\n");
            printf("1. Chess\n2. Carom\n3. Badminton\n4. Tennis\nEnter your choice: ");
            scanf("%d", &gameChoice);

            if (gameChoice < 1 || gameChoice > 4) {
                printf("Invalid game choice!\n");
                continue;
            }

            if (choice == 1) {
                acceptDetails(games[gameChoice - 1]);
            } else {
                displayEntries(games[gameChoice - 1]);
            }
        } else {
            printf("Invalid option!\n");
            break;
        }
    }

    return 0;
}
