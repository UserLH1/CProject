#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char question[100];
    char answer1[100];
    char answer2[100];
    char response[100];
    int points;
    struct node *next;
} Node;

void printQuestion(Node *head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("Intrebare: %s\n", head->question);
    printf("Raspuns 1: %s\n", head->answer1);
    printf("Raspuns 2: %s\n", head->answer2);

    printf("Introdu raspunsul tau: ");
    scanf("%99s", head->response);
    if(head->response=="k")
        printf("back to main menu");

    if (strcmp(head->response, head->answer1) == 0 || strcmp(head->response, head->answer2) == 0) {
        printf("Raspuns corect!\n");
        head->points = 1;
    } else {
        printf("Raspuns incorect!!.\n");
        head->points = 0;
    }
    printf("\n");
}

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

        char *question = strtok(line, ";");
        char *answer1 = strtok(NULL, ";");
        char *answer2 = strtok(NULL, ";");

        strcpy(newNode->question, question);
        strcpy(newNode->answer1, answer1);
        strcpy(newNode->answer2, answer2);

        newNode->points = 0;
        newNode->next = *head;
        *head = newNode;
    }

    fclose(file);
}

void continueGame(Node *head) {
    Node *current = head;
    int score = 0;
    char playerName[100];

    printf("Introduceti numele jucatorului: ");
    scanf("%99s", playerName);
    printf("\n");
    printf("Bun venit %s !! Pentru a te intoarce la meniul principal apasa tasta k.\n", playerName);
    printf("\n");
    while (current != NULL) {
        printQuestion(current);
        score += current->points;
        current = current->next;
    }

    printf("Scor final: %d\n", score);
    printf("\n");

    FILE *file = fopen("clasament.txt", "a");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    fprintf(file, "%s: %d\n", playerName, score);
    fclose(file);
    system("pause");
     system("cls");
}

void displayScoreboard() {

    FILE *file = fopen("clasament.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    printf("CLASAMENT\n");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

     system("pause");
     system("cls");
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
    printf("Introdu optiunea ta: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice) {
        case 1:
            newGame(&head);
            continueGame(head);
            break;
        case 2:
            continueGame(head);
            break;
        case 3:
            system("cls");
            displayScoreboard();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
            break;
        default:
            printf("Alegere invalida....alege un numar intre 1 si 4 !!\n");
            printf("\n");
            system("pause");
     system("cls");
            scanf("%*[^\n]");
            break;
    }

} while (choice != 4);

return 0;
}
