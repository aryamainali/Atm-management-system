//  Simple bank mgmt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define clrscr() system("cls")

// Define a structure to hold bank management data
struct bankmgmt
{
    int account_num;
    char username[50];
    int amount;
};
struct bankmgmt A1;

void design();            // Function to display menu
void Aryacreateaccount(); // Function to create a new account
void AryaDeposit();       // Function to deposit amount
void AryaWithdrawl();     // Function to withdraw amount
void AryaBalance();       // Function to display account balance

int main()
{
    int choice;
    clrscr(); // Clear the screen

    char c1, c2, c3, c4;
    int incorrectAttempts = 0;
    do
    {
        printf("Enter your PIN: ");
        c1 = getch(); // Get character without echoing to the screen
        printf("*");
        c2 = getch();
        printf("*");
        c3 = getch();
        printf("*");
        c4 = getch();
        printf("*");

        // Validate PIN
        if (c1 == 'a' && c2 == 'r' && c3 == 'y' && c4 == 'a')
        {
            // If PIN is correct, display menu and process choices
            do
            {
                design();
                printf("\n Enter your choice: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    Aryacreateaccount(); // Create a new account
                    break;
                case 2:
                    AryaDeposit(); // Deposit amount
                    break;
                case 3:
                    AryaWithdrawl(); // Withdraw amount
                    break;
                case 4:
                    AryaBalance(); // Display account balance
                    break;
                case 5:
                    break;
                default:
                    printf("Invalid choice********");
                }
            } while (choice != 5);
        }
        else
        {
            // If PIN is incorrect, inform the user and increment attempts
            printf("\n Incorrect PIN. Access Denied.\n");
            incorrectAttempts++;
            if (incorrectAttempts >= 3)
            {
                // If three incorrect attempts, prompt to put card again
                printf("\n Please put your card again.\n");
                break;
            }
        }
    } while (c1 != 'a' || c2 != 'r' || c3 != 'y' || c4 != 'a');

    return 0;
}

// Function to display the menu
void design()
{
    printf("\n********** ATM Banking Management System ***********");
    printf("\n\t 1. Create Account");
    printf("\n\t 2. Deposit Amount");
    printf("\n\t 3. Withdraw Amount");
    printf("\n\t 4. Check Account Balance");
    printf("\n\t 5. Exit");
    printf("\n ***************************************************");
}

// Function to create a new account
void Aryacreateaccount()
{
    printf("\nEnter account number: ");
    scanf("%d", &A1.account_num);
    printf("Enter your Name: ");
    scanf("%s", A1.username); // Read string directly
    printf("Enter your amount: ");
    scanf("%d", &A1.amount);
}

// Function to deposit amount
void AryaDeposit()
{
    int amt;
    printf("Enter an amount for deposit: ");
    scanf("%d", &amt);
    if (amt < 0)
    {
        printf("\n Invalid amount******");
    }
    else
    {
        // Update account balance with the deposited amount
        A1.amount += amt;
        printf("\nAmount deposited successfully.\n");
    }
}

// Function to withdraw amount
void AryaWithdrawl()
{
    int amt;
    printf("Enter the amount to withdraw: ");
    scanf("%d", &amt);
    if (amt < 0)
    {
        printf("\nInvalid amount\n");
    }
    else if (amt > A1.amount)
    {
        printf("\nInsufficient balance\n");
    }
    else
    {
        A1.amount -= amt;
        printf("\nAmount withdrawn successfully.\n");
    }
}

// Function to display account balance
void AryaBalance()
{
    printf("\n Account number: %d", A1.account_num);
    printf("\n Account name: %s", A1.username);
    printf("\n Account balance: %d", A1.amount);
}
