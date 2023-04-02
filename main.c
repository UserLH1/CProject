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

    printf("Question: %s\n", head->question);
    printf("Answer 1: %s\n", head->answer1);
    printf("Answer 2: %s\n", head->answer2);

    printf("Enter your response: ");
    scanf("%99s", head->response);

    if (strcmp(head->response, head->answer1) == 0 || strcmp(head->response, head->answer2) == 0) {
        printf("Correct answer!\n");
        head->points = 1;
    } else {
        printf("Incorrect answer.\n");
        head->points = 0;
    }
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
    while (current != NULL) {
        printQuestion(current);
        score += current->points;
        current = current->next;
    }
    printf("Final score: %d\n", score);
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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
