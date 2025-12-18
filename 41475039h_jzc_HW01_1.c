#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

void makeSecret(char secret[5]) {
    int used[10] = {0};
    int i = 0;
    while (i < 4) {
        int d = rand() % 10;
        if (!used[d]) {
            used[d] = 1;
            secret[i] = '0' + d;
            i++;
        }
    }
    secret[4] = '\0';
}

void countAB(char secret[5], char guess[5], int *A, int *B) {
    int i, j;
    *A = 0;
    *B = 0;
    for (i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) (*A)++;
        else {
            for (j = 0; j < 4; j++) {
                if (i != j && guess[i] == secret[j]) {
                    (*B)++;
                    break;
                }
            }
        }
    }
}

int main()
{
	char secret[5];
    char input[50];
    int A, B;
    int cheatTimes = 0;
    int cheatIndex = 0;
    int i;
    
    srand(time(NULL));
    makeSecret(secret);

    printf("\"Bulls and Cows\"\n");
    printf("Type a 4-digit number to guess, or type 'cheat' to reveal one digit (max 4 times).\n\n");
    
    printf("A (Bulls): A digit is correct and in the correct position.\n");
    printf("B (Cows): A digit is correct but in the wrong position.\n");
    
    while (1) {
        printf("\nYour input: ");
        gets(input);

        if (strcmp(input, "cheat") == 0) {
            if (cheatTimes < 4) {
                printf("Secret digit %d is: %c\n", cheatIndex + 1, secret[cheatIndex]);
                cheatTimes++;
                cheatIndex++;
            } else {
                printf("You have used 'cheat' 4 times already!\n");
            }
            continue;
        }

        if (strlen(input) != 4) {
            printf("Please enter exactly 4 digits!\n");
            continue;
        }

        int valid = 1;
        for (i = 0; i < 4; i++) {   
            if (!isdigit(input[i])) valid = 0;
        }

        if (!valid) {
            printf("Invalid input! Only digits allowed.\n");
            continue;
        }

        countAB(secret, input, &A, &B);
        printf("%dA%dB\n", A, B);

        if (A == 4) {
            printf("Congratulations! The secret digit was %s! \n", secret);
            break;
        }
    }

    return 0;
}
    
    
    
