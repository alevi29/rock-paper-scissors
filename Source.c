#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void delay(int numSeconds) {
	int milliseconds = numSeconds * 500;
	clock_t start = clock();
	while (clock() < start + milliseconds) {
		;
	}
}

int main() {
	srand(time(0));

	int playerScore = 0;
	int computerScore = 0;
	int choice;
	int validInput = 1;
	int playAgain = 1;

	printf("Welcome! Let's play a game of rock, paper, scissors!\n");
	while (validInput == 1) {
		printf("Type '0' for Rock, '1' for Paper, and '2' for Scissors: ");
		scanf("%d", &choice);
		if (choice < 0 || choice > 2) {
			printf("Sorry! I did not understand that.\n");
		}
		else {
			validInput = 0;
			printf("\n");
			delay(1);

			int randomNum = rand();
			switch (randomNum % 3) {
			case 0:
				printf("I choose Rock!");
				break;
			case 1:
				printf("I choose Paper!");
				break;
			case 2:
				printf("I choose Scissors!");
				break;
			}

			printf("\n");
			delay(1);

			switch (choice) {
			case 0:
				printf("You chose Rock!\n\n");
				switch (randomNum % 3) {
				case 0:
					printf("It was a draw!");
					break;
				case 1:
					printf("Looks like I win!");
					computerScore++;
					break;
				case 2:
					printf("Congratulations, you won!");
					playerScore++;
					break;
				}
				break;
			case 1:
				printf("You chose Paper!\n\n");
				switch (randomNum % 3) {
				case 1:
					printf("It was a draw!");
					break;
				case 2:
					printf("Looks like I win!");
					computerScore++;
					break;
				case 0:
					printf("Congratulations, you won!");
					playerScore++;
					break;
				}
				break;
			case 2:
				printf("You chose Scissors!\n\n");
				switch (randomNum % 3) {
				case 2:
					printf("It was a draw!");
					break;
				case 0:
					printf("Looks like I win!");
					computerScore++;
					break;
				case 1:
					printf("Congratulations, you won!");
					playerScore++;
					break;
				}
				break;
			}

			delay(1);
			printf("\n\nCurrent score:\n Me: %d\n You: %d", computerScore, playerScore);
			delay(1);

			printf("\n\nIf you would like to play again, type 0. If you would not like to play again, type anything else: ");
			scanf("%d", &playAgain);
			if (playAgain == 0) {
				printf("\n\nLet's play another round!\n");
				validInput = 1;
			}
			else {
				validInput = 0;
				printf("\nThanks for playing!");
			}

		}
	}

	return 0;
}