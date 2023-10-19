#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    srand(time(NULL));
    char q = 'y';
    int balance = 10;

    while ('q' != q && 'Q' != q) {
        char topUpYourBalance = 'n';
        
        if (balance < 1) {
            printf("Your balance is empty. Would you like to top it up? (y/n) [n]: ");
            scanf(" %c", &topUpYourBalance);
            
            if ('y' == topUpYourBalance || 'Y' == topUpYourBalance) {
                int amountToTopUp;
                printf("Enter the amount to top up: ");
                
                if (scanf("%d", &amountToTopUp) == 1) {
                    if (amountToTopUp > 0) {
                        balance += amountToTopUp;
                        printf("Balance topped up by %d. New balance: %d\n", amountToTopUp, balance);
                    } else {
                        printf("Invalid amount. Please enter a positive number to top up your balance.\n");
                    }
                } else {
                    printf("Invalid input. Please enter a valid number to top up your balance.\n");
                    fflush(stdin);
                }
            }else{
				printf("Program closed");
				exit(0);
			}
        }
        
       
        printf("---- Game begin ----\n");
        printf("Your balance: %d\n", balance);
        int attempt = 1;
        int min = 0;
        int max = 9;
        int myNumber = min + rand() % (max - min + 1);
        do {
            printf("The number is from 0 to 9. Try to guess:\n");
            printf("Attempt %d: ", attempt);
            int userNumber=0;
            
             if (scanf(" %d", &userNumber) != 1) {
                printf("Invalid input. Please enter a number.\n");
                fflush(stdin); // Очистить буфер ввода
                continue;
            }
            if (myNumber == userNumber) {
                printf("You won. Hooray!\n");
                balance++;
                break;
            } else {
                if (attempt > 2) {
                    printf("You lose, my number was: %d\n", myNumber);
                    balance--;
                    break;
                } else {
                    printf("Try again");
                    
                    if (myNumber > userNumber) {
                        printf(" (my number is higher)\n");
                    } else {
                        printf(" (my number is less)\n");
                    }
                }
            }
            attempt++;
        } while (1);
        
        printf("For exit press 'q' or 'Q', press any other key to continue: ");
        scanf(" %c", &q);
    }

    printf("\n---- End ----\n");
    return 0;
}
