#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura pentru întrebări
typedef struct node {
    char question[100];
    char answer1[100];
    char answer2[100];
    char response[100];
    int points;
    struct node *next;
} Node;

// Funcția pentru afișarea unei întrebări și colectarea răspunsului
void printQuestion(Node *head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("Question: %s\n", head->question);
    printf("Answer 1: %s\n", head->answer1);
    printf("Answer 2: %s\n", head->answer2);

    printf("Enter your response: ");
    scanf("%99s", head->response);

    // Verificăm dacă răspunsul este corect
    if (strcmp(head->response, head->answer1) == 0 || strcmp(head->response, head->answer2) == 0) {
        printf("Correct answer!\n");
        head->points = 1;
    } else {
        printf("Incorrect answer.\n");
        head->points = 0;
    }
}

// Funcția pentru încărcarea unui joc nou din fișier
void newGame(Node **head) {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    char line[300];
    while (fgets(line, sizeof(line), file)) {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        // Extragem întrebarea și răspunsurile din linie
        char *question = strtok(line, ";");
        char *answer1 = strtok(NULL, ";");
        char *answer2 = strtok(NULL, ";");

        // Verificăm dacă răspunsurile sunt valide
        if (question && answer1 && answer2) {
            strcpy(newNode->question, question);
            strcpy(newNode->answer1, answer1);
            strcpy(newNode->answer2, answer2);

            newNode->points = 0;
            newNode->next = *head;
            *head = newNode;
        } else {
            free(newNode); // Eliberăm nodul dacă nu este valid
        }
    }

    fclose(file);
}

// Funcția pentru a continua jocul și a calcula scorul
void continueGame(Node *head) {
    Node *current = head;
    int score = 0;
    char playerName[100];

    printf("Introduceti numele jucatorului: ");
    scanf("%99s", playerName);

    // Parcurgem lista de întrebări
    while (current != NULL) {
        printQuestion(current);
        score += current->points;
        current = current->next;
    }

    printf("Final score: %d\n", score);

    // Salvăm scorul în clasament
    FILE *file = fopen("clasament.txt", "a");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    fprintf(file, "%s: %d\n", playerName, score);
    fclose(file);
}

// Funcția pentru afișarea clasamentului
void displayScoreboard() {
    FILE *file = fopen("clasament.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    printf("SCOREBOARD\n");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    Node *head = NULL;

    int choice = 0;
    do {
        printf("-= TRIVIA GAME =-\n");
        printf("Bine ai venit !! \n");
        printf("Selecteaza o optiune: \n");
        printf("1. Creeaza joc nou\n");
        printf("2. Continua joc\n");
        printf("3. Vizualizeaza clasament\n");
        printf("4. Iesire\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Funcție pentru curățarea ecranului în funcție de sistem
        #ifdef _WIN32
            system("cls"); // Windows
        #else
            system("clear"); // Linux/Unix
        #endif

        switch (choice) {
            case 1:
                newGame(&head);  // Creează un joc nou și adaugă întrebări
                continueGame(head);  // Continuă jocul
                break;
            case 2:
                continueGame(head);  // Continuă jocul cu întrebările existente
                break;
            case 3:
                displayScoreboard();  // Afișează clasamentul
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    // Eliberăm memoria alocată pentru lista de întrebări
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
